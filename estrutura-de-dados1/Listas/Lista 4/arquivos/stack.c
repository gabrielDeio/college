#include "stack.h"

/*Função para criar uma pilha vazia (não criar nenhum nó, só devolver NULL)!*/
Stack* create_stack () {
   return NULL;
}

/*Função para liberar uma pilha nó por nó*/
void free_stack (Stack *s) {
   while(s != NULL){
      Stack *aux = s->next;
      free(s);
      s = aux;
   }
}

/*Função para empilhar um elemento (inserir na cabeça da lista encadeada)!*/
Stack* push (Stack *s, int elem) {
   Stack *new = (Stack*)malloc(sizeof(Stack));
   new->info = elem;
   new->next = s;

   return new; 
}

/*Função para desempilhar um elemento (remover da cabeça da lista encadeada)!*/
Stack* pop (Stack *s) {
   if(empty_stack(s)){
      printf("\nEmpty stack!!\n");
      exit(1);
   }
   else{
      Stack *prv = s;
      s = s->next;
      free(prv);
   }

   return s;
}

/*Função para retornar o elemento no topo da pilha (cabeça da lista encadeada) sem desempilhar!*/
int top (Stack *s) {
   return s->info;
}

/*Função para testar se uma pilha está vazia!*/
int empty_stack (Stack *s) {
   if(s == NULL) return 1;
   else return 0;
}
