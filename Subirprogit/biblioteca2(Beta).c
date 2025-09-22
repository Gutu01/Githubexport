//teste1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_livros 5
#define max_string 100
#define max_emprestimos 5

typedef struct{

    char nome[max_string];
    char autor[max_string];
    char editora[max_string];
    int edicao;
    int disponivel;

}Biblioteca;


typedef struct{

    int indice_livro;
    char nome_usuario[max_string];
}Emprestimo;


void limparbufferentrada(){
    int c;
    while (( c = getchar()) != '\n' && c != EOF);
}


int main(){

    Biblioteca *livro;
    Emprestimo *emprestimo;
 
    livro = (Biblioteca *) calloc(max_livros, sizeof(Biblioteca));
    emprestimo = (Emprestimo *) calloc(max_emprestimos, sizeof(Emprestimo));

    int opcao, total_livros=0, i, total_emprestimos=0;
    
    if(livro == NULL || emprestimo == NULL){
        printf("Erro na alocação de memória!\n\n");
        return 1;
    }

    do{

        printf("=========================\n");
        printf("   Biblioteca(Beta2)\n");
        printf("=========================\n");
        printf("1 - Resgistrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Pedir empréstimo\n");
        printf("4 - Listar empréstimos\n");
        printf("0 - Sair\n");
        printf("Resposta:");
        scanf("%d", &opcao);
        limparbufferentrada();

            switch (opcao){

                case 1:

                    if(total_livros == max_livros)
                        printf("\nO número máximo de livro foi atingido!\n\n");    
                    else {
                        printf("\nNome do livro:");
                        fgets(livro[total_livros].nome, max_string, stdin);
                        livro[total_livros].nome[strcspn(livro[total_livros].nome, "\n")] = '\0';

                        printf("Autor:");
                        fgets(livro[total_livros].autor, max_string, stdin);
                        livro[total_livros].autor[strcspn(livro[total_livros].autor, "\n")] = '\0';

                        printf("Editora:");
                        fgets(livro[total_livros].editora, max_string, stdin);
                        livro[total_livros].editora[strcspn(livro[total_livros].editora, "\n")] = '\0';

                        printf("Edição:");
                        scanf("%d", &livro[total_livros].edicao);
                        limparbufferentrada();

                        livro[total_livros].disponivel = 1;

                        total_livros++;
                    }
                    break;

                case 2:

                    if(total_livros == 0)
                        printf("\nNão há livros na biblioteca!\n\n");
                    else{
                        for(i=0; i < total_livros; i++){
                            printf("\n%dº livro:\n", i +1);
                            printf("Nome: %s\n", livro[i].nome);
                            printf("Autor(a): %s\n", livro[i].autor);
                            printf("Editora: %s\n", livro[i].editora);
                            printf("%dª edição\n", livro[i].edicao);
                            if(livro[i].disponivel == 1)
                                printf("Status: Disponível\n\n");
                            else
                                printf("Status: Indisponível\n\n");
                        }
                    }
                    break;
                
                case 3:
                    
            }
    }while (opcao != 0);

    return 0;
}