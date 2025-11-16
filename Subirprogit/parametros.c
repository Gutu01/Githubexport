#include <stdio.h>
#include <locale.h>

// Esta função recebe uma CÓPIA valor
void dobrar(int x){
    x = x * 2;
    printf("Dentro da função, o valor da cópia é: %d\n", x);
}

int main(){
    //Essa função coloca o código em português
    setlocale(LC_ALL, "Portuguese");

    int numero = 5;

    printf("Antes de chamar a função, o valor original é: %d\n", numero);

    // Passando 'numero' por valor
    dobrar(numero);

    printf("Depois de chamar a função, o valor original é: %d", numero);

    return 0;
}