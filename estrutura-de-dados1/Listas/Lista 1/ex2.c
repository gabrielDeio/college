#include <stdio.h>
#include <stdlib.h>

typedef struct _fila {
   int ini;
   int fim;
   int tam;
   int *vetor;
} Fila;

Fila* criar_fila (int tamanho) {
   Fila *fila = (Fila *) malloc(sizeof(Fila));
   fila->vetor = (int *) malloc(tamanho * sizeof(int));

   return fila;
}

void destruir_fila (Fila *f) {
   free(f->vetor);
   free(f);
}

void enqueue (Fila *f, int elemento) {
   if(f->fim != f->tam - 1){
       f->vetor[f->fim] = elemento;
       f->fim++;
   }
   else{
       printf("\nLista cheia!!\n");
       exit(1);
   }   
}

int dequeue (Fila *f) {
   int elemento;
   
   if(f->ini != f->fim){
       elemento = f->vetor[f->ini];
       (f->ini)++;
       
       return elemento;
   }
   else{
       printf("\nLista vazia!!\n");
       exit(1);
   }  
} 

void printVetor(Fila *f, int ini, int fim){
    int i;

    printf("\nFila = [");

    for(i = f->ini; i < f->fim; i++){
        printf("%d ", f->vetor[i]);
    }
    printf("]\n");
}

int main () {

   /*Inicializando a estrutura de dados fila!*/  
   Fila *fila = criar_fila (10);

   fila->fim = 0;
   fila->ini = 0;
   
   /*Tentando inserir o elemento 1 na fila!*/ 
   int elem = 1; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 2 na fila!*/ 
   elem = 2; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 3 na fila!*/ 
   elem = 3; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 4 na fila!*/ 
   elem = 4; 
   enqueue (fila, elem);

   printVetor(fila, fila->ini, fila->fim);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/ 
   printf("%d\n", dequeue (fila));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/ 
   printf("%d\n", dequeue (fila));

   printVetor(fila, fila->ini, fila->fim);

   destruir_fila (fila);

   return 0;
}