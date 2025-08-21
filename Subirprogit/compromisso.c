#include <stdio.h>

#define max_letras 5600
#define max_compromissos 30

typedef struct{
    
    char descrição[max_letras];
    int minutos;
    int horas;
    int data;
    
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
                if(total_compromissos >= max_compromissos)
                printf("O número máximo de compromissos foi atingido!")
                printf("\nMarcar compromisso iniciado!\n\n");
                printf("Descrição:");
                fgets(compromisso)











        }
    }while (escolha != 0);

    return 0;
}