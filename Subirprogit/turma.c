#include <stdio.h>
#include <string.h>

#define max_letras_nome 160
#define turma 3

typedef struct{

    int matricula;
    char nome[max_letras_nome];
    int codigo_disciplina;
    float nota_1;
    float nota_2;
    float media_final;

}Alunos;

void limparbufferentrada(){
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}
int main(){

    Alunos alunos[turma];
    int total_alunos=0;

    for(int i=0; i < turma; i++){

        printf("\nMatricula:");
        scanf("%d", &alunos[total_alunos].matricula);
        limparbufferentrada();

        printf("Nome:");
        fgets(alunos[total_alunos].nome, max_letras_nome, stdin);
        alunos[total_alunos].nome[strcspn(alunos[total_alunos].nome, "\n")] = '\0';

        printf("Código da disciplina:");
        scanf("%d", &alunos[total_alunos].codigo_disciplina);
        limparbufferentrada();

        printf("Nota 1:");
        scanf("%f", &alunos[total_alunos].nota_1);
        limparbufferentrada();

        printf("Nota 2:");
        scanf("%f", &alunos[total_alunos].nota_2);
        limparbufferentrada();

        alunos[total_alunos].media_final = (alunos[total_alunos].nota_1 + alunos[total_alunos].nota_2*2)/3;

        total_alunos++;
    }

    for(int i=0;i < total_alunos; i++){
        printf("\n%dº aluno:\n", i+1);
        printf("Nome:%s\n", alunos[i].nome);
        printf("Média final:%.2f\n", alunos[i].media_final);
    }

    return 0;
}