#include <stdio.h>
#include <string.h>

#define max_pessoas 5
#define max_letras_nome 160
#define max_letras_endereco 85

typedef struct{

    char endereco[max_letras_endereco];
    char nome[max_letras_nome];
    int idade;

}cadastro;

void limparbufferentrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main(){

    cadastro pessoa[max_pessoas];
    int escolha;
    int total_pessoas=0;

    do{
        printf("\nTela inicial\n");
        printf("0-Sair\n");
        printf("1-Registrar\n");
        printf("2-Ver lista de cadastros\n");
        printf("Resposta:");
        scanf("%d", &escolha);
        limparbufferentrada();

        switch(escolha){
            case 1:

                printf("Nome:");
                fgets(pessoa[total_pessoas].nome, max_letras_nome, stdin);
                pessoa[total_pessoas].nome[strcspn(pessoa[total_pessoas].nome, "\n")] = '\0';

                printf("Idade:");
                scanf("%d", &pessoa[total_pessoas].idade);
                limparbufferentrada();

                printf("Endereço:");
                fgets(pessoa[total_pessoas].endereco, max_letras_endereco, stdin);
                pessoa[total_pessoas].endereco[strcspn(pessoa[total_pessoas].endereco, "\n")] = '\0';

                total_pessoas++;
                break;
            case 2:
                if(total_pessoas == 0){
                    printf("\nO número máximo de cadastros foi atingido!\n\n");
                    break;
                }else{
                    for(int i=0; i < total_pessoas; i++){
                        printf("\n%dº Cadastro:\n", i+1);
                        printf("Nome:%s\n", pessoa[i].nome);
                        printf("Idade:%d\n", pessoa[i].idade);
                        printf("Idade:%s\n\n", pessoa[i].endereco);
                    }
                    break;
                }
        }
    }while(escolha != 0);

    return 0;
}