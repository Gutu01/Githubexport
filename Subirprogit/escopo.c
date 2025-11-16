#include <stdio.h>

int global = 10;

void MostrarGlobal(){
    printf("Na função MostarGlobal: %d\n", global);
}

int main(){
    int local = 5;

    printf("Na função main (local): %d\n", local);
    printf("Na função main (global): %d\n", global);

    MostrarGlobal();

    return 0;
}