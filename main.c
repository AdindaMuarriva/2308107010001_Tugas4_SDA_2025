#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>

#include "generateData.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "shellSort.h"

void bubble_sort_str(char **arr, int n);
void selection_sort_str(char **arr, int n);
void insertion_sort_str(char **arr, int n);
void merge_sort_str(char **arr, int n);
void quick_sort_str(char **arr, int n);
void selection_sort_str(char **arr, int n);

// melakukan load data angka dari file
void load_integers(const char *filename, int *arr, int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file angka");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
}

// melakukan load data kata dari file
void load_words(const char *filename, char **arr, int n, int max_len) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file kata");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = malloc((max_len + 1) * sizeof(char));
        fscanf(fp, "%s", arr[i]);
    }

    fclose(fp);
}

// Mengukur memory usage 
size_t get_memory_usage_int(int n) {
    return n * sizeof(int);
}

size_t get_memory_usage_str(int n, int max_len) {
    return n * (max_len + 1) * sizeof(char);
}

// pengurutan dan menghitung waktu untuk angka/int
void test_sorting(const char *name, void (*sort_fn)(int *, int), int *data, int n) {
    int *copy = malloc(n * sizeof(int));
    memcpy(copy, data, n * sizeof(int));

    clock_t start = clock();
    sort_fn(copy, n);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    size_t mem = get_memory_usage_int(n);

    printf("%s untuk %d data: %.4f detik | Memori: %.2f KB\n", name, n, duration, mem / 1024.0);

    free(copy);
}

// pengurutan dan menghitung waktu untuk merge/quick sort
void test_merge_sort(const char *name, void (*sort_fn)(int *, int, int), int *data, int n) {
    int *copy = malloc(n * sizeof(int));
    memcpy(copy, data, n * sizeof(int));

    clock_t start = clock();
    sort_fn(copy, 0, n - 1);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    size_t mem = get_memory_usage_int(n);

    printf("%s untuk %d data: %.4f detik | Memori: %.2f KB\n", name, n, duration, mem / 1024.0);

    free(copy);
}

// pengurutan dan menghitung waktu untuk string
void test_sorting_str(const char *name, void (*sort_fn)(char **, int), char **data, int n, int max_len) {
    char **copy = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        copy[i] = malloc((max_len + 1) * sizeof(char));
        strcpy(copy[i], data[i]);
    }

    clock_t start = clock();
    sort_fn(copy, n);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    size_t mem = get_memory_usage_str(n, max_len);

    printf("%s untuk %d kata: %.4f detik | Memori: %.2f KB\n", name, n, duration, mem / 1024.0);

    for (int i = 0; i < n; i++) free(copy[i]);
    free(copy);
}

int main() {
    const char *num_file = "data_angka.txt";
    const char *word_file = "data_kata.txt";
    int sizes[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};
    int max_word_len = 20;

    // Generate sekali saja
    generate_random_numbers(num_file, 2000000, 2000000);
    generate_random_words(word_file, 2000000, max_word_len);

    for (int i = 0; i < sizeof(sizes)/sizeof(int); i++) {
        int n = sizes[i];
        int *data_num = malloc(n * sizeof(int));
        load_integers(num_file, data_num, n);

        printf("\n=== UJI DATA ANGKA (%d) ===\n", n);
        test_sorting("Bubble Sort", bubble_sort, data_num, n);
        test_sorting("Selection Sort", selection_sort, data_num, n);
        test_sorting("Insertion Sort", insertion_sort, data_num, n);
        test_merge_sort("Merge Sort", merge_sort, data_num, n);
        test_merge_sort("Quick Sort", quick_sort, data_num, n);
        test_sorting("Shell Sort", shell_sort, data_num, n);
        free(data_num);

        // Data kata
        char **data_str = malloc(n * sizeof(char *));
        load_words(word_file, data_str, n, max_word_len);

        printf("\n=== UJI DATA KATA (%d) ===\n", n);
        test_sorting_str("Bubble Sort", bubble_sort_str, data_str, n, max_word_len);
        test_sorting_str("Selection Sort", selection_sort_str, data_str, n, max_word_len);
        test_sorting_str("Insertion Sort", insertion_sort_str, data_str, n, max_word_len);
        test_sorting_str("Merge Sort", merge_sort_str, data_str, n, max_word_len);
        test_sorting_str("Quick Sort", quick_sort_str, data_str, n, max_word_len);
        test_sorting_str("Shell Sort", shell_sort_str, data_str, n, max_word_len);

        for (int j = 0; j < n; j++) free(data_str[j]);
        free(data_str);
    }

    return 0;
}
