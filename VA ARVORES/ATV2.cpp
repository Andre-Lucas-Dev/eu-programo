#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para representar um produto
typedef struct {
    char nome[100];
    float preco;
} Produto;

// Função para implementar o Bubble Sort
void bubbleSort(Produto arr[], int n) {
    int i, j;
    Produto temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j].preco > arr[j+1].preco) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Função para implementar o Selection Sort
void selectionSort(Produto arr[], int n) {
    int i, j, minIdx;
    Produto temp;
    for(i = 0; i < n-1; i++) {
        minIdx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j].preco < arr[minIdx].preco) {
                minIdx = j;
            }
        }
        if(minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

// Função para imprimir a lista de produtos no formato esperado
void printArray(Produto arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("(\"%s\", %.2f)", arr[i].nome, arr[i].preco);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Função para medir o tempo de execução de um algoritmo
double measureTime(void (*sortFunc)(Produto[], int), Produto arr[], int n) {
    clock_t start, end;
    start = clock();
    sortFunc(arr, n);
    end = clock();
    return ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC; // Tempo em milissegundos
}

int main() {
    // Lista de produtos
    Produto produtos[] = {
        {"Teclado", 120.50}, 
        {"Mouse", 80.00}, 
        {"Monitor", 550.00}, 
        {"Fone", 200.00}, 
        {"Cadeira", 350.00},
        {"Mousepad", 25.00}, 
        {"Impressora", 450.00}, 
        {"Caixa de Som", 150.00}, 
        {"Headset", 180.00},
        {"Webcam", 300.00},
        {"Mochila", 90.00},
        {"Placa de Vídeo", 1200.00},
        {"Fonte", 250.00},
        {"Teclado Mecânico", 400.00},
        {"Smarphone", 999.99}
    };
    
    int n = sizeof(produtos) / sizeof(produtos[0]);

    // Medir e exibir o tempo de execução do Selection Sort
    Produto arrSelection[n];
    for(int i = 0; i < n; i++) arrSelection[i] = produtos[i];  // Copiar o array
    double selectionTime = measureTime(selectionSort, arrSelection, n);
    printf("Produtos ordenados (Selection Sort): ");
    printArray(arrSelection, n);
    printf("Tempo de execução (Selection Sort): %.2f ms\n\n", selectionTime);

    // Medir e exibir o tempo de execução do Bubble Sort
    Produto arrBubble[n];
    for(int i = 0; i < n; i++) arrBubble[i] = produtos[i];  // Copiar o array
    double bubbleTime = measureTime(bubbleSort, arrBubble, n);
    printf("Produtos ordenados (Bubble Sort): ");
    printArray(arrBubble, n);
    printf("Tempo de execução (Bubble Sort): %.2f ms\n", bubbleTime);

    return 0;
}

