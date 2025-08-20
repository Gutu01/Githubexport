#include <stdio.h>

#define max_livros 50
#define max_letras 100

typedef struct{

    char nome[max_letras];
    char autor[max_letras];
    char cor[max_letras];

}livro;

int main(){

    livro biblioteca;
    int escolha = 0;
    int total_livros = 0;

    

    do{

    printf("Menu de opções\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Listar livros\n");
    printf("Resposta:");
    
    scanf("%d", &escolha);
    getchar();

    switch(escolha){
        case 1:
        printf("O cadastro de livro foi iniciado.\n\n");
        if(total_livros >= max_livros){
            printf("Limite de livros atingido.\n");
        } else {
        printf("Qual o nome do livro?\nresposta:");
        fgets(biblioteca.nome, max_letras, stdin);
        
        printf("Qual o nome do autor?\nresposta:");
        fgets(biblioteca.autor, max_letras, stdin);
        
        printf("Qual a cor da capa do livro?\nresposta:");
        fgets(biblioteca.cor, max_letras, stdin);
        
        printf("Livro cadastrado com sucesso!\n\n");
        total_livros++;
        }
        case 2:
        printf("Lista ")
        

        
        }
    }while (escolha != 0);


    return 0;
}
