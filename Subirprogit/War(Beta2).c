#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max_string 30
#define max_nome_cor 10

typedef struct{

    char nome[max_string];
    char cor[max_nome_cor];
    int num_tropas;

}Dados;

void limparbufferentrada(){
    int c;
    while (( c = getchar ()) != '\n' && c != EOF);
}

int main(){

    int jogadores=0, i;

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

    for(i=0; i < jogadores; i++){

        printf("\nNome do %dº território: ", i+1);
        fgets(dados[i].nome, max_string, stdin);
        dados[i].nome[strcspn(dados[i].nome, "\n")] = '\0';

        printf("Cor das tropas: ");
        fgets(dados[i].cor, max_string, stdin);
        dados[i].cor[strcspn(dados[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &dados[i].num_tropas);
        limparbufferentrada();
        
    }

    printf("\n\nMapa de War\n\n");

    for(i=0; i < jogadores; i++){
        printf("%d - %s (cor %s, %d tropas)\n", i + 1, dados[i].nome, dados[i].cor, dados[i].num_tropas);
    }

    printf("\nTurno de ataque\n");
    printf("Escolha um atacante");
    
    free(dados);

    return 0;
}