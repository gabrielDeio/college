#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct _no {
   int id;           /*Identificador armazenado no nó. */
   struct _no *next; /*Próximo nó na lista encadeada. */
} No;

/*Estrutura de Grafo representado por uma lista de adjacências: */
typedef struct {
   int e; /* Quantidade de arestas. */
   int v; /* Quantidade de vértices. */
   No **list; /*Vetor com as listas de adjacências de cada vértice. */
} Grafo;

/*Função para criar um grafo representado como uma lista de adjacências com {V} vértices de tamanho.*/
Grafo* criar_grafo (int v);

/*Função para destruir um grafo construído através de uma representação por lista de adjacências.*/
void destruir_grafo (Grafo *g);

/*Função para imprimir um grafo construído através de uma representação por lista de adjacências.*/
void imprimir_grafo (Grafo *g);

/*Função para adicionar a aresta (ligação) entre os vértices {u,v} e {v,u} no grafo {G}.*/
void adicionar_aresta (int u, int v, Grafo *g);


