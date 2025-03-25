#include <stdio.h>

// Fun��o para implementar o Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;

    // Passa por todos os elementos do array
    for(i = 0; i < n-1; i++) {
        // A cada itera��o, o maior elemento "borbulha" at� o final
        for(j = 0; j < n-i-1; j++) {
            // Troca se o elemento encontrado for maior que o pr�ximo
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    // Chama a fun��o bubbleSort
    bubbleSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

