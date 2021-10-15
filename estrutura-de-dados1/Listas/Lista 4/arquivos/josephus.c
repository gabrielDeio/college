#include "queue.h"

Queue* kill(Queue *q, int passo);

int main () {
  int i, passo, n_competidores;
  printf("Josephus - digite o passo da morte e numero de competidores: ");
  scanf("%d %d", &passo, &n_competidores);
  Queue *q = create_queue ();
  

  for(i = 1; i <= n_competidores; i++){
    q = enqueue(q, i);
  }

  print_queue(q);

  while(q->next != NULL){
    q = kill(q, passo);
    print_queue(q);
  }

  printf("\nSobrevivente : %d\n", front(q));
  
  free_queue (q);
  return 0;
}

Queue* kill(Queue *q, int passo){
  Queue *aux = q, *prv = NULL;
  int i;

  for(i = 1; i < passo; i++){
    aux = q;
    while(aux->next != NULL){
      prv = aux;
      aux = aux->next;
    }
    aux->next = q;
    q = aux;
    prv->next = NULL;
  }

  print_queue(q);
  q = dequeue(q);

  return q;
}