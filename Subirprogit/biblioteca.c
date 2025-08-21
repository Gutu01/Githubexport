//Lista para melhorias:
//1ºAprimorar o código para ficar como protótipo
//para minha antiga escola;
//2ºFazer comentários do projéto;
//3ºFazer menus melhores;
//4ºFazer o código "a prova" de erros de digitação.

#include <stdio.h>

#define max_livros 50
#define max_letras 100

typedef struct{

    char nome[max_letras];
    char autor[max_letras];
    char cor[max_letras];

}livro;

void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    }

int main(){

    livro biblioteca[max_livros];
    int escolha = 0;
    int total_livros = 0;

    do{

    printf("Menu de opções\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Listar livros\n");
    printf("Resposta:");
    
    scanf("%d", &escolha);
    LimparBufferEntrada();

    switch(escolha){
        case 1:

        if(total_livros >= max_livros){
            printf("\nLimite de livros atingido.\n\n");
            break;
        } else {
        printf("\nO cadastro de livro foi iniciado.\n\n");
        printf("Qual o nome do livro?\nresposta:");
        fgets(biblioteca[total_livros].nome, max_letras, stdin);
        
        printf("Qual o nome do autor(a)?\nresposta:");
        fgets(biblioteca[total_livros].autor, max_letras, stdin);
        
        printf("Qual a cor da capa do livro?\nresposta:");
        fgets(biblioteca[total_livros].cor, max_letras, stdin);
        
        printf("\nLivro cadastrado com sucesso!\n\n");
        total_livros++;
        }
        break;
        case 2:
        
        if(total_livros == 0){
            printf("\nNão há livros registrados!\n\n");
        }else{
            
            printf("\nLista de livros\n\n");

        for(int i=0; i < total_livros; i++){
            printf("Nome: %s", biblioteca[i].nome);
            printf("Autor: %s", biblioteca[i].autor);
            printf("Cor: %s\n", biblioteca[i].cor);
                }

            }
        break;
        }
    }while (escolha != 0);


    return 0;
}
