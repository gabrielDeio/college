#include "deck.h"

Deck* createDeck () {
  return NULL;
}

/*Função que retorna a coordenada armazenada na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getFront (Deck *d) {
   if(d != NULL) return d->p;
   else{
      printf("Lista Vazia!!\n");
      exit(1);
   }
}

/*Função que retorna a coordenada armazenada na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getRear (Deck *d) {
   if(d == NULL){ 
      printf("Lista vazia!!");
      exit(1);
   }   
   else while(d->next != NULL){d = d->next;}

   return d->p;
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
   Deck *novo = (Deck*)malloc(sizeof(Deck));
   novo->p.x = p.x;
   novo->p.y = p.y;
   novo->next = d;
   novo->prev = NULL;
   if(d != NULL)  d->prev = novo;
   field[p.x][p.y] = '*';   

   return novo;
}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   Deck *novo = (Deck*)malloc(sizeof(Deck));
   novo->p.x = p.x;
   novo->p.y = p.y;

   if(d != NULL){
      Deck *aux = d; 
      while(aux->next != NULL){aux = aux->next;}

      novo->prev = aux;
      aux->next = novo;
      novo->next = NULL;
      field[p.x][p.y] = '*'; 
      
      return d;
   }
   else{
      d = novo;
      d->next = NULL;
      d->prev = NULL;
      d->p.x = p.x;
      d->p.y = p.y; 
      field[p.x][p.y] = '*'; 

      return d;
   }
   
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteFront (Deck *d, char field[][SIZE]) {
   if(d == NULL){
      printf("Lista Vazia!!\n");
      exit(1);
   }
   else{
      Deck *aux = d->next;
      field[d->p.x][d->p.y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
      if(d->next != NULL){
         d->next->prev = NULL;
         free(d);
         d = aux;
      }
      
      return d;   
   }

}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteRear (Deck *d, char field[][SIZE]) {
   if(d == NULL){
      printf("Lista vazia!!\n");
      exit(1);
   }
   else{
      Deck *aux = d;
      while(aux->next != NULL){
         aux = aux->next;
      }
      aux->prev->next = NULL;
      field[aux->p.x][aux->p.y] = ' ';
      free(aux);
      return d;  
   }
  
}


