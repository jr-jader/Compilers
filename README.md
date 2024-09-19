# Compilers

```mermaid
graph TD;
    A((A)) --> B((B));
    B --> C((C));
    C --> D((D));
    D --> E((E));
    E --> A;
    A --> C;
    C --> E;
    E --> B;
    B --> D;
    D --> A;

Este repositório foi criado para armazenar e organizar os trabalhos e listas desenvolvidos durante a disciplina de Compiladores. Ele contém projetos como analisadores léxicos, sintáticos, um mini compilador para Portugol, além de listas de exercícios práticos e teóricos.

## Estrutura do Repositório

- **[Analisador Léxico](./Lexico/)**
  - Implementação de um analisador léxico desenvolvido usando Flex.
  - O analisador reconhece e categoriza tokens com base nas definições fornecidas.

- **[Analisador Sintático](./Sintatico/)**
  - Implementação de um analisador sintático usando Bison.
  - O analisador utiliza uma gramática definida para identificar estruturas válidas de código.

- **[Compilador de Portugol](./Portugol/)**
  - Um compilador básico que converte código escrito em Portugol para uma linguagem intermediária.
  - Integra análise léxica e sintática para fazer a tradução.

- **Listas de Exercícios**
  - **[Práticas](./Prático/)**: Atividades focadas na implementação de técnicas de compilação.
  - **[Teóricas](./Teórico/)**: Questões e discussões sobre conceitos relacionados a compiladores.

## Requisitos

Para compilar e executar os projetos, é necessário ter as seguintes ferramentas instaladas:

- Flex
- Bison
- G++ (para projetos em C++)

## Como Utilizar

1. Clone este repositório:
   ```bash
   git clone https://github.com/jr-jader/Compilers.git
