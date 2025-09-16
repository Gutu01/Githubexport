#include <stdio.h>
#include <locale.h>

typedef struct{

    float x;
    float y;
    float z;

}Vetor;

int main(){

    setlocale(LC_ALL, "");

    
    Vetor numeros1, numeros2, resultado;

    printf("Insira a primeira categoria de números\n\n");
    printf("X:");
    scanf("%f", &numeros1.x);
    printf("Y:");
    scanf("%f", &numeros1.y);
    printf("Z:");
    scanf("%f", &numeros1.z);

    printf("Insira a segunda categoria de números\n\n");
    printf("X:");
    scanf("%f", &numeros2.x);
    printf("Y:");
    scanf("%f", &numeros2.y);
    printf("Z:");
    scanf("%f", &numeros2.z);

    resultado.x = numeros1.x + numeros2.x;
    resultado.y = numeros1.y + numeros2.y;
    resultado.z = numeros1.z + numeros2.z;


    printf("A soma das duas são:\nX: %.2f\nY: %.2f\nZ: %.2f\n\n", resultado.x, resultado.y, resultado.z);

    return 0;
}