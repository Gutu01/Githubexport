#include <stdio.h>
#include <string.h>

#define max_nome_livro 50
#define max_letras_nome 50


typedef struct{

//Irei fazer apenas nome de início para ficar uma versão simplificada de melhor entendimento
    char nome[max_nome_livro];
    int disponível;

}biblioteca;


typedef struct{

    int indice_livros;
    char nome_usuario[max_letras_nome]

}emprestimo;

void limparbufferentrada(){
    int c;
    while(( c = getchar()) != '\n' && c != EOF);
}

int main (){



}