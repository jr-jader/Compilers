# Compilers
                                MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
                                MMMMMMMMMMMMds+:--------:+sdNMMMMMMMMMMM
                                MMMMMMMMms:-+sdNMMMMMMMMNdy+--omMMMMMMMM
                                MMMMMMh:` /mMMMMMMMMMMMMMMMMm+ `-yMMMMMM
                                MMMMd--hN``--sNMMMMMMMMMMNy:..`md:.hMMMM
                                MMM+`yMMMy hd+./hMMMMMMh/.+dd sMMMh`/MMM
                                MM:.mMMMMM:.NMMh/.+dd+./hMMM--MMMMMm--NM
                                M+`mMMMMMMN`+MMMMm-  .dMMMMo mMMMMMMN.:M
                                d yMMMMMMMMy dNy:.omNs--sNm oMMMMMMMMh h
                                /`MMMMMMMMMM.`.+dMMMMMMm+.``NMMMMMMMMM-:
                                .:MMMMMMMd+./`oMMMMMMMMMMs /.+dMMMMMMM/`
                                .:MMMMmo.:yNMs dMMMMMMMMm`oMNy:.omMMMM/`
                                /`MNy:.omMMMMM--MMMMMMMM:.MMMMMNs--sNM.:
                                d -` :++++++++: /++++++/ :++++++++:  : h
                                M+ yddddddddddd+ yddddy /dddddddddddy`/M
                                MM/.mMMMMMMMMMMM.-MMMM/.NMMMMMMMMMMm.:NM
                                MMMo`sMMMMMMMMMMd sMMy hMMMMMMMMMMy`+MMM
                                MMMMd--hMMMMMMMMM+`mN`/MMMMMMMMMh--hMMMM
                                MMMMMMh:.omMMMMMMN.:/`NMMMMMMms.:hMMMMMM
                                MMMMMMMMNs:./shmMMh  yMMNds/.:smMMMMMMMM
                                MMMMMMMMMMMMdy+/---``---:+sdMMMMMMMMMMMM
                                MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                      

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
