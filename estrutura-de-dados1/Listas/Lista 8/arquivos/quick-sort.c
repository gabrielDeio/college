#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (vetor[i] < vetor[i+1]) {
       return 0;
    }
  }
  return 1;
}

void Imprimir (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}


int Particione(int *vetor, int esq, int dir){
  int pivo = vetor[dir]; 
  int i = esq-1 , j, aux;

  for(j = esq; j < dir; j++){
    if(vetor[j] >= pivo){
      i++;
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
    }
  }

  aux = vetor[i+1];
  vetor[i+1] = vetor[dir];
  vetor[dir] = aux;

  return i+1;
}

void QuickSort (int *vetor, int esq, int dir) {
  int pivo;
  
  if(esq < dir){
    pivo = Particione(vetor, esq, dir);
    QuickSort(vetor, esq, pivo-1);
    QuickSort(vetor, pivo+1, dir);
  }
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   int tamanho = 1000000;
   int *vetor = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      vetor[i] = rand() % (tamanho+1);
   }
   Imprimir (vetor, tamanho);
   start = clock();
   QuickSort (vetor, 0, tamanho-1);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   //printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
   if (!Verifica_Ordenacao(vetor, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   }
   Imprimir (vetor, tamanho);
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
   free (vetor);
   return 0;
}

/*Tempos de execução ordem crescente:
  10 - 0.0sec
  100 - 0.0sec
  1000- 0.0sec
  10000- 0.0sec
  100000- 0.02sec
  1000000- 0.22sec
  ######################################################
  
  Tempos de execução em ordem decrescente:
  10 - 0.0sec
  100 - 0.0sec
  1000- 0.0sec
  10000- 0.0sec
  100000- 0.02sec
  1000000- 0.21
   */