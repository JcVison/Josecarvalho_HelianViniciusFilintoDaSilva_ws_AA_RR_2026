# Seminário de Análise de Algoritmos
## Tema: Torre de Hanói

Este repositório foi desenvolvido para a atividade de seminário da disciplina **Análise de Algoritmos** da **Universidade Federal de Roraima (UFRR)**, ministrada pelo **Prof. Dr. Herbert Oliveira Rocha**.

De acordo com a proposta do trabalho, o seminário deve apresentar a análise detalhada de um algoritmo, contendo função de custo e complexidade, implementação em C, experimentação com diferentes entradas, coleta de tempo de execução, gráfico de desempenho e a apresentação de um algoritmo mais eficiente para comparação.

---

## Informações da Disciplina

- **Universidade:** Universidade Federal de Roraima (UFRR)
- **Disciplina:** Análise de Algoritmos
- **Professor:** Prof. Dr. Herbert Oliveira Rocha
- **Tipo de atividade:** Seminário
- **Prazo de entrega:** 12/06/2025
- **Formato da apresentação:** Slide
- **Tempo de apresentação:** 10 minutos por equipe 

---

## Tema Escolhido

O tema escolhido pela equipe foi **Torre de Hanói**, conforme a lista de temas disponibilizada no documento da disciplina. 

A Torre de Hanói é um problema clássico da computação e da matemática, muito utilizado para demonstrar o funcionamento da recursão. O problema consiste em mover uma pilha de discos de uma haste de origem para uma haste de destino, utilizando uma haste auxiliar, obedecendo às seguintes regras:

1. Apenas um disco pode ser movido por vez;
2. Um disco maior nunca pode ser colocado sobre um disco menor;
3. Todos os discos começam empilhados na haste de origem em ordem decrescente de tamanho.

---

## Objetivo do Trabalho

Este trabalho tem como objetivo analisar o algoritmo recursivo da Torre de Hanói, observando seu comportamento assintótico, sua função de custo e seu desempenho prático por meio de testes automatizados em linguagem C.

Além disso, para atender ao requisito da atividade, também foi utilizado um algoritmo mais eficiente para comparação de complexidade: o **Merge Sort**, cuja complexidade é inferior à da Torre de Hanói em termos assintóticos. 

---

## Equipe

### Responsável pelos testes e código
- **Helian Vinicius Filinto da Silva**
- Matrícula: **2022008985**
- E-mail: **Helianvinicius40@gmail.com**

### Responsável pelo GitHub, relatórios e slide
- **José Carvalho Neto**
- Matrícula: **2023010235**
- E-mail: **josecarvalhoneto3@gmail.com**

---
## Estrutura do Projeto

A organização do projeto foi definida para separar os códigos principais, os testes automáticos, os relatórios e os slides da apresentação.

```text
Aluno_ws_AA_RR_2025/
│
├── codigos/
│   ├── Torre_Iterativa.c
│   ├── Torre_Recursiva.c
│
├── relatorio/
│   └── relatorio_seminario_torre_hanoi.pdf
│
├── slides/
│   └── seminario_torre_hanoi.pptx
│
└── README.md
