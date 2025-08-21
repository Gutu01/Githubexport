//Lista para melhorias:
//1ºIntegrar o sistema de tempo faltando de um outro projéto meu para cá.

#include <stdio.h>

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

    compromisso compromisso[max_compromissos];
    int total_compromissos=0;
    int escolha;

    do{

        printf("Escolha uma opção\n");
        printf("0-Sair\n");
        printf("1-Marcar compromisso\n");
        printf("2-Vercompromissos\n");
        printf("Resposta:");
        scanf("%d", &escolha);
        limparbufferentrada();


        switch(escolha){
            case 1:
                if(total_compromissos >= max_compromissos){
                    printf("\nO número máximo de compromissos foi atingido!\n\n");
                    break;
                }else{

                printf("O número máximo de compromissos foi atingido!");
                printf("\nMarcar compromisso iniciado!\n\n");
                printf("Descrição:");
                fgets(compromisso[max_compromissos].descrição, max_letras, stdin);
                
                printf("Data:");
                fgets(compromisso[max_compromissos].data, max_letras, stdin);

                printf("Horas(minutos no próximo campo):");
                fgets(compromisso[max_compromissos].horas, max_letras, stdin);

                printf("Minutos:");
                fgets(compromisso[max_compromissos].minutos, max_letras, stdin);

                printf("\nCompromisso agendado com sucesso!\n\n");
                }
            case 2:

                if(total_compromissos == 0){
                    printf("Não há compromissos agendados :(");
                    break;
                }else{
                    printf("\nAgenda de compromissos\n\n");
                    for(int i = 0; i < total_compromissos; i++){
                        printf("%s às %d:%d\n", compromisso[max_compromissos].data,
                        compromisso[max_compromissos].horas, 
                        compromisso[max_compromissos].minutos);
                        printf("%s\n\n", compromisso[max_compromissos].descrição);
                    }
                }


        }
    }while (escolha != 0);

    return 0;
}