#include <stdio.h>
#include <string.h>

#define max_letras_nome 160
#define max_registros 3

typedef struct{

    int matricula;
    char nome[max_letras_nome];
    float nota_prova_1;
    float nota_prova_2;
    float nota_prova_3;
    float media_geral;

}Aluno;

void limparbufferentrada(){
    int c;
    while (( c = getchar()) != '\n' && c != EOF);
}

int main(){

    Aluno aluno[max_registros];
    int total_alunos=0, i;
    float maior_nota_primeira_prova=0;
    float maior_media_geral=0;
    float menor_media_geral=1000;

    for(i=0; i < max_registros; i++){
        printf("\n%dº aluno:\n", i+1);
        printf("Número da matricula:");
        scanf("%d", &aluno[total_alunos].matricula);
        limparbufferentrada();

        printf("Nome:");
        fgets(aluno[total_alunos].nome, max_letras_nome, stdin);
        aluno[total_alunos].nome[strcspn(aluno[total_alunos].nome, "\n")] = '\0';

        printf("Nota 1º prova:");
        scanf("%f", &aluno[total_alunos].nota_prova_1);
        limparbufferentrada();

        printf("Nota 2º prova:");
        scanf("%f", &aluno[total_alunos].nota_prova_2);
        limparbufferentrada();

        printf("Nota 3º prova:");
        scanf("%f", &aluno[total_alunos].nota_prova_3);
        limparbufferentrada();

        aluno[total_alunos].media_geral = (aluno[total_alunos].nota_prova_1 + aluno[total_alunos].nota_prova_2 +aluno[total_alunos].nota_prova_3)/3;

        if(aluno[total_alunos].nota_prova_1 > maior_nota_primeira_prova)
            maior_nota_primeira_prova =  aluno[total_alunos].nota_prova_1;
        if(aluno[total_alunos].media_geral > maior_media_geral)
            maior_media_geral = aluno[total_alunos].media_geral;
        if(aluno[total_alunos].media_geral < menor_media_geral)
            menor_media_geral = aluno[total_alunos].media_geral;

        total_alunos++;
    }

    for(i=0;i < max_registros; i++){
        printf("\n%dº aluno:\n", i+1);
        printf("Matrícula:%d\n", aluno[i].matricula);
        printf("Nome:%s\n", aluno[i].nome);
        printf("1º nota:%.2f\n", aluno[i].nota_prova_1);
        printf("2º nota:%.2f\n", aluno[i].nota_prova_2);
        printf("3º nota:%.2f\n", aluno[i].nota_prova_3);
        printf("Média geral:%.2f\n", aluno[i].media_geral);
        
        if(aluno[i].media_geral >= 6)
            printf("\nO aluno foi aproado!\n\n");
        else
            printf("\nO aluno foi reprovado!\n\n");
    }

    printf("Maior nota da primeira prova:%.2f\n", maior_nota_primeira_prova);
    printf("Maior média geral:%.2f\n", maior_media_geral);
    printf("Menor média geral:%.2f\n", menor_media_geral);

    return 0;
}