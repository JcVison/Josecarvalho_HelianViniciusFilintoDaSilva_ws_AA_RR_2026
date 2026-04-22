#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // API do Windows para medição de alta precisão
#include <time.h>    // Para gerar sementes aleatórias

// --- FUNÇÃO MERGE (Intercalação) ---
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
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// --- FUNÇÃO MERGESORT ---
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- FUNÇÃO PARA EXIBIÇÃO FORMATADA ---
void exibirTempoBonito(double micro) {
    printf("\n--- RESULTADO FINAL ---\n");
    
    if (micro < 1000.0) {
        printf("Tempo Medio: %.2f microssegundos\n", micro);
    } else if (micro < 1000000.0) {
        printf("Tempo Medio: %.4f milissegundos (ms)\n", micro / 1000.0);
    } else {
        printf("Tempo Medio: %.2f segundos (s)\n", micro / 1000000.0);
    }
    
    printf("Valor bruto: %.10f s\n", micro / 1000000.0);
}

int main() {
    int n, repeticoes;
    LARGE_INTEGER frequencia, t1, t2; 
    double tempo_total = 0;

    srand(time(NULL)); 
    QueryPerformanceFrequency(&frequencia);

    printf("--- MODO DE TESTES AUTOMATICOS (MERGE SORT) ---\n");
    printf("Digite o tamanho do vetor para ordenacao: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Quantas vezes deseja repetir o teste para calcular a media? ");
    if (scanf("%d", &repeticoes) != 1) return 1;

    // ALOCAÇÃO DO VETOR DE HISTÓRICO PARA ARMAZENAR TEMPOS INDIVIDUAIS
    double *historico = (double *)malloc(repeticoes * sizeof(double));
    if (historico == NULL) {
        printf("Erro ao alocar memoria para o historico.\n");
        return 1;
    }

    printf("\nProcessando testes silenciosamente... Aguarde.\n");

    for (int i = 0; i < repeticoes; i++) {
        // Alocação e preenchimento fora da medição
        int *arr = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 10000;
        }

        // --- INÍCIO DA MEDIÇÃO PURA ---
        QueryPerformanceCounter(&t1);
        mergeSort(arr, 0, n - 1);
        QueryPerformanceCounter(&t2);
        // --- FIM DA MEDIÇÃO ---

        double tempo_micro = (double)(t2.QuadPart - t1.QuadPart) * 1000000.0 / frequencia.QuadPart;
        
        // SALVA NO HISTÓRICO (Operação de memória ultra rápida)
        historico[i] = tempo_micro;
        tempo_total += tempo_micro;
        
        free(arr); 

        // Feedback visual discreto
        if (repeticoes >= 10 && (i + 1) % (repeticoes / 10) == 0) printf(".");
    }

    // EXIBIÇÃO DO LOG INDIVIDUAL (Fora do laço de medição)
    printf("\n\n--- LOG DE EXECUCOES INDIVIDUAIS ---");
    for (int i = 0; i < repeticoes; i++) {
        printf("\nTeste %d: %.2f us | Bruto: %.10f s", i + 1, historico[i], historico[i] / 1000000.0);
    }

    double media = tempo_total / repeticoes;
    exibirTempoBonito(media);

    free(historico);
    return 0;
}