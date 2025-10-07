#include <stdio.h>

void somar(float a, float b){
    printf("A soma é: %.2f", a + b);
}


int main(){

    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o primeiro número: ");
    scanf("%d", &num2);

    somar(num1, num2);
}