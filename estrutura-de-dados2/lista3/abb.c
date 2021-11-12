#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {  
   int info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}



//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
	if(a == NULL){
		a = (Arvore*)malloc(sizeof(Arvore));
		a->info = v;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if(v < a->info) a->esq = inserir(a->esq, v);
	else a->dir = inserir(a->dir, v);	

	return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
	if(a == NULL) return NULL;
   	else{
		if(a->info > v) a->esq = remover(a->esq, v);
		else if(a->info < v) a->dir = remover(a->dir, v);
		else{
			if((a->esq == NULL)&&(a->dir == NULL)){
				free(a);
				a = NULL;	
				
			}	
			else if(a->dir == NULL){
				Arvore *tmp = a;
				a = a->esq;
				free(tmp);
			}
			else if(a->esq == NULL){
				Arvore *tmp = a;
				a = a->dir;
				free(tmp);
			}
			else{
				Arvore *tmp = a->esq;
				while(tmp->dir != NULL){tmp = tmp->dir;}
				a->info = tmp->info;
				tmp->info = v;
				a->esq = remover(a->esq, v);
			}	
	
		}
		return a;	
     	}		
	
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
	if(a == NULL) return 0;
     	else if(v < a->info) return buscar(a->esq, v);
	else if(v > a->info) return buscar(a->dir, v);
	else return 1; 
}


//========= Q2 - min =====
int min (Arvore *a){
	if(a == NULL) return 0;
	else if(a->esq != NULL) return min(a->esq);
	else return a->info;
}	

//========= Q2 - max =====
int max (Arvore *a){
	if(a == NULL) return 0;
	else if(a->dir != NULL) return max(a->dir);
	else return a->info;
}	


void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

//========Q5===================
void imprime_decrescente(Arvore *a){
	if(a == NULL) printf("Arvore Vazia!!\n");
	else {
		if(a->dir != NULL) imprime_decrescente(a->dir);
		if(a->esq != NULL){
			printf("%d ", a->info);
			imprime_decrescente(a->esq);
		}	
		else if(a->dir == NULL || a->esq == NULL) printf("%d ", a->info);
	}	
}	
//==========Q5=================

//==========Q6=================
int maior_ramo(Arvore *a){
	if(a == NULL) return 0;
	int ramoEsq = maior_ramo(a->esq);
	int ramoDir = maior_ramo(a->dir);
	int maior;
	if(ramoEsq > ramoDir) maior = ramoEsq;
	else maior = ramoDir;
	return a->info + maior;
}	

//===========Q6==================


//===========Q7==================
int ancestral(Arvore *a, int e1, int e2){
	if(a == NULL) return -1;
	if(buscar(a, e1) && buscar(a, e2)){
		int busca = ancestral(a->dir, e1, e2);
		if(busca == -1){
			busca = ancestral(a->esq, e1, e2);
		}

		if(busca == -1){
			return a->info;
		}

		return busca;	
	}

	return -1;	
}	
//=========Q7=====================


int main () {

	int i, element = 0;
	clock_t begin, end;

	Arvore *a = cria_arvore_vazia ();
	
	/*
  	do{
		printf("\nInsira um elemento(-1 para sair): ");
		scanf("%d", &element);
		if(element != -1){
			printf("%d\n", element);
			a = inserir(a, element);
		}	
	}while(element != -1);	*/
	
	a = inserir (a, 50);
	a = inserir (a, 30);
	a = inserir (a, 90);
	a = inserir (a, 20);
	a = inserir (a, 40);
	a = inserir (a, 95);
	a = inserir (a, 10);
	a = inserir (a, 35);
	a = inserir (a, 45);

	printf("\n");
	pre_order (a);	
	printf("\n");
	
	
	printf("\nInsira um elemento para remover: ");
	scanf("%d", &element);
	remover(a, element);
	//printf("%d\n", buscar(a, element));
	
	printf("\n");
	pre_order (a);	
	printf("\n");
	
	printf("Menor valor: %d\n", min(a));
	printf("Maior valor: %d\n", max(a));

	arvore_libera(a);	
	
//=========Q3==================
	a = cria_arvore_vazia();
	printf("\nInsercao de numeros sequenciais: \n");
	begin = clock();
	for(i = 0; i < 100000; i++) { a = inserir(a, i);}
	end = clock();
	printf("\n%d\n", buscar(a, 10000));
	printf("\nTempo de execucao: %lf\n", (double)(end - begin)/CLOCKS_PER_SEC);	
	//Inserção: 133.234375sec
	//Busca: < 0sec
//==========Q3================
	arvore_libera(a);
	a = cria_arvore_vazia();
//==========Q4================	
	srand(time(NULL));
	begin = clock();
	for(i = 0; i < 100000; i++){a = inserir(a, rand()%100000);}
	end = clock();
	printf("\n%d\n", buscar(a, 10000));
	printf("\nTempo de execucao: %lf\n", (double)(end - begin)/CLOCKS_PER_SEC);
	//Inserção: 0.109375sec
	//Busca: < 0sec	
//===========Q4=================

	//printf("\n");
	//imprime_decrescente(a);
	//printf("\n");
	printf("\nMaior ramo: %d\n", maior_ramo(a));
	printf("Ancestral = %d\n", ancestral(a, 10, 40));
	arvore_libera(a);
	
   	return 0;
}
