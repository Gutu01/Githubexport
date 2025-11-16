#include <stdio.h>

// A funlção agora recebe um ENDEREÇO (ponteiro para int)
void dobrar(int* x){
    // Acessarmos o valor NO ENDEREÇO e o modificamos
    *x = (*x) * 2;
}

int main(){
    int numero = 5;
    printf("Antes da função, o valor é: %d\n", numero);

    // Passamos o ENDEREÇO de 'numero' com o operador &
    dobrar(&numero);

    printf("Depois da função, o valor é: %d\n", numero);
}