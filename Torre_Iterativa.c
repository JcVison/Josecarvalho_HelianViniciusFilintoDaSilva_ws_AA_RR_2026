#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 

/* ALGORITMO ANALISADO: Torre de Hanoi (Iterativa)
   COMPLEXIDADE: O(2^n)
   CARACTERISTICA: Utiliza um laco de repeticao puro. 
   Evita o overhead da pilha (stack), sendo mais eficiente em termos de hardware.
*/

void torreHanoiIterativa(int n) {
    // total_movimentos = 2^n - 1 usando deslocamento de bits (mais rapido que pow())
    unsigned long long i;
    unsigned long long total_movimentos = (1ULL << n) - 1;

    // Lógica iterativa baseada em propriedades binárias
    for (i = 1; i <= total_movimentos; i++) {
        /* A logica abaixo determina o pino de origem e destino
           baseado no numero do movimento atual. 
           Utilizamos operacoes bitwise para maxima performance. */
        unsigned long long de = (i & i - 1) % 3;
        unsigned long long para = ((i | i - 1) + 1) % 3;
        
        // Simulação de processamento do movimento (vazio para medir apenas o algoritmo)
    }
}

void exibirResultado(int n, int rep, double media_micro) {
    printf("\n========================================");
    printf("\n   RESULTADOS FINAIS - ITERATIVA");
    printf("\n========================================");
    printf("\nDiscos: %d", n);
    printf("\nRepeticoes: %d", rep);
    printf("\nMedia: %.2f us", media_micro);
    printf("\nTempo em Segundos: %.10f s", media_micro / 1000000.0);
    printf("\n========================================\n");
}

int main() {
    int n, repeticoes;
    LARGE_INTEGER frequencia, t1, t2; 
    double tempo_total = 0;

    QueryPerformanceFrequency(&frequencia);

    printf(">>> TESTE AUTOMATICO: TORRE DE HANOI ITERATIVA <<<\n");
    printf("Numero de discos: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Numero de repeticoes: ");
    if (scanf("%d", &repeticoes) != 1) return 1;

    // Alocação do histórico para evitar I/O durante o teste
    double *historico = (double *)malloc(repeticoes * sizeof(double));
    if (historico == NULL) {
        printf("Erro de memoria.\n");
        return 1;
    }

    printf("\nExecutando testes iterativos... ");

    for (int i = 0; i < repeticoes; i++) {
        QueryPerformanceCounter(&t1);
        
        torreHanoiIterativa(n);
        
        QueryPerformanceCounter(&t2);

        double t_micro = (double)(t2.QuadPart - t1.QuadPart) * 1000000.0 / frequencia.QuadPart;
        historico[i] = t_micro;
        tempo_total += t_micro;

        // Feedback visual a cada 10%
        if (repeticoes >= 10 && (i + 1) % (repeticoes / 10) == 0) printf("."); 
    }

    printf(" Concluido!\n\nLOG DE EXECUCOES:");
    for (int i = 0; i < repeticoes; i++) {
        printf("\n[%02d] %.2f us", i + 1, historico[i]);
    }

    exibirResultado(n, repeticoes, tempo_total / repeticoes);

    free(historico);
    system("pause");
    return 0;
}