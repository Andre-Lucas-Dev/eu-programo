#include <stdio.h>

// Fun��o para implementar o Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;

    // Passa por todos os elementos a partir do segundo
    for(i = 1; i < n; i++) {
        key = arr[i]; // O elemento a ser inserido
        j = i - 1;

        // Move os elementos que s�o maiores que a chave para uma posi��o � frente
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Coloca a chave na posi��o correta
        arr[j + 1] = key;
    }
}

// Fun��o para imprimir o array
void printArray(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    // Chama a fun��o insertionSort
    insertionSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

