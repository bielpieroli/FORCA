# FORCA / HANGMAN GAME

Este é um jogo de Forca implementado na linguagem C. O jogo segue as regras tradicionais da forca, onde um jogador escolhe uma palavra e fornece uma dica, enquanto outro jogador tenta adivinhar a palavra antes que suas tentativas se esgotem.

This is a Hangman game implemented in the C programming language. The game follows the traditional rules of Hangman, where one player chooses a word and provides a hint, while the other player tries to guess the word before running out of attempts.

---

## MOTIVAÇÃO / MOTIVATION

Este projeto foi desenvolvido como parte da disciplina de Introdução à Ciência da Computação I. O objetivo era aplicar os conceitos aprendidos durante o semestre, como manipulação de strings, loops, funções e entrada/saída, para criar um programa funcional e interativo. Como amante de jogos, decidi implementar uma versão do clássico jogo da forca, que pode ser jogado diretamente no terminal.

This project was developed as part of the Introduction to Computer Science I subject. The goal was to apply the concepts learned during the semester, such as string manipulation, loops, functions, and input/output, to create a functional and interactive program. As a gaming enthusiast, I decided to implement a version of the classic Hangman game, which can be played directly in the terminal.

---

## FUNCIONAMENTO / HOW IT WORKS

O jogo é projetado para ser jogado por duas pessoas:

1. **Primeiro Jogador**: Escolhe uma palavra e fornece uma dica sobre ela.
2. **Segundo Jogador**: Tenta adivinhar a palavra com base na dica, tendo um número limitado de tentativas.

O jogo continua até que o segundo jogador adivinhe a palavra corretamente ou esgote todas as tentativas.

The game is designed for two players:

1. **First Player**: Chooses a word and provides a hint about it.
2. **Second Player**: Tries to guess the word based on the hint, with a limited number of attempts.

The game continues until the second player guesses the word correctly or exhausts all attempts.

---

## COMO JOGAR? / HOW TO PLAY?

1. **Compilação**: Compile o código usando um compilador C, como `gcc`:
```bash
gcc forca.c -o forca
```
2. **Execução**: Execute o programa gerado:
  ```bash
  ./forca
  ```
Instruções:

- O primeiro jogador insere a palavra a ser adivinhada e uma dica.

- O segundo jogador tenta adivinhar a palavra, letra por letra.

- O jogo informa se a letra está correta ou não, e atualiza o estado da palavra oculta.

- O jogo termina quando a palavra é completamente adivinhada ou quando as tentativas se esgotam.

1. **Compilation**: Compile the code using a C compiler, such as gcc:
  ```bash
  gcc forca.c -o hangman
  ```
2. *Execution*: Run the generated program:
  ```bash
  ./hangman
  ```
Instructions:

- The first player enters the word to be guessed and a hint.

- The second player tries to guess the word, one letter at a time.

- The game informs whether the letter is correct or not and updates the state of the hidden word.

- The game ends when the word is fully guessed or when all attempts are exhausted.

---

## ESTRUTURA DO CÓDIGO / CODE STRUCTURE

O código está organizado em funções principais:

- **`pedirasinfos`**: Solicita a palavra e a dica ao primeiro jogador.
- **`uppereocultarsecreta`**: Converte a palavra para maiúsculas e cria uma versão oculta da palavra (com hífens).
- **`forca`**: Implementa a lógica principal do jogo, incluindo a verificação de letras e a contagem de tentativas.
- **`main`**: Função principal que orquestra a execução do jogo.

The code is organized into main functions:

- **`pedirasinfos`**: Asks the first player for the word and the hint.
- **`uppereocultarsecreta`**: Converts the word to uppercase and creates a hidden version of the word (with hyphens).
- **`forca`**: Implements the core logic of the game, including letter verification and attempt counting.
- **`main`**: The main function that orchestrates the execution of the game.

---

## MELHORIAS FUTURAS / FUTURE IMPROVEMENTS

- **Interface Gráfica**: Adicionar uma interface gráfica simples para tornar o jogo mais atraente.
- **Modo Single Player**: Implementar um modo onde o computador escolhe a palavra aleatoriamente de uma lista predefinida.
- **Dificuldade**: Adicionar níveis de dificuldade, variando o número de tentativas ou o tamanho das palavras.

- **Graphical Interface**: Add a simple graphical interface to make the game more visually appealing.
- **Single Player Mode**: Implement a mode where the computer randomly selects a word from a predefined list.
- **Difficulty Levels**: Add difficulty levels by varying the number of attempts or the size of the words.
