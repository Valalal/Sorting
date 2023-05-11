#define _CRT_SECURE_NO_WARNINGS f djn

#include <stdio.h>
#include <stdlib.h>

void Input(int* count, int** array);

void Output(int count, int array[]);

void Merge_sort(int* array, int l, int r);

int main(void) {
    int count;
    int* array;
    while (1) {
        Input(&count, &array);
        Output(count, array);
        Merge_sort(array, 0, count - 1);
        Output(count, array);
        free(array);
    }
}


void Input(int* count, int** arr) {
    printf("Number of elements:\n");
    if (scanf("%d", count) == 0) {
        puts("Error");
        exit(1);
    }
    *arr = (int*)malloc((*count) * sizeof(int));
    if (*arr) {
        for (int i = 0; i < *count; i++) {
            if (arr)
                (*arr)[i] = rand() % 20;
            else
                exit(-2);
        }
        printf(".........\n");
    }
}
void Output(int count, int array[]) {
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n...\n");
}

void Merge_sort(int* array, int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    Merge_sort(array, l, mid);
    Merge_sort(array, mid + 1, r);
    int i = l;
    int j = mid + 1;
    int* buf = (int*)malloc((r - l + 1) * sizeof(int));
    for (int step = 0; step < r - l + 1; step++) {
        if ((j > r) || ((i <= mid) && (array[i] < array[j]))) {
            buf[step] = array[i];
            i++;
        }
        else {
            buf[step] = array[j];
            j++;
        }
    }
    for (int k = 0; k < r - l + 1; k++) {
        array[l + k] = buf[k];
    }
}