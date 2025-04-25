#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdlib.h>
#include <string.h>

void merge_sort_str(char **arr, int n);

// fungsi untuk mengurutkan integer
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Untuk string
void merge_sort_str(char **arr, int n) {
    if (n <= 1) return;

    int mid = n / 2;
    char **left = malloc(mid * sizeof(char *));
    char **right = malloc((n - mid) * sizeof(char *));

    for (int i = 0; i < mid; i++) left[i] = arr[i];
    for (int i = mid; i < n; i++) right[i - mid] = arr[i];

    merge_sort_str(left, mid);
    merge_sort_str(right, n - mid);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < (n - mid)) {
        if (strcmp(left[i], right[j]) <= 0) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while (i < mid) arr[k++] = left[i++];
    while (j < n - mid) arr[k++] = right[j++];

    free(left);
    free(right);
}

#endif
