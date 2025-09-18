// ===========================================================================
// PR�TICA: SISTEMA DE BIBLIOTECA - PARTE 2
// 
// OBJETIVO DESTA PARTE:
// Adicionar a funcionalidade de empr�stimo e introduzir aloca��o din�mica.
// - Os arrays de livros e empr�stimos s�o alocados com malloc/calloc.
// - NOva struct para Empr�stimo.
// - Libera��o de mem�ria com free.
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100 // Definimos uma capacidade de empr�stimos.
#define TAM_STRING 100

// --- Defini��o das Estruturas ---
// Struct Livro agora tem um campo 'disponivel' para controlar o status.
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;// 1 para sim, 0 para n�o.
};

//Nova struct para armazenar informa��es do empr�stimo.
struct Emprestimo {
    int indiceLivro; //Para saber qual livro do array 'biblioteca' foi emprestado.
    char nomeUsuario[TAM_STRING];
};

// --- Func�o para limpar o buffer de entrada ---
void LimparBufferEntrada(){
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}

// --- Fun��o Principal (main) ---
