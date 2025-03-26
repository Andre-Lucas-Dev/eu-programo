#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para implementar o Bubble Sort
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Função para implementar o Insertion Sort
void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos que são maiores que a chave para a posição seguinte
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para imprimir o array
void printArray(float arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%.1f", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Função para medir o tempo de execução de um algoritmo
double measureTime(void (*sortFunc)(float[], int), float arr[], int n) {
    clock_t start, end;
    start = clock();
    sortFunc(arr, n);
    end = clock();
    return ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC; // Tempo em milissegundos
}

int main() {
    // Exemplo de diferentes tamanhos de entrada (10, 100 e 1000)
    int sizes[] = {10, 100, 1000};
    int i, j;

    // Para cada tamanho de entrada
    for(i = 0; i < 3; i++) {
        int n = sizes[i];
        float arr[n];

        // Preencher o array com valores aleatórios entre 0 e 10
        for(j = 0; j < n; j++) {
            arr[j] = (float)(rand() % 101) / 10.0;  // Gera números decimais entre 0.0 e 10.0
        }

        printf("\nTamanho do array: %d\n", n);

        // Medir e exibir o tempo de execução do Bubble Sort
        float arrBubble[n];
        for(j = 0; j < n; j++) arrBubble[j] = arr[j];  // Copiar o array
        double bubbleTime = measureTime(bubbleSort, arrBubble, n);
        printf("Notas ordenadas (Bubble Sort): ");
        printArray(arrBubble, n);
        printf("Tempo de execução (Bubble Sort): %.2f ms\n", bubbleTime);

        // Medir e exibir o tempo de execução do Insertion Sort
        float arrInsertion[n];
        for(j = 0; j < n; j++) arrInsertion[j] = arr[j];  // Copiar o array
        double insertionTime = measureTime(insertionSort, arrInsertion, n);
        printf("Notas ordenadas (Insertion Sort): ");
        printArray(arrInsertion, n);
        printf("Tempo de execução (Insertion Sort): %.2f ms\n", insertionTime);
    }

    return 0;
}

