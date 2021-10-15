#include "grafo.h"

/*Função principal.*/
int main () {

   int v = 5; /*Número de vértices*/

   Grafo* g = criar_grafo (v);

   adicionar_aresta (0, 4, g);
   adicionar_aresta (0, 1, g);
   adicionar_aresta (1, 4, g);
   adicionar_aresta (1, 3, g);
   adicionar_aresta (1, 2, g);
   adicionar_aresta (2, 3, g);
   adicionar_aresta (3, 4, g);
   
   imprimir_grafo (g);

   printf("# vertices = %d, # arestas = %d\n", g->v, g->e);

   destruir_grafo (g);      

   return 0;
}

