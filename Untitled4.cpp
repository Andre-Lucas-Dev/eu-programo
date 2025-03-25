#include <stdio.h>

// Fun��o para implementar o Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;

    // Passa por todos os elementos do array
    for(i = 0; i < n - 1; i++) {
        // Encontra o �ndice do menor elemento na parte n�o ordenada
        minIdx = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Troca o elemento encontrado com o primeiro elemento da parte n�o ordenada
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

// Fun��o para imprimir o array
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    // Chama a fun��o selectionSort
    selectionSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

