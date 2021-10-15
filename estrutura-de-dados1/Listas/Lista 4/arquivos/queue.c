#include "queue.h"

/*Função para criar uma fila vazia (não criar nenhum nó, só devolver NULL)!*/
Queue* create_queue () {
   return NULL;
}

/*Função para liberar uma fila nó por nó!*/
void free_queue (Queue *q) {
   while(q != NULL){
      Queue *aux = q->next;
      free(q);
      q = aux;
   }
}

/*Função para enfileirar um elemento (inserir na cauda da lista encadeada)!*/
Queue* enqueue (Queue *q, int elem) {
   Queue *new = (Queue*)malloc(sizeof(Queue));
   new->info = elem;
   new->next = q;

   return new;
}

/*Função para desenfileirar um elemento (remover da cabeça da lista encadeada)!*/
Queue* dequeue (Queue *q) {
   if(empty_queue(q)){
      printf("\nFila vazia!!!\n");
      exit(1);
   }
   else{
      Queue *prv = NULL;   Queue *v = q;
      while(v->next != NULL){
         prv = v;
         v = v->next;
      }
      if(v->next == NULL){
         prv->next = NULL;
         free(v);
      }
   }
   return q;
}

/*Função para retornar o primeiro elemento da fila (cabeça da lista encadeada) sem desenfileirar!*/
int front (Queue *q) {
   Queue *aux = q;
   
   while(aux->next != NULL){
      aux = aux->next;
   }
   
   return aux->info;
}

/*Função para testar se uma fila está vazia!*/
int empty_queue (Queue *q) {
   if(q == NULL) {return 1;}
   else {return 0;}
}

void print_queue(Queue *q){
   Queue *v;

   printf("Fila = ");
   for(v = q; v != NULL; v = v->next){
      printf("%d ", v->info);
   }
   printf("\n");
}