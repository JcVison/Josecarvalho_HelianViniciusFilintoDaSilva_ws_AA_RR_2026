# Relatório de Análise de Complexidade Computacional
## Comparação entre Torre de Hanói Iterativa e Torre de Hanói Recursiva

---

## 1. Introdução

Este trabalho apresenta um estudo experimental sobre o algoritmo da Torre de Hanói, com foco na análise de desempenho computacional. A partir de diferentes implementações, busca-se observar como decisões de programação influenciam o tempo de execução de um mesmo problema clássico da computação.

Para isso, foram realizados testes controlados e repetidos, permitindo a coleta e organização de dados de forma sistemática. Os resultados obtidos servem como base para comparações e discussões ao longo do trabalho, contribuindo para a compreensão prática do impacto da implementação na eficiência de algoritmos

## 1.1 O que é a Torre de Hanói?

A Torre de Hanói é um problema clássico da matemática e da computação, amplamente utilizado no estudo de recursão, estruturas de dados e análise de algoritmos. Ele é frequentemente empregado como exemplo didático para compreender chamadas recursivas e o crescimento exponencial do custo computacional.

## 1.2 Descrição do Problema

O problema consiste em mover uma pilha de discos de uma haste de origem para uma haste de destino, utilizando uma haste auxiliar, obedecendo a um conjunto de regras bem definidas. Inicialmente, todos os discos estão empilhados na haste de origem, organizados em ordem decrescente de tamanho, com o maior disco na base e o menor no topo.

## 1.3 Regras do Jogo

Durante a execução do problema, devem ser respeitadas as seguintes regras:

Apenas um disco pode ser movido por vez;
Um disco maior nunca pode ser colocado sobre um disco menor;
Todos os discos devem começar empilhados corretamente na haste de origem.

---
## 1.4 Dedução da Recorrência — Torre de Hanói
1. Origem da Recorrência

A dedução começa a partir da lógica necessária para mover os discos entre as hastes. Para mover n discos, é preciso:

Mover os n − 1 discos superiores da haste de origem para a haste auxiliar;
Mover o maior disco diretamente para a haste de destino (1 movimento);
Mover novamente os n − 1 discos da haste auxiliar para a haste de destino.

Essa estratégia leva à seguinte relação de recorrência:

T(n)=T(n−1)+1+T(n−1)

Simplificando a expressão, obtemos:

T(n)=2T(n−1)+1

2. Processo de Expansão (Substituição)

Para identificar um padrão geral, expandimos a recorrência por substituição sucessiva:

1ª substituição:
<img width="309" height="33" alt="image" src="https://github.com/user-attachments/assets/e45181bf-8795-457a-ac53-2fdceb7ec72e" />

Distribuindo:
<img width="292" height="36" alt="image" src="https://github.com/user-attachments/assets/e47edb30-f2cf-4780-baea-29b7ef07d085" />

2ª substituição:
<img width="338" height="33" alt="image" src="https://github.com/user-attachments/assets/f4b0993c-9f20-4f73-b8da-222476637d28" />

Observa-se que, a cada expansão, o termo recursivo é multiplicado por uma potência de 2, enquanto os termos constantes se acumulam.

3. Generalização para o Passo k
A partir do padrão observado, é possível generalizar a expressão para qualquer nível k de recursão
<img width="310" height="92" alt="image" src="https://github.com/user-attachments/assets/bb2e3339-7200-4583-86ef-b33ab0812621" />

O termo <img width="74" height="91" alt="image" src="https://github.com/user-attachments/assets/bf9aebee-3e99-4b03-bc91-67136d083345" /> representa a soma das potências de 2 geradas durante as expansões sucessivas da recorrência.

4. Resolução da Somatória
A soma das potências de 2 pode ser resolvida utilizando a fórmula da Soma de uma Progressão Geométrica (PG):
<img width="165" height="68" alt="image" src="https://github.com/user-attachments/assets/21b79356-a14a-47a2-8ad7-b82b95f041ee" />

Substituindo os valores:
<img width="173" height="77" alt="image" src="https://github.com/user-attachments/assets/3d5da780-b097-4bae-9d7f-2eccbbe53020" />

Logo, o resultado da somatória é:
<img width="162" height="90" alt="image" src="https://github.com/user-attachments/assets/2a1472bc-cdbc-4c4b-83f2-ec6e72a4771d" />

5. Resultado Final da Recorrência
<img width="171" height="57" alt="image" src="https://github.com/user-attachments/assets/9f6c2bdf-598f-434f-9145-3aff33dd0e92" />

## 1.5 Prova por Indução Matemática: Torre de Hanói

A Indução Matemática é um método de prova utilizado para demonstrar a verdade de um número infinito de proposições. Funciona como um "efeito dominó": se conseguirmos derrubar a primeira peça (Base) e provarmos que a queda de uma peça derruba a próxima (Passo Indutivo), todas as peças cairão.
Objetivo da Prova

Queremos provar que a solução fechada <img width="153" height="36" alt="image" src="https://github.com/user-attachments/assets/1c49a199-7351-4d74-85ba-230674727acb" /> é verdadeira para todos os números naturais n, sabendo que a relação de recorrência do problema é: <img width="238" height="39" alt="image" src="https://github.com/user-attachments/assets/74ca9c24-5de5-42a2-add2-c45fe1f74ae7" />

1. Base da Indução
O primeiro passo consiste em mostrar que o enunciado vale para os primeiros casos (geralmente n=1).
<img width="496" height="124" alt="image" src="https://github.com/user-attachments/assets/4248d9e1-137f-4fa5-8591-ae9bca53111e" />
Nesse caso, ao substituir o vaalor de n por 1 e 2 tanto no t(n) quanto no j(n) o resultados foram iguais 

2. Hipótese de Indução
Supomos que o enunciado é verdadeiro para um elemento genérico n−1. Ou seja, assumimos como verdade que: <img width="337" height="45" alt="image" src="https://github.com/user-attachments/assets/48089001-41cc-41bf-b33e-3dfe5a9dd6da" />

3. Passo Indutivo
Agora, devemos provar que, se a hipótese vale para n−1, ela obrigatoriamente vale para o próximo elemento n. Utilizamos a fórmula da recorrência e substituímos os valores:

1. Partimos da recorrência conhecida: <img width="261" height="41" alt="image" src="https://github.com/user-attachments/assets/b26a3c73-1672-4cb1-9235-91de5383703d" />
  
2. Substituímos T(n−1) pela nossa Hipótese de Indução (J): <img width="256" height="44" alt="image" src="https://github.com/user-attachments/assets/c16ce6e9-d2b5-4efa-9cb7-ea62001e464d" />
  
3. Aplicamos o valor da fórmula J para n−1: <img width="267" height="41" alt="image" src="https://github.com/user-attachments/assets/bb002542-a2f7-4cbc-ab35-19a0bac6cdc2" />
  
4. Realizamos a distribuição do multiplicador: <img width="247" height="42" alt="image" src="https://github.com/user-attachments/assets/7163a2ca-ad35-4cdb-8657-d66e7d1539d8" />
  
5. Simplificamos os termos constantes (−2+1=−1): <img width="224" height="33" alt="image" src="https://github.com/user-attachments/assets/298cd763-8adb-4a84-a192-d88f3836e92a" />
  
6. Aplicamos a propriedade de potências de mesma base: <img width="156" height="31" alt="image" src="https://github.com/user-attachments/assets/c06463c3-803e-40d0-80c5-dc19bfa6eb33" />

Conclusão
A proposição <img width="241" height="28" alt="image" src="https://github.com/user-attachments/assets/6ec4d430-b8a1-423f-83e0-6602bbd8eecc" /> é verdadeira para todo n natural.
## 2. Desenvolvimento dos Algoritmos 

### 2.1 Algoritmos Implementados

- Torre de Hanói Recursiva:
Implementação baseada no paradigma de "Dividir e Conquistar", seguindo estritamente a recorrência matemática do problema. Embora seja o código mais elegante e fácil de ler, ela é a "opção lenta" devido ao overhead de chamadas de função. Cada movimento exige que o processador manipule a pilha de execução (stack), salvando contextos de memória bilhões de vezes, o que gera um custo computacional adicional perceptível em grandes valores de n.

- Torre de Hanói Iterativa:
Versão otimizada que substitui as chamadas recursivas por laços de repetição (loops) e lógica binária/bitwise. Esta implementação é a "opção rápida" porque trabalha de forma contínua, evitando o peso da pilha do sistema. Mesmo mantendo a mesma complexidade teórica, ela demonstra uma eficiência de hardware superior, resultando em tempos de execução significativamente menores e maior estabilidade térmica para o processador.

---

### 2.2 Criação do Algoritmo Automático

Inicialmente, foi desenvolvido um algoritmo capaz de executar a solução da Torre de Hanói em uma única execução, com o objetivo de validar a corretude da lógica implementada e o funcionamento básico do código. Em uma etapa posterior, essa implementação foi estendida por meio da adição de uma função de controle responsável por repetir automaticamente a execução do algoritmo quantas vezes o usuário desejar, possibilitando a coleta sistemática dos tempos de execução. Essa abordagem permitiu a realização de experimentos mais consistentes, reduzindo a influência de variações pontuais e viabilizando uma análise de desempenho mais confiável.

---
### 3 Considerações de Hardware

As variações observadas nos tempos de execução estão relacionadas principalmente ao escalonamento do sistema operacional, ao uso dinâmico dos níveis de cache da CPU e, em execuções mais longas, a eventuais efeitos de throttling térmico. Tais flutuações são inerentes ao ambiente de execução.

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

---
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
### 5.2 Graficos
<img width="549" height="409" alt="Grafico_1" src="https://github.com/user-attachments/assets/6339cf33-6287-42bf-a1ac-c67017e87c6f" />

<img width="549" height="412" alt="Grafico_2" src="https://github.com/user-attachments/assets/0326abfb-56d3-4f27-86be-9fa6408b2b00" />


---

## 6. Conclusão

Os resultados experimentais indicam que, embora as implementações recursiva e iterativa da Torre de Hanói compartilhem a mesma complexidade assintótica O(2ⁿ), a versão iterativa apresenta desempenho consistentemente superior. Essa vantagem decorre da eliminação do overhead associado às chamadas recursivas e ao uso intensivo da pilha de execução. Contudo, o crescimento exponencial do algoritmo permanece dominante, tornando ambas as abordagens inviáveis para valores elevados de n e evidenciando que otimizações de implementação afetam apenas o tempo absoluto, não o limite teórico do problema.
