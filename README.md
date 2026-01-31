# 🎮 Hangman Core: Engine de Jogo de Forca em C

![C](https://img.shields.io/badge/language-C-blue.svg)
![Status](https://img.shields.io/badge/status-Functional-brightgreen.svg)
![Type](https://img.shields.io/badge/complexity-Intermediate-yellow.svg)

Uma implementação clássica do jogo de forca (Hangman) via CLI, focada em manipulação de buffers de memória, strings (arrays de char) e lógica de estados.

## 🔍 Code Walkthrough: Arquitetura do Jogo

O sistema opera através de um loop de eventos (`while(1)`) que gerencia a transição de estados do jogo:

1.  **Setup de Memória:** O programa aloca dois arrays de caracteres (`p_sec` e `p_tela`). Um armazena a verdade absoluta (palavra secreta) e o outro reflete o estado visível ao jogador.
2.  **Sanitização de Entrada:** Utiliza `fgets()` para segurança de buffer, seguido de um ajuste manual no terminador nulo (`\0`) para remover o caractere de nova linha (`\n`).
3.  **Mecanismo de Renderização:** A função `forca(int estado)` atua como um renderizador de estados estáticos, desenhando o ASCII art baseado no acumulador de erros.
4.  **Lógica de Comparação:** A cada iteração, o código percorre a string secreta comparando o caractere inserido. O uso de `strcmp` define a condição de vitória, validando a igualdade total entre os buffers.

---

## 🧠 Alfabetização Algorítmica (Fundamentals)

Este projeto demonstra conceitos fundamentais de engenharia de software:

* **Manipulação de Strings:** Uso intensivo de `string.h` (`strlen`, `strcpy`, `strcmp`).
* **Flag de Estado:** Uso da variável `sera_que_errou` como um sinalizador booleano (0 ou 1) para controle de fluxo condicional.
* **Gestão de Loops:** Implementação de loops aninhados (`for` dentro de `while`) para processamento de matrizes unidimensionais (arrays).



---

## 🛠 Deep Dive Técnico

### 1. Manipulação do Terminador Nulo (`\0`)
O código demonstra um entendimento profundo de como strings funcionam em C. Ao executar `p_sec[strlen(p_sec) -1] = '\0';`, o programa corrige manualmente o comportamento do `fgets`, que inclui o `ENTER` no buffer. Isso é essencial para que o `strcmp` funcione corretamente depois.

### 2. Segurança de I/O
Diferente do `gets()` (que é perigoso e obsoleto), o uso de `fgets(p_sec, 100, stdin)` previne o **Buffer Overflow**, limitando a leitura ao tamanho máximo do array alocado.

### 3. O "Hack" do Scanf
A instrução `scanf(" %c", &letra)` com um espaço antes do `%c` é uma solução técnica para limpar o buffer do teclado (consumindo o caractere de nova linha residual), evitando que o jogo pule rodadas ou entre em loop infinito.

---

## 🚀 Roadmap de Evolução

Para escalar este projeto para um nível de sistema comercial, as seguintes melhorias seriam aplicadas:

* **Abstração de UI:** Separar a lógica do jogo da lógica de impressão (limpar a tela com `system("clear")` ou sequências de escape ANSI).
* **Data Persistence:** Carregar palavras de um arquivo `.txt` externo em vez de entrada manual do Jogador 1.
* **Dicionário Dinâmico:** Uso de `malloc` e `free` para suportar palavras de qualquer tamanho, otimizando o uso da memória RAM.
* **Modularização:** Mover a função `forca` para um módulo de visualização separado.

---

## 💻 Compilação e Uso

```bash
# Compilar
gcc forca.c -o forca

# Executar
./forca
