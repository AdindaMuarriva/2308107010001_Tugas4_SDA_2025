#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

/*
 * Bubble Sort:
 * Algoritma ini membandingkan dua elemen bersebelahan dan menukarnya jika urutannya salah.
 * Proses ini diulang hingga tidak ada lagi pertukaran yang dilakukan.
 */
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

#endif
