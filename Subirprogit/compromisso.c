//Lista para melhorias:
//1ºIntegrar o sistema de tempo faltando de um outro projéto meu para cá;
//2ºFazer as entradas "a prova" de erros;
//3ºfazer menus mais bonitos;
//4ºFazer comentários no projéto.

#include <stdio.h>
#include <string.h>

#define max_letras 5600
#define max_compromissos 30

typedef struct{
    
    char descrição[max_letras];
    char data[max_letras];
    int minutos;
    int horas;
    
}compromisso;

void limparbufferentrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){

    compromisso agenda[max_compromissos];
    int total_compromissos=0;
    int escolha;

    do{

        printf("Escolha uma opção\n");
        printf("0-Sair\n");
        printf("1-Agendar compromisso\n");
        printf("2-Ver compromissos\n");
        printf("Resposta:");
        scanf("%d", &escolha);
        limparbufferentrada();


        switch(escolha){
            case 1:
                if(total_compromissos >= max_compromissos){
                    printf("\nO número máximo de compromissos foi atingido!\n\n");
                    break;
                }else{
                printf("\nAgendamento de compromisso iniciado!\n\n");
                printf("Descrição:");
                fgets(agenda[total_compromissos].descrição, max_letras, stdin);
                agenda[total_compromissos].descrição[strcspn(agenda[total_compromissos].descrição
                , "\n")] = '\0';

                printf("Data:");
                fgets(agenda[total_compromissos].data, max_letras, stdin);
                agenda[total_compromissos].data[strcspn(agenda[total_compromissos].data
                , "\n")] = '\0';

                printf("Horas(minutos no próximo campo):");
                scanf("%d", &agenda[total_compromissos].horas);
                limparbufferentrada();

                printf("Minutos:");
                scanf("%d", &agenda[total_compromissos].minutos);
                limparbufferentrada();

                printf("\nCompromisso agendado com sucesso!\n\n");

                total_compromissos++;

                }
                break;
            case 2:

                if(total_compromissos == 0){
                    printf("\nNão há compromissos agendados :(\n\n");
                    break;
                }else{
                    printf("\nAgenda\n\n");
                    for(int i = 0; i < total_compromissos; i++){
                        printf("%s às %02d:%02d\n", agenda[i].data,
                        agenda[i].horas, 
                        agenda[i].minutos);
                        printf("%s\n\n", agenda[i].descrição);
                    }
                }


        }
    }while (escolha != 0);

    return 0;
}