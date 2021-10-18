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
   	if(a == NULL) printf("Arvore Vazia!!\n");
	else{
		printf("%c\n", a->info);
		if(a->esq != NULL) print_pre_ordem(a->esq);
		if(a->dir != NULL) print_pre_ordem(a->dir);
	}
}	


//========= Exercício 1 - in-ordem ====
void print_in_ordem(Arvore *a){
	if(a == NULL) printf("Arvore Vazia!!\n");
	else{	
	
		if(a->esq != NULL) print_in_ordem(a->esq);
       		printf("%c\n", a->info);
		if(a->dir != NULL) print_in_ordem(a->dir);
  	}
}

//========= Exercício 1 - pós-ordem ====
void print_pos_ordem(Arvore *a){
   if(a == NULL) printf("Arvore Vazia!!\n"); 
   else{
	if(a->esq != NULL) print_pos_ordem(a->esq);
   	if(a->dir != NULL) print_pos_ordem(a->dir);
   	
	printf("%c\n", a->info);
   }	 		
}

//========= Exercício 2 - pertence ====
int pertence_arv(Arvore *a, char c){
	if(a == NULL) return -1;
	else{
		int answer = 0;

       		if(a->esq != NULL && answer != 1) { 
			answer = pertence_arv(a->esq, c);
		}	
		if(a->dir != NULL && answer != 1){ 
			answer = pertence_arv(a->dir, c);
		}

		return a->info == c || answer == 1;
	}	
}

//========= Exercício 3 - conta nós ====
int conta_nos(Arvore *a){
	if(a == NULL) return -1;
	else{	
		int count = 1;

		if(a->esq != NULL){
			count += conta_nos(a->esq);	
		}
		if(a->dir != NULL){
			count += conta_nos(a->dir);
		}
	
		return count;
	}	
}	

//========= Exercício 4 - calcula altura ====
int calcula_altura_arvore(Arvore *a){
	if(a == NULL) return -1;
	else{
		int lh = calcula_altura_arvore(a->esq);
		int rh = calcula_altura_arvore(a->dir);
	
		if(lh < rh) return rh + 1;
		else return lh + 1;
	}	
		
}	


//========= Exercício 5 - conta folhas ====
int conta_nos_folhas(Arvore *a){
	if(a == NULL) return -1;
	else{	
		int qtdFolha = 0;

		if(a->esq != NULL) qtdFolha += conta_nos_folhas(a->esq);
		if(a->dir != NULL) qtdFolha += conta_nos_folhas(a->dir);

		if(a->esq == NULL && a->dir == NULL) qtdFolha++;

		return qtdFolha;
	}	
}	


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

   	
   	printf("\n=====Exercicio 1===========\n");
	printf("\nPre-Ordem:\n");
   	print_pre_ordem(a);
	printf("\nIn-Ordem:\n");	
	print_in_ordem(a);
	printf("\nPos-Ordem:\n");
   	print_pos_ordem(a);
	printf("\n################################\n\n");
	
	printf("\n=====Exercicio 2=============\n");
       	if (pertence_arv(a, 'e')) printf("A informacao se encontra na arvore!\n");
	else printf("A informacao nao se encontra na arvore!\n");
	printf("\n################################\n\n");


	printf("\n=====Exercicio 4==============\n");
	printf("Qtd de nos = %d\n", conta_nos(a));
	printf("\n##############################\n\n");

	printf("\n=====Exercicio 5==============\n");
	printf("Altura = %d\n", calcula_altura_arvore(a));
	printf("\n################################\n\n");
	
	printf("\n=====Exercicio 6==============\n");
	printf("Qtd de folhas = %d\n", conta_nos_folhas(a));
	printf("\n#################################\n\n");
		
	arv_libera (a);

   return 0;
}
