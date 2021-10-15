#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct pilha {
  int topo; 
  int tam; 
  int *vetor; 
} Pilha;


Pilha* create_stack (int tam);

void fill_stack(Pilha *p);

void push (Pilha *p, int elem);

void print_pilha(Pilha *p);

int pop (Pilha *p);

int empty_stack (Pilha *p);

int full_stack (Pilha *p);

void destroy_stack (Pilha *p);
