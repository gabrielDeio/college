#include "pilha.h"

/*Função para criar uma pilha!*/
Pilha* create_stack (int tam) {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (int *)malloc(tam * sizeof(int));
  return p;
}


void print_pilha(Pilha *p){
  int i;

  for(i = 0; i < p->topo; i++){
    printf("%d\n", p->vetor[i]);
  }
}

void fill_stack(Pilha *p){
  int i;
  
  for(i = 0; i < p->tam/2; i++){
    push(p, rand()%6);
  }
}

/*Função para empilhar um elemento!*/
void push (Pilha *p, int elem) {
  if (full_stack(p)) {
    printf ("Pilha cheia\n");
    exit(1);
  }
  p->vetor[p->topo] = elem;
  p->topo++;
}

/*Função para desempilhar um elemento!*/
int pop (Pilha *p) {
  if (empty_stack(p)) {
    printf ("Pilha vazia\n");
    exit(1);
  }
  p->topo--;
  return p->vetor[p->topo];
}

/*Função para liberar a memória alocada.*/
int empty_stack (Pilha *p) {
  return (p->topo ==  0);
}

/*Funão para testar se a pilha está cheia!*/
int full_stack (Pilha *p) {
  return (p->topo == p->tam);
}

/*Funão para testar se a pilha está vazia!*/
void destroy_stack (Pilha *p) {
  free(p->vetor);
  free(p);
}

