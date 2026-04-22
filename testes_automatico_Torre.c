#include <stdio.h>
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

    printf("--- MODO DE TESTES AUTOMATICOS ---\n");
    printf("Digite o numero de discos: ");
    scanf("%d", &n);
    printf("Quantas vezes deseja repetir o teste? ");
    scanf("%d", &repeticoes);

    printf("\nProcessando testes... Aguarde.\n");

    for (int i = 1; i <= repeticoes; i++) {
        // Medição pura, sem interrupções de printf
        QueryPerformanceCounter(&t1);
        torreHanoi(n, 'A', 'C', 'B');
        QueryPerformanceCounter(&t2);

        double tempo_micro = (double)(t2.QuadPart - t1.QuadPart) * 1000000.0 / frequencia.QuadPart;
        tempo_total += tempo_micro;

        // Feedback visual simples para não parecer que o programa travou em testes longos
        if (i % 10 == 0) printf("."); 
    }

    double media = tempo_total / repeticoes;
    
    exibirTempoBonito(media);

    return 0;
}