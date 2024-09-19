# Compilers
                                    .....
                               .d$$$$*$$$$$$bc
                            .d$P"    d$$    "*$$.
                           d$"      4$"$$      "$$.
                         4$P        $F ^$F       "$c
                        z$%        d$   3$        ^$L
                       4$$$$$$$$$$$$$$$$$$$$$$$$$$$$$F
                       $$$F"""""""$F""""""$F"""""C$$*$
                      .$%"$$e    d$       3$   z$$"  $F
                      4$    *$$.4$"        $$d$P"    $$
                      4$      ^*$$.       .d$F       $$
                      4$       d$"$$c   z$$"3$       $F
                       $L     4$"  ^*$$$P"   $$     4$"
                       3$     $F   .d$P$$e   ^$F    $P
                        $$   d$  .$$"    "$$c 3$   d$
                         *$.4$"z$$"        ^*$$$$ $$
                          "$$$$P"             "$$$P
                            *$b.             .d$P"
                              "$$$ec.....ze$$$"
                                  "**$$$**""                        

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
