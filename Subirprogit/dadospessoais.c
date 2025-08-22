#include <stdio.h>
#include <string.h>

#define max_pessoas 5
#define max_letras 160

typedef struct{

    char nome[max_letras];
    int idade;

}cadastro;

void limparbufferentrada(){
    int c;
    while ((c = getchar()) != '\n && != EOF');
}


int main(){

    cadastro pessoa[max_pessoas];
    int escolha;

    do{
        printf("Tela inicial\n");
        printf("0-Sair\n");
        printf("1-Registrar\n");
        printf("2-Ver lista de cadastros\n");
        printf("Resposta:");
        scanf("%d", &escolha);
        limparbufferentrada();

        switch(escolha){
            case 1:

                printf("Nome:");
                fgets(pessoa[max_pessoas].nome, max_letras, stdin);
                pessoa[max_pessoas].nome[strcspn(pessoa[max_pessoas].nome, "\n")] = '\0';

                printf("Idade:");
                scanf("%d", &pessoa[max_pessoas].idade);

                printf("")
        }
    }while(escolha != 1);

    return 0;
}