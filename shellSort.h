#ifndef SHELL_SORT_H
#define SHELL_SORT_H

/*
 * Shell Sort:
 * Algoritma ini adalah versi pengembangan Insertion Sort yang membandingkan elemen dengan jarak tertentu,
 * mengurangi jarak secara bertahap hingga menjadi 1.
 */
void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

#endif
