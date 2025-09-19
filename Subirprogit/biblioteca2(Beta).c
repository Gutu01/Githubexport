//teste1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_livros 5
#define max_string 100


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

    int opcao, total_livros=0;

    
    do{

        printf("=========================\n");
        printf("   Biblioteca(Beta2)\n");
        printf("=========================\n");
        printf("1 - Resgistrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Pedir empréstimo\n");
        printf("4 - Listar empréstimos\n");
        printf("Resposta:");
        scanf("%d", &opcao);

            switch (opcao){

                case 1:

                    if(total_livros > max_livros){
                        printf("\nO número máximo de livro foi atingido!\n\n");
                        break;
                    } else {
                        printf("");
                    }
            }
    }while (opcao != 0);

    return 0;
}