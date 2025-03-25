#include <stdio.h>

// Fun��o para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o para particionar o array e encontrar o �ndice do piv�
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Piv� � o �ltimo elemento
    int i = (low - 1);  // �ndice do menor elemento

    // Organiza o array em torno do piv�
    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor que o piv�
        if (arr[j] < pivot) {
            i++;    // Incrementa o �ndice do menor elemento
            swap(&arr[i], &arr[j]);  // Troca os elementos
        }
    }
    // Coloca o piv� na posi��o correta
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fun��o principal de ordena��o do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontra o �ndice do piv�
        int pi = partition(arr, low, high);

        // Ordena recursivamente as duas metades
        quickSort(arr, low, pi - 1);  // Ordena a parte esquerda
        quickSort(arr, pi + 1, high);  // Ordena a parte direita
    }
}

// Fun��o para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    // Chama a fun��o quickSort
    quickSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

