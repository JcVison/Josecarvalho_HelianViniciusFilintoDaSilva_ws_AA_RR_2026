# Relatório de Análise de Complexidade Computacional
## Comparação entre Torre de Hanói O(2ⁿ) e Torre de Hanói Melhorada com Merge Sort O(n log n)

---

## 1. Introdução

Este relatório apresenta uma análise experimental de complexidade computacional comparando dois algoritmos com comportamentos assintóticos distintos: a Torre de Hanói tradicional, de complexidade exponencial O(2ⁿ), e uma versão melhorada da Torre de Hanói baseada no algoritmo Merge Sort, de complexidade O(n log n).

O objetivo é demonstrar, por meio de testes práticos, como o crescimento do tamanho da entrada (n) impacta diretamente o tempo de execução, validando empiricamente conceitos teóricos de exponencialidade, eficiência e escalabilidade algorítmica.

---

## 2. Desenvolvimento dos Algoritmos e Estratégia Experimental

### 2.1 Algoritmos Implementados
Torre de Hanói Tradicional (Manual)
Implementação clássica recursiva, utilizada como base de comparação.

Torre de Hanói Tradicional Automática
Versão criada para executar o algoritmo tradicional repetidas vezes, medir tempos médios e reduzir interferências externas.

Torre de Hanói Melhorada (Manual)
Implementação otimizada desenvolvida manualmente, utilizando Merge Sort como estratégia central de processamento.

Torre de Hanói Melhorada Automática
Versão criada para executar a implementação melhorada de forma repetida, calcular tempos médios e garantir maior confiabilidade nos testes.
---

### 2.2 Criação do Algoritmo Automático

O algoritmo automático foi desenvolvido para executar múltiplas repetições do algoritmo e medir o tempo de execução de cada repetição.


---

## 3. Validação do Algoritmo Automático

Antes da execução em larga escala, o algoritmo automático foi validado comparando seus resultados com a versão manual.

---

## 4. Resultados Experimentais

### 4.1 Torre de Hanói Tradicional – O(2ⁿ)
|  Discos (n) | T1   | T2     | T3     | T4     | T5     | T6     | T7     | T8     | T9     | T10      | Média    |
| ----------: | -----| -----  | -----  | -----  | -----  | -----  | -----  | -----  | -----  | ------   | ---------|
|   10 (μs) | 5.00   | 4.50   | 3.80   | 3.80   | 3.80   | 3.80   | 3.60   | 3.70   | 3.70   | 3.60     | 3.93 μs  |
|    20 (s) | 0.0035 | 0.0032 | 0.0026 | 0.0040 | 0.0037 | 0.0030 | 0.0026 | 0.0026 | 0.0027 | 0.0027   | 0.0031 s |
|    25 (s) | 0.09   | 0.10   | 0.09   | 0.14   | 0.09   | 0.09   | 0.09   | 0.09   | 0.09   | 0.10     | 0.10 s   |
|    30 (s) | 2.71   | 2.75   | 2.73   | 2.73   | 2.71   | 2.72   | 2.73   | 2.71   | 2.72   | 2.73     | 2.73 s   |
|    32 (s) | 10.85  | 10.85  | 10.86  | 10.85  | 10.86  | 10.86  | 10.91  | 10.92  | 10.85  | 10.86    | 10.87 s  |
|    35 (s) | 87.41  | 87.59  | 87.82  | 87.59  | 87.57  | 87.62  | 87.57  | 87.38  | 87.41  | 87.31    | 87.53 s  |


---

### 4.2 Torre de Hanói Melhorada – Merge Sort O(n log n)

| Elementos (n) | T1   | T2   | T3  | T4   | T5   | T6   | T7   | T8   | T9   | T10  | Média        |
| ------------: | ---- | ---- | --- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ------------ |
|          10   | 13.2 | 6.3  | 2.5 | 3.6  | 2.8  | 2.4  | 2.7  | 2.3  | 2.4  | 3.3  |   4.15 μs    |
|          20   | 24.5 | 5.7  | 5.3 | 5.2  | 17.3 | 25.4 | 6.4  | 6.3  | 7.1  | 6.0  |   10.92 μs   |
|          25   | 21.0 | 7.6  | 7.2 | 8.8  | 6.7  | 8.6  | 7.7  | 7.3  | 6.4  | 7.6  |   8.89 μs    |
|          30   | 36.3 | 8.9  | 8.5 | 11.2 | 8.7  | 9.4  | 9.0  | 11.0 | 9.6  | 8.5  |   12.11 μs   |
|          32   | 27.1 | 11.4 | 8.7 | 8.4  | 9.5  | 15.1 | 8.7  | 10.3 | 13.8 | 14.9 |   12.79 μs   |
|          35   | 23.1 | 9.8  | 9.3 | 9.2  | 10.1 | 11.7 | 10.3 | 9.2  | 11.5 | 9.4  |   11.36 μs   |



---

## 5. Análise Comparativa

### 5.1 Comparação Final
| Entrada (Hanói / Merge) | Torre de Hanói – O(2ⁿ) (s) | Merge Sort – O(n log n) (s) |
| ----------------------: | -------------------------: | --------------------------: |
|               10 / 10   |                 0.00000393 |                  0.00000415 |
|               20 / 20   |                     0.0031 |                  0.00001092 |
|               25 / 25   |                       0.10 |                  0.00000889 |
|               30 / 30   |                       2.73 |                  0.00001211 |
|               32 / 32   |                      10.87 |                  0.00001279 |
|               35 / 35   |                      87.53 |                  0.00001136 |



---

### 5.2 Considerações de Hardware

As variações entre os tempos de execução observadas nos testes decorrem principalmente do escalonamento do sistema operacional, do uso dinâmico do cache da CPU e, em execuções mais longas, de possíveis efeitos de throttling térmico. Tais variações são pequenas e não afetam a análise geral, sendo suavizadas pelo uso da média dos tempos medidos.

---

### 5.3 Limitações de Memória

Embora o algoritmo baseado em Merge Sort seu desempenho pode ser limitado pela disponibilidade de memória RAM em cenários com entradas muito grandes.

---

## 6. Conclusão

Os experimentos confirmam que a Torre de Hanói tradicional é inviável para grandes valores de n devido ao crescimento exponencial do tempo de execução. Em contraste, a abordagem baseada em Merge Sort apresenta alta eficiência e boa escalabilidade, evidenciando a importância da escolha adequada de algoritmos considerando tanto tempo quanto espaço computacional.
