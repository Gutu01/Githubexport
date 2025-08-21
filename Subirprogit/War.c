#include <stdio.h>
#include <string.h>

#define max_letras_pais 28
#define max_letras_cor 21
#define max_jogadores 5

typedef struct{

    char nome_pais[max_letras_pais];
    char nome_cor[max_letras_cor];
    int tropas;
}war;

void limparbufferentrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){

    war dados_jogo[max_jogadores];
    int escolha;

    printf("Vamos começar o jogo?\n");
    printf("0-Sair\n1-Jogar\nEscolha:");
    scanf("%d", &escolha);
    limparbufferentrada();

    if(escolha == 1)
        printf("\nVamos começar o jogo!\n");
    else if(escolha == 0){
        return 1;}

    printf("Insira 5 territórios para começar\n");

    for(int i = 0;i < 5; i++){

        printf("\n%dº território\n", i + 1);
        printf("Nome do território:");
        fgets(dados_jogo[i].nome_pais, max_letras_pais, stdin);
        dados_jogo[i].nome_pais[strcspn(dados_jogo[i].nome_pais, "\n")] = '\0';

        printf("Cor das tropas:");
        fgets(dados_jogo[i].nome_cor, max_letras_cor, stdin);
        dados_jogo[i].nome_cor[strcspn(dados_jogo[i].nome_cor, "\n")] = '\0';

        printf("Número de tropas:");
        scanf("%d", &dados_jogo[i].tropas);
        limparbufferentrada();

    }

    printf("\n*Mapa dos territórios*\n\n");

    for(int i = 0; i < 5; i++){

        
        printf("%dº território\n", i +1);
        printf("Nome: %s\n", dados_jogo[i].nome_pais);
        printf("Cor do exercíto: %s\n", dados_jogo[i].nome_cor);
        printf("Quantidade de tropas: %d\n\n", dados_jogo[i].tropas);
    }

    return 0;
}