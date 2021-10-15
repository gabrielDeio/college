#include "queue.h"

Fila* create_queue (int tam) {
   Fila *f = (Fila *)malloc(sizeof(Fila));
   f->ini = 0;
   f->fim = 0;
   f->tam = tam;
   f->vetor = (int*)malloc(tam*sizeof(int));
   return f;
}

/*Função para enfileirar um elemento de uma fila 
  circular implementada através de um vetor!*/
void enqueue (Fila *f, int e) {
   if (full(f)) {
      printf("Full queue: Depleted capacity!\n");
      exit(1); /*aborta programa*/
   }
   else{
      f->vetor[f->fim] = e;
      if(f->fim == f->tam - 1) f->fim = 0;
      else (f->fim)++;
   }
}

/*Função para desenfileirar um elemento de uma fila 
  circular implementada através de um vetor!*/
int dequeue (Fila *f) {
   int elemento;
   
   if (empty(f)) {
      printf("Empty queue!\n");
      exit(1); /*aborta programa*/
   }
   else{   
      elemento = f->vetor[f->ini];
      if(f->ini == f->tam - 1) f->ini = 0;
      else (f->ini)++;
   }
   return elemento;

}

int empty (Fila *f) {
   return (f->ini == f->fim);
}

int full (Fila *f) {
   return (f->ini == ((f->fim + 1) % f->tam));
}

void free_queue (Fila *f) {
   free(f->vetor);
   free(f);
}

void print_queue (Fila *f){
   int i;

   printf("\nQueue = [");
   
   if(f->fim > f->ini){
      for(i = f->ini; i < f->fim; i++){
         printf("%d ", f->vetor[i]);
      }
   }
   else{
      for(i = f->fim; i < f->ini; i++){
         printf("%d ", f->vetor[i]);
      }   
   }
   printf("]\n");
}

void print_first (Fila *f){
   printf("%d ", f->vetor[f->ini]);
}
/*
int main()
{
   Fila *f;
   int element, option;

   f = create_queue(7);

   printf("f->tam = %d\n", f->tam);

   do{
      printf("Choose a option:\n1-Add a element to the queue\n2-Dequeue a element\n3-print the queue\n0-Exit\n");
      scanf("%d", &option);

      switch(option){
         case 0:
            printf("Bye!!\n");
            free_queue(f);
            break;   
         
         case 1:
            printf("\nInsert a element to the queue: ");
            scanf("%d", &element);
            enqueue(f, element);
            break;

         case 2:
            element = dequeue(f);
            break;

         case 3:
            print_queue(f);
            break;

         default:
            printf("Invalid option!!\n");
      }
   }while(option != 0);

   
   
   return 0;
   
}*/


