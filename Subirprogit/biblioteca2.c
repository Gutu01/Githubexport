#include <stdio.h>
#include <string.h>
#include <locale.h>

#define max_letras_livro 50
#define max_letras_nome 50
#define max_livros 5

typedef struct{

//Irei fazer apenas nome de inÃ­cio para ficar uma versÃ£o simplificada de melhor entendimento
    char nome[max_letras_livro];
    int disponivel;

}biblioteca;


typedef struct{

    int indice_livros;
    char nome_usuario[max_letras_nome];

}emprestimo;

void limparbufferentrada(){
    int c;
    while(( c = getchar()) != '\n' && c != EOF);
}


int main (){

    setlocale(LC_ALL, "");

    biblioteca livro[max_livros];
    int escolha, total_livros=0, i;

    do{

        printf("\nBiblioteca(beta)\n");
        printf("1-Cadastrar livro\n");
        printf("2-Lista de livros\n");
        printf("3-Fazer emprestimo\n");
        printf("4-Listar emprestimos\n");
        printf("0-Sair\n");
        printf("Resposta:");    
        scanf("%d", &escolha);
        limparbufferentrada();

        switch(escolha){
            case 1:
                
            if(total_livros >= max_livros){
                printf("\nO número máximo de livros foi atingido!\n\n");
                break;
            }else{
                printf("Nome do livro:");
                fgets(livro[total_livros].nome, max_letras_livro, stdin);
                livro[total_livros].nome[strcspn(livro[total_livros].nome, "\n")] = '\0';

                total_livros++;
                break;
            }
            case 2:

            if(total_livros == 0){
                printf("\nNão há livros registrados!\n\n");
                break;
            }else{
                for(i=0; i < total_livros; i++){
                    printf("\n%dº livro\nNome: %s\n",i+1, livro[i].nome);
                }
            }
            break;
        }
    }while(escolha != 0);
    
    return 0;
}