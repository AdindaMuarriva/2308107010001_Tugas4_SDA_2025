#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <string.h>

void quick_sort_str(char **arr, int n);

// Fungsi partition untuk quick sort integer
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }

    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return i + 1;
}

// Fungsi quick sort untuk integer
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Untuk string
void quick_sort_str_helper(char **arr, int low, int high) {
    if (low < high) {
        char *pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (strcmp(arr[j], pivot) <= 0) {
                i++;
                char *temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        char *temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;

        int pi = i + 1;
        quick_sort_str_helper(arr, low, pi - 1);
        quick_sort_str_helper(arr, pi + 1, high);
    }
}

// Fungsi quick sort utama untuk array string
void quick_sort_str(char **arr, int n) {
    quick_sort_str_helper(arr, 0, n - 1);
}

#endif
