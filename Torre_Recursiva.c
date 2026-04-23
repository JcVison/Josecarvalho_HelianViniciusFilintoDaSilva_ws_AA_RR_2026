#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 

/* ALGORITMO ANALISADO: Torre de Hanoi (Recursiva)
   COMPLEXIDADE: O(2^n)
   CARACTERISTICA: Utiliza a pilha (stack) para cada chamada, gerando overhead.
*/

void torreHanoiRecursiva(int n, char origem, char destino, char auxiliar) {
    if (n == 0) return;
    torreHanoiRecursiva(n - 1, origem, auxiliar, destino);
    torreHanoiRecursiva(n - 1, auxiliar, destino, origem);
}

void exibirResultado(int n, int rep, double media_micro) {
    printf("\n========================================");
    printf("\n   RESULTADOS FINAIS - RECURSIVA");
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

    printf(">>> TESTE AUTOMATICO: TORRE DE HANOI RECURSIVA <<<\n");
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

    printf("\nExecutando testes... ");

    for (int i = 0; i < repeticoes; i++) {
        QueryPerformanceCounter(&t1);
        
        torreHanoiRecursiva(n, 'A', 'C', 'B');
        
        QueryPerformanceCounter(&t2);

        double t_micro = (double)(t2.QuadPart - t1.QuadPart) * 1000000.0 / frequencia.QuadPart;
        historico[i] = t_micro;
        tempo_total += t_micro;

        if (repeticoes >= 10 && (i + 1) % (repeticoes / 10) == 0) printf("."); 
    }

    printf(" Concluido!\n\nLOG DE EXECUCOES:");
    for (int i = 0; i < repeticoes; i++) {
        printf("\n[%02d] %.2f us", i + 1, historico[i]);
    }

    exibirResultado(n, repeticoes, tempo_total / repeticoes);

    free(historico);
    system("pause"); // Mantém o terminal aberto no Windows
    return 0;
}