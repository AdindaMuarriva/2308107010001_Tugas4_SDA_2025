#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

/*
 * Insertion Sort:
 * Algoritma ini membangun array terurut satu per satu,
 * dengan cara menyisipkan elemen ke posisi yang tepat.
 */
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

#endif
