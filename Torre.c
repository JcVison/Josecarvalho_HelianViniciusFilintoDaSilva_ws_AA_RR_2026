#include <stdio.h>
#include <windows.h> // Biblioteca necessária para acessar a API do Windows e medir tempo em us

// Função recursiva que implementa a lógica da Torre de Hanói
void torreHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        return;
    }
    torreHanoi(n - 1, origem, auxiliar, destino);
    torreHanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;
    
    // Estruturas do Windows para lidar com o contador de performance de 64 bits
    LARGE_INTEGER frequencia; 
    LARGE_INTEGER t1, t2;     
    double tempo_micro;

    // Obtém a frequência do hardware (ticks por segundo)
    QueryPerformanceFrequency(&frequencia);

    printf("Digite o numero de discos: ");
    if (scanf("%d", &n) != 1) return 1;

    // --- INÍCIO DA MEDIÇÃO ---
    QueryPerformanceCounter(&t1);
    
    torreHanoi(n, 'A', 'C', 'B');
    
    QueryPerformanceCounter(&t2);
    // --- FIM DA MEDIÇÃO ---

    // Cálculo: (Diferença de ticks * 1.000.000) / Frequência = microssegundos (us)
    tempo_micro = (double)(t2.QuadPart - t1.QuadPart) * 1000000.0 / frequencia.QuadPart;

    // Exibe os resultados no console usando a abreviação 'us'
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Tempo para %d discos: %.2f us\n", n, tempo_micro);
    
    // Valor bruto em segundos com 10 casas decimais para máxima precisão
    printf("Tempo convertido: %.10f s\n", tempo_micro / 1000000.0);

    return 0;
}