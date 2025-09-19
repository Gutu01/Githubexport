// ===========================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 2
// teste 1
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
    biblioteca = (struct Livro *) malloc(MAX_LIVROS, sizeof(struct Livro));

    // Usamos malloc para o array de empréstimos. mallox(tamanho_total_em_bytes)
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // VERIFICAÇÃO: É crucial verificar se a aloxação de memória deu certo.
    if (biblioteca == NULL || emprestimos == NULL){
        printf("ERRO: Falha ao alocar memoria.\n");
        return 1; //retorn 1 para indicar um erro.
    }

    int totalLivros = 0;
    int totalemprestimos = 0;
    int opcao, i;

    do{
        printf("====================================\n");
        printf("       BIBLIOTECA - PARTE 2\n");
        printf("====================================\n");
        printf("1 - Cadastrar no livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar emprestimo\n");
        printf("4 - Listar emprestimos\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        LimparBufferEntrada();

        switch (opcao){
            case 1: // CADASTRO DE LIVROS
                printf("--- Cadastro de Novo Livro ---\n\n");
                if(totalLivros < MAX_LIVROS){
                    //O acesso aos campos é igual ao do array estático.
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    // ... (demais leituras são iguais à Parte 1) ...
                    printf("Digite o autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    printf("Digite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite a edição: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    LimparBufferEntrada();

                    //Ao Cadastrar, o livro automaticamente se torna disponível.
                    biblioteca[totalLivros].disponivel = 1;

                    totalLivros++;
                    printf("\nLivro cadastado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia!\n");
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            case 2: //LISTAGEM DE LIVROS
                printf("--- Lista de Livros Cadastrados ---\n\n");
                if (totalLivros == 0){
                    printf("Nenhum livro cadastrado ainda.\n");
                } else {
                    for (i=0; i < totalLivros; i++){
                        printf("-----------------------------------\n");
                        printf("LIVRO %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        //Mostrar p status de disponibilidade.
                        printf("Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Emprestad...");//... não consegui ver o resto
                    }
                    printf("----------------------------\n");
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            case 3:// REALIZAR EMPRÉSTIMO
                printf("--- Realizar Emprestimo ---\n\n");

                if(totalemprestimos >= MAX_EMPRESTIMOS){
                    printf("Limite de emprestimos atingidos!\n");
                } else {
                    printf("Livros disponiveis:\n");
                    int disponiveis = 0;
                    for (i =0; i < totalLivros; i++) {
                        if (biblioteca[i].disponivel){
                            printf("%d - %s\n", i + 1, biblioteca[i].nome);
                            disponiveis++;
                        }
                    }

                    if (disponiveis == 0) {
                        printf("Nenhum livro disponivel para emprestimo.\n");
                    } else {
                        printf("\nDigite o número do livro que deseja emprestar:");
                        int numLivro;
                        scanf("%d", &numLivro);
                        LimparBufferEntrada();

                        int indice = numLivro - 1; //Converte para o índice do array (0 a N-1).

                        //Validação da escolha do usuário.
                        if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel){
                            printf("Digite o nome do usuário que está pegando o livro: ");
                            fgets(emprestimos[totalemprestimos].nomeUsuario, TAM_STRING, stdin);
                            emprestimos[totalemprestimos].nomeUsuario[strcspn(emprestimos[totalemprestimos].nomeUsuario, "\n")] = '\0'; 
                            
                            // Registra o empréstimo
                            emprestimos[totalemprestimos].indiceLivro = indice;

                            // Atualiza o status do livro para indisponivel.
                            biblioteca[indice].disponivel = 0;

                            totalemprestimos++;
                            printf("\nemprestimo realizado com sucesso!\n");
                        } else {
                            printf("\nNúmero de livro inválido ouu livro indisponível.\n");
                        }
                    }
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            case 4: //LISTAR EMPRÉSTIMOS
                printf("--- Lista de Emprestimos ---\n");
                if (totalemprestimos == 0){
                    printf("Nenhum emprestimo realizado.\n");
                } else {
                    for (i = 0; i < totalemprestimos; i++){
                        //Usa o índice armazenado no empréstimo para buscar o nome do livro.
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("---------------------------------------\n");
                        printf("EMPRESTIMO %d\n", i + 1);
                        printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
                    }
                    printf("---------------------------------------\n");
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            case 0:
                printf("\nSaindo so sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }
    }while (opcao != 0);

    // 2. LIBERAÇÃO DA MEMÓRIA
    // Antes de terminar, é ESSENCIAL liberar a memória que foi alocada dinamicamente.
    //Isso evita "memory leaks" (vazamentos de memória).
    free(biblioteca);
    free(emprestimos);

    printf("Memória libeada com sucesso.\n");

    return 0;
 }