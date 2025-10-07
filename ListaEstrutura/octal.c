#include <stdio.h>

void hexa(int numero){
    printf("\nSeu número em Hexadecimal: %x\n", numero);
    printf("Seu número em Octal: %o\n", numero);
}

int main(){

    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    hexa(numero);

    return 0;
}