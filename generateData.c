#include "generateData.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//  Menghasilkan angka acak dan menyimpannya ke file
//  serta mencatat waktu eksekusinya.
void generate_random_numbers(const char *filename, int count, int max_value) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("File tidak dapat dibuka");
        return;
    }

    clock_t start = clock();
    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        int num = rand() % max_value;
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Waktu generate angka: %.2f detik\n", time_taken);
}


 // Membuat satu kata acak
 
void random_word(char *word, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        word[i] = charset[key];
    }
    word[length] = '\0';
}


//  Menghasilkan kata acak dan menyimpannya ke file
//  serta mencatat waktu eksekusinya.
  
void generate_random_words(const char *filename, int count, int max_word_length) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("File tidak dapat dibuka");
        return;
    }

    clock_t start = clock();
    srand(time(NULL));

    char word[100];
    for (int i = 0; i < count; i++) {
        int length = (rand() % (max_word_length - 3)) + 3;
        random_word(word, length);
        fprintf(fp, "%s\n", word);
    }

    fclose(fp);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Waktu generate kata: %.2f detik\n", time_taken);
}
