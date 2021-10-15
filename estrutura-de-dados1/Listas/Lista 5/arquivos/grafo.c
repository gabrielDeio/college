#include "grafo.h"

/*Função para criar um grafo representado como uma lista de adjacências com {V} vértices de tamanho.*/
Grafo* criar_grafo (int vertices) {
   int i;
   Grafo *g = (Grafo*)malloc(sizeof(Grafo));
   g->v = vertices;
   g->e = 0;

   
   g->list = (No**)malloc(sizeof(No*)*vertices);
   
   for(i = 0; i < vertices; i++){
      g->list[i] = NULL;
   }


   return g;  
}

/*Função para destruir um grafo construído através de uma representação por lista de adjacências.*/
void destruir_grafo (Grafo *g) {
   int i;
   Grafo *aux = g;

   for(i = 0; i < g->v; i++){
      while(g->list[i] != NULL){
         aux->list[i] = g->list[i]->next;
         free(g->list[i]);
         g->list[i] = aux->list[i];   
      }
      free(g->list[i]);
   }
   
   free(g->list);
   free(g);
}

/*Função para imprimir um grafo construído através de uma representação por lista de adjacências.*/
void imprimir_grafo (Grafo *g) {
   int i;
   Grafo *aux = g;

   for(i = 0; i < g->v; i++){
      printf("%d -> ", i);
      while(aux->list[i]!= NULL){
         printf("%d ", aux->list[i]->id);
         aux->list[i] = aux->list[i]->next;
      }
      printf("\n");
   }
}

/*Função para adicionar a aresta (ligação) entre os vértices {u,v} e {v,u} no grafo {G}.*/
/*Adicione um novo vértice sempre no início da lista encadeada do respectivo vértice.*/
/*Você pode dividir essa função em duas se achar necessário!*/
void adicionar_aresta (int u, int v, Grafo *g) {
   No *novo1 = (No*) malloc(sizeof(No));
   novo1->id = v;
   novo1->next = g->list[u];
   g->list[u] = novo1;
   
   No *novo2 = (No*) malloc(sizeof(No));
   novo2->id = u;
   novo2->next = g->list[v];
   g->list[v] = novo2;

   g->e += 1;         
}
