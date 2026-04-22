#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 

/* FUNÇÃO RECURSIVA TORRE DE HANOI */
void torreHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) return;
    torreHanoi(n - 1, origem, auxiliar, destino);
    torreHanoi(n - 1, auxiliar, destino, origem);
}

/* FUNÇÃO DE FORMATAÇÃO DE SAÍDA */
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

    QueryPerformanceFrequency(&frequencia);

    printf("--- MODO DE TESTES AUTOMATICOS (TORRE DE HANOI) ---\n");
    printf("Digite o numero de discos: ");
    scanf("%d", &n);
    printf("Quantas vezes deseja repetir o teste? ");
    scanf("%d", &repeticoes);

    // ALOCAÇÃO DO VETOR DE HISTÓRICO
    // Guardamos os tempos aqui para não usar printf dentro do loop
    double *historico = (double *)malloc(repeticoes * sizeof(double));
    if (historico == NULL) {
        printf("Erro ao alocar memoria para o historico.\n");
        return 1;
    }

    printf("\nProcessando testes silenciosamente... Aguarde.\n");

    for (int i = 0; i < repeticoes; i++) {
        // Medição pura
        QueryPerformanceCounter(&t1);
        torreHanoi(n, 'A', 'C', 'B');
        QueryPerformanceCounter(&t2);

        double tempo_micro = (double)(t2.QuadPart - t1.QuadPart) * 1000000.0 / frequencia.QuadPart;
        
        // Armazena o tempo individual no vetor
        historico[i] = tempo_micro;
        tempo_total += tempo_micro;

        // Feedback visual discreto a cada 10% do progresso
        if (repeticoes >= 10 && (i + 1) % (repeticoes / 10) == 0) printf("."); 
    }

    // EXIBIÇÃO DOS RESULTADOS INDIVIDUAIS
    // Isso acontece APÓS todos os testes terminarem
    printf("\n\n--- LOG DE EXECUCOES INDIVIDUAIS ---");
    for (int i = 0; i < repeticoes; i++) {
        printf("\nTeste %d: %.2f us | Bruto: %.10f s", i + 1, historico[i], historico[i] / 1000000.0);
    }

    double media = tempo_total / repeticoes;
    
    exibirTempoBonito(media);

    // LIBERAÇÃO DA MEMÓRIA
    free(historico);

    return 0;
}