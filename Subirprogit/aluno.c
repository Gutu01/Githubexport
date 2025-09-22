#include <stdio.h>
#include <string.h>

#define max_letras_nome 160
#define max_letras_curso 20
#define max_alunos 2

typedef struct{
    
    char nome[max_letras_nome];
    int matricula;
    char curso[max_letras_curso];

}Aluno;

void limparbufferentrada(){
    int c;
    while (( c = getchar ()) != '\n' && c != EOF);
}

int main(){

    Aluno aluno[max_alunos];
    int total_alunos=0, i;

    for(i=0; i < max_alunos; i++){

        printf("\n%dº aluno\n", i+1);
        printf("Nome:");
        fgets(aluno[total_alunos].nome, max_letras_nome, stdin);
        aluno[total_alunos].nome[strcspn(aluno[total_alunos].nome, "\n")] = '\0';

        printf("matricula:");
        scanf("%d", &aluno[total_alunos].matricula);
        limparbufferentrada();

        printf("Curso:");
        fgets(aluno[total_alunos].curso, max_letras_nome, stdin);
        aluno[total_alunos].curso[strcspn(aluno[total_alunos].curso, "\n")] = '\0';

        total_alunos++;
    }

    for(i=0; i < total_alunos;i++){
        printf("\n%dº cadastro:\n", i+1);
        printf("Nome:%s\n", aluno[i].nome);
        printf("Número de matricula:%d\n", aluno[i].matricula);
        printf("Curso:%s\n", aluno[i].curso);
    }

    return 0;
}