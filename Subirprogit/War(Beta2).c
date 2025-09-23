#include <stdio.h>
#include <stdlib.h>

#define max_string 50

typedef struct{

    char nome[max_string];
    char cor[max_string];
    int num_tropas;

}Dados;

void limparbufferentrada(){
    int c;
    while (( c = getchar ()) != '\n' && c != EOF);
}

int main(){

    int jogadores=0;

    Dados *dados;

    dados = (Dados *) calloc(6, sizeof(Dados));

    do{
        printf("\nInsira o número de jogadores ou 0 para sair: ");
        scanf("%d", &jogadores);
        limparbufferentrada();

        if(jogadores == 0){
            printf("\nSaindo\n\n");
            return 1;
        }else if(jogadores<3 || jogadores>6)
            printf("\nNúmero de jogadores inválido!\n");
    }while (jogadores<3 || jogadores>6);

    
    return 0;
}