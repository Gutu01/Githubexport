#include <stdio.h>
#include <string.h>

#define max_letras_nome 50
#define max_letras_nascimento 11
#define max_letras_cargo 30
#define max_letras_CPF 16

typedef struct{

    char nome[max_letras_nome];
    int idade;
    int sexo;
    char CPF[max_letras_CPF];
    char data_nascimento[max_letras_nascimento];
    int codigo_setor;
    char cargo[max_letras_cargo];
    float salario;

}Dados;

void limparbufferentrada(){
    int c;
    while(( c = getchar()) != '\n' && c != EOF);
}

int main(){

    Dados dados; 

    printf("Nome:");
    fgets(dados.nome, max_letras_nome, stdin);
    dados.nome[strcspn(dados.nome, "\n")] = '\0';

    printf("Idade:");
    scanf("%d", &dados.idade);
    limparbufferentrada();

    do{
        printf("\nSexo:\n1-Masculino\n2-Feminino\nResposta:");
        scanf("%d", &dados.sexo);
        limparbufferentrada();
    }while(dados.sexo != 1 && dados.sexo != 2);

    printf("CPF:");
    fgets(dados.CPF, max_letras_CPF, stdin);
    dados.CPF[strcspn(dados.CPF, "\n")] = '\0';

    printf("Data de nascimento:");
    fgets(dados.data_nascimento, max_letras_nascimento, stdin);
    dados.data_nascimento[strcspn(dados.data_nascimento, "\n")] = '\0';

    do{
        printf("\nCódigo do setor onde trabalha(0-99):");
        scanf("%d", &dados.codigo_setor);
        limparbufferentrada();
    }while(dados.codigo_setor < 0 || dados.codigo_setor > 99);

    printf("Cargo que ocupa:");
    fgets(dados.cargo, max_letras_cargo, stdin);
    dados.cargo[strcspn(dados.cargo, "\n")] = '\0';

    printf("\nSalário:");
    scanf("%f", &dados.salario);
    limparbufferentrada();

    printf("\nNome: %s", dados.nome);
    printf("\nIdade: %d", dados.idade);

    if(dados.sexo == 1)
        printf("\nSexo: Masculino");
    else
        printf("\nSexo: Feminino");

    printf("\nCPF: %s", dados.CPF);
    printf("\nData de nascimento: %s", dados.data_nascimento);
    printf("\nCódigo do setor onde trabalha: %.2d", dados.codigo_setor);
    printf("\nCargo ocupado: %s", dados.cargo);
    printf("\nSalário: %.2f\n\n", dados.salario);

    return 0;
}