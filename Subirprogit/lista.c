
#include <stdio.h>
#include <stdlib.h>

typedef struct No { 
 int dado; 
 struct No* proximo; 
} No; 

// Insere no início da lista
void inserirInicio(No** cabeca, int valor) { 
 No* novo = (No*) malloc(sizeof(No)); 
 novo->dado = valor; 
 novo->proximo = *cabeca; 
 *cabeca = novo; 
} 

// Exibe todos os elementos
void exibir(No* cabeca) { 
 No* atual = cabeca; 
 while (atual != NULL) { 
 printf("%d -> ", atual->dado); 
 atual = atual->proximo; 
 } 
 printf("NULL\n"); 
} 

// Libera toda a memória
void liberarLista(No** cabeca) { 
 No* atual = *cabeca; 
 while (atual != NULL) { 
 No* temp = atual; 
 atual = atual->proximo; 
 free(temp); 
 } 
 *cabeca = NULL; 
} 

int main() { 
 No* lista = NULL; 
 inserirInicio(&lista, 30); 
 inserirInicio(&lista, 20); 
 inserirInicio(&lista, 10); 
 printf("Lista: "); 
 exibir(lista); // Saída: 10 -> 20 -> 30 -> NULL
 liberarLista(&lista); 
 return 0; 
}