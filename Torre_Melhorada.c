#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // API do Windows para medição de alta precisão em us
#include <time.h>    // Para a semente do gerador de números aleatórios

/* FUNÇÃO MERGE (Intercalação):
   Recebe duas metades já ordenadas e as junta
   em uma sequência única também ordenada. 
   Complexidade desta parte: O(n).
*/
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; 
    int n2 = r - m;     

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

/* FUNÇÃO MERGESORT:
   Estratégia Dividir para Conquistar.
   Complexidade Total: O(n log n).
*/
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m);     
        mergeSort(arr, m + 1, r); 

        merge(arr, l, m, r);      
    }
}

int main() {
    int n;
    
    // Estruturas do Windows para medição de tempo de alta resolução
    LARGE_INTEGER frequencia; 
    LARGE_INTEGER t1, t2;     
    double tempo_micro;

    srand(time(NULL)); 

    // Obtém a frequência do contador (ticks por segundo)
    QueryPerformanceFrequency(&frequencia);

    printf("Digite o tamanho do vetor para ordenacao: ");
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro: Memoria insuficiente.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    // --- INÍCIO DA MEDIÇÃO ---
    QueryPerformanceCounter(&t1);
    
    mergeSort(arr, 0, n - 1); 
    
    QueryPerformanceCounter(&t2);
    // --- FIM DA MEDIÇÃO ---
    
    // Cálculo: (Ticks * 1.000.000) / Frequência = microssegundos (us)
    tempo_micro = (double)(t2.QuadPart - t1.QuadPart) * 1000000.0 / frequencia.QuadPart;

    printf("\n--- RESULTADO FINAL (MERGE SORT) ---\n");
    printf("Entrada: %d elementos\n", n);
    printf("Tempo: %.2f us\n", tempo_micro);
    
    // Exibição com 10 casas decimais para capturar a diferença em microssegundos
    printf("Tempo convertido: %.10f s\n", tempo_micro / 1000000.0);

    free(arr);
    
    return 0;
}