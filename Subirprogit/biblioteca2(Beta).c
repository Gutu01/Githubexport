// ===========================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 2
// 
// OBJETIVO DESTA PARTE:
// Adicionar a funcionalidade de empréstimo e introduzir alocação dinâmica.
// - Os arrays de livros e empréstimos são alocados com malloc/calloc.
// - NOva struct para Empréstimo.
// - Liberação de memória com free.
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100 // Definimos uma capacidade de empréstimos.
#define TAM_STRING 100

// --- Definição das Estruturas ---
// Struct Livro agora tem um campo 'disponivel' para controlar o status.
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;// 1 para sim, 0 para não.
};

//Nova struct para armazenar informações do empréstimo.
struct Emprestimo {
    int indiceLivro; //Para saber qual livro do array 'biblioteca' foi emprestado.
    char nomeUsuario[TAM_STRING];
};

// --- Funcão para limpar o buffer de entrada ---
void LimparBufferEntrada(){
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}

// --- Função Principal (main) ---
int main() {
    // 1. ALOCAÇÃO DINÂMICA DE MEMÓRIA
    // Agora, em vez de arrays estáticos, usamos ponteiros.
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    //Usamos calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
    //Vantagem: inicializa toda a memória com zeros. Isso significa que 'disponivel' já começa com...
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

    // Usamos malloc para o array de empréstimos. mallox(tamanho_total_em_bytes)
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // VERIFICAÇÃO: É crucial verificar se a aloxação de memória deu certo.
    if (biblioteca == NULL || emprestimos == NULL){
        printf("ERRO: Falha ao alocar memoria.\n");
        return 1; //retorn 1 para indicar um erro.
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    printf("Teste");
 }