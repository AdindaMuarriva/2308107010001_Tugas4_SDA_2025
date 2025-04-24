#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

/*
 * Selection Sort:
 * Algoritma ini mencari elemen terkecil dari array dan menukarnya dengan elemen pertama,
 * lalu mengulang untuk bagian array yang belum terurut.
 */
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

#endif
