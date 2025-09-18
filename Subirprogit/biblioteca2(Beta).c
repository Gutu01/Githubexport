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
int main() {
    // 1. ALOCA��O DIN�MICA DE MEM�RIA
    // Agora, em vez de arrays est�ticos, usamos ponteiros.
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    //Usamos calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
    //Vantagem: inicializa toda a mem�ria com zeros. Isso significa que 'disponivel' j� come�a com...
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

    // Usamos malloc para o array de empr�stimos. mallox(tamanho_total_em_bytes)
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // VERIFICA��O: � crucial verificar se a aloxa��o de mem�ria deu certo.
    if (biblioteca == NULL || emprestimos == NULL){
        printf("ERRO: Falha ao alocar memoria.\n");
        return 1; //retorn 1 para indicar um erro.
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    printf("Teste");
 }