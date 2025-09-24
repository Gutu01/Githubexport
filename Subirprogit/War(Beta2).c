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

int aleatorio(int *rola_dado1, int *rola_dado2){
    *rola_dado1 = rand() % 6 + 1;
    *rola_dado2 = rand() % 6 + 1;
}

void limparbufferentrada(){
    int c;
    while (( c = getchar ()) != '\n' && c != EOF);
}

int main(){

    int jogadores=0, i, total_jogadores=0, escolha=0, defensor=0, resultado1=0, resultado2=0;

    aleatorio(&resultado1, &resultado2);

    srand(time(NULL));

    Dados *dados;

    dados = (Dados *) calloc(6, sizeof(Dados));

    do{
        printf("\nInsira o número de jogadores ou 0 para sair (3-6 jogadores): ");
        scanf("%d", &jogadores);
        limparbufferentrada();

        if(jogadores == 0){
            printf("\nSaindo\n\n");
            return 1;
        }else if(jogadores<3 || jogadores>6)
            printf("\nNúmero de jogadores inválido!\n");
    }while (jogadores<3 || jogadores>6);

    total_jogadores = jogadores;
    
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

    do{
        
        printf("\n\nMapa de War\n\n");

        for(i=0; i < jogadores; i++){
            printf("%d - %s (cor %s, %d tropas)\n", i + 1, dados[i].nome, dados[i].cor, dados[i].num_tropas);
        }

            printf("\nTurno de ataque\n");
        do{
            
            printf("\nEscolha um atacante (1-%d, ou 0 para sair): ", jogadores);
            scanf("%d", &escolha);
            limparbufferentrada();

            if(escolha == 0){
                printf("\nSaindo do programa\n\n");
                return 0;
            }
            else if(escolha < 0 || escolha > jogadores)
                printf("Escolha Inválida");
        }while (escolha < 0 || escolha > jogadores);
        
        do{
            printf("\nEscolha um defensor (0 para sair): ");
            scanf("%d", &defensor);
            limparbufferentrada();

            if(defensor == 0){
                printf("\nSaindo do programa!\n\n");
                return 0;
            }
            else if(escolha == defensor || defensor < 0 || defensor > jogadores)
                printf("\nEscolha inválida!\n");

        }while (escolha == defensor || defensor < 1 || defensor > jogadores);

        //Isso cerve para encaixar nos arrays
        escolha--;
        defensor--;

        printf("%s, pressione ENTER para rolar o dado", dados[escolha].nome);
        getchar();

        printf("%s, tirou %d",dados[escolha].nome, resultado1);
        getchar();

        printf("%s, pressione ENTER para rolar o dado", dados[defensor].nome);
        getchar();

        printf("%s, tirou %d",dados[defensor].nome, resultado2);
        getchar();



    }while (total_jogadores != 1 || escolha != 0);

   
    free(dados);

    return 0;
}