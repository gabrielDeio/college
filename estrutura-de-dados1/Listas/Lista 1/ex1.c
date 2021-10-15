#include <stdio.h>
#include <stdlib.h>

/*NAO USE VARIAVEIS GLOBAIS!!!!!!!!!!!!!*/

/*Função para enfileirar um dado elemento em um vetor: */
void enqueue (int vetor[], int elemento, int *fim, int tamanho) {
    int i;
    
    
    if(*fim != tamanho - 1){
        vetor[*fim] = elemento;

        *fim = *fim + 1;

        /*printf("\nFila = [");
        for(i = 0; i < *fim; i++)
        {
            printf("%d ", vetor[i]);
        }
        printf("]\n");*/

    }
    else{ 
        printf("Lista cheia!!\n");
        exit(1);
    }        
}

/*Função para desenfileirar um dado elemento em um vetor: */
int dequeue (int vetor[], int *inicio, int fim,  int tamanho) { 
    int elemento, i;
    
    if(*inicio == fim){ 
        printf("\nLista vazia!!\n");
        exit(1);
    }
    else{
        elemento = vetor[*inicio];
        *inicio = *inicio + 1;

        /*printf("\nFila1 = [");
        for(i = *inicio; i < fim; i++)
        {
            printf("%d ", vetor[i]);
        }
        printf("]\n");*/
        
        return elemento;
    } 
}	

int main () {

   int elem, fim = 0, inicio = 0;

   /*Determinando o tamanho da fila!*/ 
   int fila_tamanho = 10;

   /*Reservando o espaco para o vetor na memoria!*/ 
   int *fila = (int *)malloc(fila_tamanho * sizeof(int)); 

   /*Tentando inserir o elemento 1 na fila!*/ 
   
   elem = 1;
   enqueue (fila, elem, &fim, fila_tamanho);
   //printf("\nfimmain = %d\n", fim);

   /*Tentando inserir o elemento 2 na fila!*/ 
   elem = 2; 
   enqueue (fila, elem, &fim, fila_tamanho);
   //printf("\nfimmain = %d\n", fim);

   /*Tentando inserir o elemento 3 na fila!*/ 
   elem = 3; 
   enqueue (fila, elem, &fim, fila_tamanho);

   /*Tentando inserir o elemento 4 na fila!*/ 
   elem = 4; 
   enqueue (fila, elem, &fim, fila_tamanho);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/ 
   printf("\nElemento retirado: %d\n", dequeue (fila, &inicio, fim, fila_tamanho));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/ 
   printf("\nElemento retirado: %d\n", dequeue (fila, &inicio, fim, fila_tamanho));

   free(fila);

   return 0;	 
}
