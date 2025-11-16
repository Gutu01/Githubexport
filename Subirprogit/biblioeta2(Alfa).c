// ==========================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 3
//
// OBJETIVO DESTA PARTE:
// Modularizar o código com funções especializadas, aplicando boas práticas.
// - Passagem por valor (para exibição) e por referência (para modificação).
// - Funções para cada funcionabilidade principal do sistema.
// - A função main() se torna um "orquestrador" , chamado as outras.
// ==========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -- Constantes Globais ---
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

// --- Definição das Estruturas ---
struct Livro{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};

struct Emprestimo{
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

// --- Portótipos das Funções ---
// Declarar as funções aqui permite que a "main" as chame de suas definições.
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivros(const struct Livro *biblioteca, int totalLivros); // "const" indica que a função...
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos); // !!!Atenção!!! Código não finalizado
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimo);

// Código não finalizado pela falta de informações no vídeo de demonstraçãod o código