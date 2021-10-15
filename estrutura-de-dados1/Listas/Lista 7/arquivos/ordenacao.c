#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort (int *vetor, int tamanho) {
    int i, j, tam = tamanho,        //250.000 = 236.29
    aux;                            //100.000 = 37.75
                                    //10.000 = 0.35
    for(i = 0; i < tamanho; i++){   //1000 = 0.01
      for(j = 0; j < tam - 1; j++){
        if(vetor[j] > vetor[j+1]){
          aux = vetor[j+1];
          vetor[j+1] = vetor[j];
          vetor[j] = aux;
        }
      }
      tam--;
    }
}
 
void SelectionSort (int *vetor, int tamanho) {
    int inicio = 0, i, j,                   //250.000 = 103.48
    posicao = 0, aux;                       //100.000 = 16.56
                                            //10.000 = 0.18   
    for(i = 0; i < tamanho - 1; i++){       //1000 = 0.01
      for(j = inicio; j < tamanho; j++){
        if(vetor[j] < vetor[posicao]){
          posicao = j;
        }      
      }
      aux = vetor[i];
      vetor[i] = vetor[posicao];
      vetor[posicao] = aux; 
      inicio++;
      posicao = inicio;
    }
}

void InsertionSort (int *vetor, int tamanho) {
    int chave = 1, i, j, 
    elemento, posicao;

    for(i = 0; i < tamanho; i++){
      elemento = vetor[chave];
      posicao = chave;
      for(j = chave - 1; j >= 0; j--){
        if(elemento < vetor[j]){
          vetor[posicao] = vetor[j];
          posicao--;
        }
      }
      vetor[posicao] = elemento;
      chave++;
      
    } 
}

void Imprimir (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (A[i] > A[i+1]) {
       return 0;
    }
  }
  return 1;
}


int main () {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i, j = 0;

  int tamanho = 250000;

  int *v1 = (int *)malloc(tamanho * sizeof(int));
  int *v2 = (int *)malloc(tamanho * sizeof(int));
  int *v3 = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++) {
     v1[i] = rand() % (tamanho+1);
     v2[i] = rand() % (tamanho+1);
     v3[i] = rand() % (tamanho+1);
  }  

  /*
  start = clock();
  Imprimir(v1, tamanho);
  BubbleSort (v1, tamanho);
  Imprimir(v1, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (BubbleSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v1, tamanho)) {
     printf("Erro: a ordenação do BubbleSort não está correta!\n");
  }*/

  
  start = clock();
  Imprimir(v2, tamanho);
  SelectionSort (v2, tamanho);
  Imprimir(v2, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (SelectionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v2, tamanho)) {
     printf("Erro: a ordenação do SelectionSort não está correta!\n");
  } 

  /*
  start = clock();
  Imprimir(v3, tamanho);
  InsertionSort (v3, tamanho);
  Imprimir(v3, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (InsertionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v3, tamanho)) {
     printf("Erro: a ordenação do InsertionSort não está correta!\n");
  } */
 
  free (v1);
  free (v2);
  free (v3);

  return 0;
}

