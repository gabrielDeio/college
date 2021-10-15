#include "lista.h"

int conta_nos_itr (Lista* lista) {
   int i = 1;

   while(lista->next != NULL){
      i++;
      lista = lista->next;
   }

   return i;
}

int conta_nos_rec (Lista* lista) {
   int i = 1;

   if(lista->next == NULL){
      return i;
   }
   else{
      i = conta_nos_rec(lista->next);
      return i+1;
   }
}

int procura_itr (Lista* lista, int elemento) {
   int i = 0;
   
   while(lista->next != NULL && lista->info != elemento){
      lista = lista->next;
      i++;      
   }

   
   if(i != 0)  return i;
   else return -1;
}

int procura_rec (Lista* lista, int elemento) {
   int i = 0;

   if(lista->next != NULL && lista->info != elemento){
      i = procura_rec(lista->next, elemento);
      return i+1;
   }

   return i;
}

int lista_max_itr (Lista* lista) {
   int max = lista->info;

   while(lista->next != NULL){
      if(lista->info < lista->next->info){
         max = lista->next->info;
      }
      
      lista = lista->next;
   }

   return max;
}

/*Você pode usar outras funções aqui se achar necessário!*/
int lista_max_rec (Lista* lista) {
   int max = lista->info;

   if(lista->next != NULL){
      max = lista_max_rec(lista->next);
      if(max < lista->next->info) return lista->next->info;
      else return max;
   }

   return max;
}

int lista_soma_itr (Lista* lista) {
   int sum = lista->info;

   while(lista->next != NULL){
      lista = lista->next;
      sum += lista->info;
   }

   return sum;
}

int lista_soma_rec (Lista* lista) {
   int sum = 0;

   if(lista->next != NULL){
      sum = lista_soma_rec(lista->next);
      return sum + lista->info;
   }
}

/*Você pode usar outras funções aqui se achar necessário!*/
void imprimir_invertida_itr (Lista* lista) {
   Lista *aux = lista;
   int i, c = conta_nos_rec(lista);

   for(i = 0; i < c; i++){
      lista = troca_posicoes(lista);
   }

}

void imprimir_invertida_rec (Lista* lista) {
   if(lista != NULL){
      imprimir_invertida_rec(lista->next);
      printf("%d ", lista->info);
   }
}

/*Função para criar uma lista encadeada vazia!*/
Lista* criar_lista (void) {
   return NULL;
}

/*Função para inserir um elemento na cabeça de uma lista encadeada!*/
Lista* inserir (Lista *lista, int elem) {
   Lista *novo =(Lista*)malloc(sizeof(Lista));
   novo->info = elem;
   novo->next = lista;
   return novo;
}

/*Função para imprimir uma lista encadeada!*/
void imprimir_lista (Lista *lista) {
   Lista *v; /*var. para percorrer a lista*/
   printf("Lista: ");
   for (v = lista; v != NULL; v = v->next) {
      printf("%d ", v->info);
   }
   printf("\n");
}

/*Função para desalocar uma lista encadeda!*/
void destruir_lista (Lista *l) {
  Lista *aux;
  while (l != NULL) {
    aux = l->next;
    free(l);
    l = aux;
  }
}

Lista* troca_posicoes(Lista *lista){
   Lista *prv, *aux = lista;
   while(aux->next != NULL){
      prv = aux;
      aux = aux->next;
   }

   printf("%d ", aux->info);

   aux->next = lista;
   lista = aux;
   prv->next = NULL;
   

   return lista;
}