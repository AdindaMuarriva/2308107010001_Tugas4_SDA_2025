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

// Fungsi untuk membaca data integer dari file
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

// Fungsi mengukur dan menjalankan sorting
void test_sorting(const char *name, void (*sort_fn)(int *, int), int *data, int n) {
    int *copy = malloc(n * sizeof(int));
    memcpy(copy, data, n * sizeof(int));

    clock_t start = clock();
    sort_fn(copy, n);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s untuk %d data: %.4f detik\n", name, n, duration);

    free(copy);
}

// Untuk merge sort dan quick sort (karena argumen beda)
void test_merge_sort(const char *name, void (*sort_fn)(int *, int, int), int *data, int n) {
    int *copy = malloc(n * sizeof(int));
    memcpy(copy, data, n * sizeof(int));

    clock_t start = clock();
    sort_fn(copy, 0, n - 1);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s untuk %d data: %.4f detik\n", name, n, duration);

    free(copy);
}

int main() {
    const char *filename = "data_angka.txt";
    int sizes[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};

    // Generate data sekali saja
    generate_random_numbers(filename, 2000000, 2000000);

    for (int i = 0; i < sizeof(sizes)/sizeof(int); i++) {
        int n = sizes[i];
        int *data = malloc(n * sizeof(int));
        load_integers(filename, data, n);

        printf("\n=== UJI DATA %d ===\n", n);

        test_sorting("Bubble Sort", bubble_sort, data, n);
        test_sorting("Selection Sort", selection_sort, data, n);
        test_sorting("Insertion Sort", insertion_sort, data, n);
        test_merge_sort("Merge Sort", merge_sort, data, n);
        test_merge_sort("Quick Sort", quick_sort, data, n);
        test_sorting("Shell Sort", shell_sort, data, n);

        free(data);
    }

    return 0;
}
