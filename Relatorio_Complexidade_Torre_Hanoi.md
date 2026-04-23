# Relatório de Análise de Complexidade Computacional
## Comparação entre Torre de Hanói Iterativa e Torre de Hanói Recursiva

---

## 1. Introdução

Este trabalho apresenta um estudo experimental sobre o algoritmo da Torre de Hanói, com foco na análise de desempenho computacional. A partir de diferentes implementações, busca-se observar como decisões de programação influenciam o tempo de execução de um mesmo problema clássico da computação.

Para isso, foram realizados testes controlados e repetidos, permitindo a coleta e organização de dados de forma sistemática. Os resultados obtidos servem como base para comparações e discussões ao longo do trabalho, contribuindo para a compreensão prática do impacto da implementação na eficiência de algoritmos

---

## 2. Desenvolvimento dos Algoritmos 

### 2.1 Algoritmos Implementados

- Torre de Hanói Recursiva
Implementação baseada no paradigma de "Dividir e Conquistar", seguindo estritamente a recorrência matemática do problema. Embora seja o código mais elegante e fácil de ler, ela é a "opção lenta" devido ao overhead de chamadas de função. Cada movimento exige que o processador manipule a pilha de execução (stack), salvando contextos de memória bilhões de vezes, o que gera um custo computacional adicional perceptível em grandes valores de n.

- Torre de Hanói Iterativa
Versão otimizada que substitui as chamadas recursivas por laços de repetição (loops) e lógica binária/bitwise. Esta implementação é a "opção rápida" porque trabalha de forma contínua, evitando o peso da pilha do sistema. Mesmo mantendo a mesma complexidade teórica, ela demonstra uma eficiência de hardware superior, resultando em tempos de execução significativamente menores e maior estabilidade térmica para o processador.

---

### 3 Criação do Algoritmo Automático

Inicialmente, foi desenvolvido um algoritmo capaz de executar a solução da Torre de Hanói em uma única execução, com o objetivo de validar a corretude da lógica implementada e o funcionamento básico do código. Em uma etapa posterior, essa implementação foi estendida por meio da adição de uma função de controle responsável por repetir automaticamente a execução do algoritmo quantas vezes o usuário desejar, possibilitando a coleta sistemática dos tempos de execução. Essa abordagem permitiu a realização de experimentos mais consistentes, reduzindo a influência de variações pontuais e viabilizando uma análise de desempenho mais confiável.

---

## 3. Validação do Algoritmo Automático

Antes da execução em larga escala, o algoritmo automático foi validado comparando seus resultados com a versão manual.

---

## 4. Resultados Experimentais

### 4.1 Torre de Hanói Recursiva – O(2ⁿ)
## Resultados – Torre de Hanói (Recursiva)

| Discos (n) | Repetições |   Média (µs) | Tempo Médio (s) |
| ---------: | ---------: | -----------: | --------------: |
|         10 |         20 |        11.02 |        0.000011 |
|         15 |         20 |       348.55 |        0.000349 |
|         20 |         20 |     10942.20 |        0.010942 |
|         25 |         20 |    283182.53 |        0.283183 |
|         30 |         20 |   7901740.90 |        7.901741 |
|         35 |         20 | 182453095.49 |      182.453095 |



---

### 4.2 Torre de Hanói Iterativa
| Discos (n) | Repetições |   Média (µs) | Tempo Médio (s) |
| ---------: | ---------: | -----------: | --------------: |
|         10 |         20 |         7.08 |        0.000007 |
|         15 |         20 |       187.65 |        0.000188 |
|         20 |         20 |      7293.24 |        0.007293 |
|         25 |         20 |    186929.96 |        0.186930 |
|         30 |         20 |   5103828.74 |        5.103829 |
|         35 |         20 | 135874776.01 |      135.874776 |


## 5. Análise Comparativa

### 5.1 Comparação Final
| Discos (n) | Recursiva – Média (µs) |  Recursiva (s) | Iterativa – Média (µs) |  Iterativa (s) |     Ganho da Iterativa |
| ---------: | ---------------------: | -------------: | ---------------------: | -------------: | ---------------------: |
|         10 |               11.02 µs |   0.00001103 s |                7.08 µs |   0.00000708 s |   ~35.8% mais rápida   |
|         15 |              348.55 µs |   0.00034856 s |              187.65 µs |   0.00018765 s |   ~46.2% mais rápida   |
|         20 |           10,942.20 µs |   0.01094221 s |            7,293.24 µs |   0.00729324 s |   ~33.4% mais rápida   |
|         25 |          283,182.53 µs |   0.28318254 s |          186,929.96 µs |   0.18692996 s |   ~33.98% mais rápida  |
|         30 |        7,901,740.90 µs |   7.90174090 s |        5,103,828.74 µs |   5.10382874 s |   ~35.4% mais rápida   |
|         35 |      182,453,095.49 µs | 182.45309550 s |      135,874,776.01 µs | 135.87477601 s |   ~25.5% mais rápida   |

---

### 5.2 Considerações de Hardware

As variações observadas nos tempos de execução estão relacionadas principalmente ao escalonamento do sistema operacional, ao uso dinâmico dos níveis de cache da CPU e, em execuções mais longas, a eventuais efeitos de throttling térmico. Tais flutuações são inerentes ao ambiente de execução e foram mitigadas pela realização de múltiplas repetições e pelo uso da média aritmética, não comprometendo a confiabilidade da análise comparativa.

---

## 6. Conclusão

Os resultados experimentais indicam que, embora as implementações recursiva e iterativa da Torre de Hanói compartilhem a mesma complexidade assintótica O(2ⁿ), a versão iterativa apresenta desempenho consistentemente superior. Essa vantagem decorre da eliminação do overhead associado às chamadas recursivas e ao uso intensivo da pilha de execução. Contudo, o crescimento exponencial do algoritmo permanece dominante, tornando ambas as abordagens inviáveis para valores elevados de n e evidenciando que otimizações de implementação afetam apenas o tempo absoluto, não o limite teórico do problema.
