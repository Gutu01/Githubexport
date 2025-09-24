// Isso faz sempre o mesmo númeroa aleatórios, pois usa a mesma semente
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main(){

// int aleatorio;

// aleatorio = rand();
// 
// printf("%d", aleatorio);

// return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int aleatorio,i;
    srand(time(NULL));

    for(i=0; i<100;i++){

    aleatorio = rand() % 6 + 1;

    printf("%d ", aleatorio);

    }

    return 0;
}