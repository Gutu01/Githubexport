#include <stdio.h>

int main(){
    
    int a = 5;
    float b = 10.2;
    char c = 'A';


    int *d = &a;
    float *e = &b;
    char *f = &c;
    

    printf("a: %i\n", a);
    printf("b: %.2f\n", b);
    printf("c: %i\n\n", c);

    printf("*d: %i\n", *d);
    printf("*e: %.2f\n", *e);
    printf("*f: %i\n", *f);
    
    return 0;
}