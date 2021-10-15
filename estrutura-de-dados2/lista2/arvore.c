#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 1 - pré-ordem ====
void print_pre_ordem(Arvore *a){
   printf("%c\n", a->info);
	if(a->esq != NULL) print_pre_ordem(a->esq);
	if(a->dir != NULL) print_pre_ordem(a->dir);

}	


//========= Exercício 1 - in-ordem ====
void print_in_ordem(Arvore *a){
	if(a->esq != NULL) print_in_ordem(a->esq);
   printf("%c\n", a->info);
	if(a->dir != NULL) print_in_ordem(a->dir);
  
}

//========= Exercício 1 - pós-ordem ====
void print_pos_ordem(Arvore *a){
   if(a->esq != NULL) print_pos_ordem(a->esq);
   if(a->dir != NULL) print_pos_ordem(a->dir);
   printf("%c\n", a->info);
}

//========= Exercício 2 - pertence ====
int pertence_arv(Arvore *a, char c){
   if(a->info != c) pertence_arv();
}

//========= Exercício 3 - conta nós ====


//========= Exercício 4 - calcula altura ====



//========= Exercício 5 - conta folhas ====



int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

   //print_pre_ordem(a);
   //print_in_ordem(a);
   print_pos_ordem(a);
   arv_libera (a);

   return 0;
}
