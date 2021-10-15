#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*função para retornar qual string está em uma posição maior ou menor.*/
int ehMaiorStr(char str1[], char str2[])
{
   int i = 0;

   while(str1[i] != '\n' && str2[i] != '\n'){
      if((int)str1[i] > (int)str2[i]) return 1;
      else if((int)str1[i] < (int)str2[i]) return 0;
      else i++;
   }
}

/*Função para contar o número de linhas de um arquivo.*/
int conta_linhas (FILE *arq) {
  int linhas = 0;
  if (arq == NULL) {
    return linhas; 
  }
  while (!feof(arq)) {
    char c;
    fscanf(arq, "%c", &c);
    if (c == '\n') {
      linhas++;
    }
  }
  rewind(arq);
  return (linhas-1);
}

/*Busca sequêncial (linear).*/
int busca_linear (char **dicionario, int linhas, char palavra[]) {
   int i;

   for(i = 0; i < linhas; i++){
      if(strcmp(dicionario[i], palavra) == 0) return i;
   }

   return -1;
}

/*Busca binária iterativa.*/
int busca_binaria_itr (char **dicionario, int linhas, char palavra[]) {
   int indiceIni = 0, indiceFim = linhas - 1, aux;

   while(indiceFim >= indiceIni){
      aux = (indiceIni+indiceFim) / 2;
      if(strcmp(dicionario[aux], palavra) == 0) return aux;
      else if(ehMaiorStr(dicionario[aux], palavra)) indiceFim = aux - 1;
      else indiceIni = aux + 1;
   }

   return -1;
}

/*Busca binária recursiva.*/
int busca_binaria_rec (char **dicionario, int esq, int dir, char palavra[]) {
   int aux = (esq + dir) / 2;

   if(!strcmp(dicionario[aux], palavra)) return aux;
   else if(esq >= dir) return -1;
   else if(ehMaiorStr(dicionario[aux], palavra)) return busca_binaria_rec(dicionario, esq, aux - 1, palavra);
   else return busca_binaria_rec(dicionario, aux+1, dir, palavra);
   


}

/*Função principal.*/
int main (int argc, char *argv[]) {

   int nbuscas = 1;

   int p;

   clock_t start, end;
  
   double elapsed_time;

   /*Abrindo o arquivo:*/
   FILE *arq = fopen("palavras.txt","r");

   /*Contando o número de linhas do arquivo:*/
   int linhas = conta_linhas(arq);
   
   /*Alocando memória para armazenar as palavras:*/
   char **dicionario = (char **)malloc(linhas * sizeof(char *));
   int i;
   for (i = 0; i < linhas; i++) {
      dicionario[i] = (char *)malloc(256 * sizeof(char));
   }
  
   /*Lendo as dicionario do arquivo:*/
   i = 0;
   while (!feof(arq)) {
      fscanf(arq, "%s", dicionario[i]);     
      i++;
   }


   /*Lendo a palavra a ser pesquisada:*/
   printf("Pesquise a palavra: ");
   char palavra[256]; 
   scanf("%s", palavra);

   /*Executando os algoritmos busca sequêncial:*/
   for (i = 0; i < nbuscas; i++){
      p = busca_linear (dicionario, linhas, palavra);
      if (p != -1){
         printf("Achei a palavra %s no dicionário na posição %d!\n", palavra, p);
      }
      else {
         printf("Não achei a palavra %s no dicionário!\n", palavra);
      }
   }   

   /*------------------------------------------------*/
   /*Executando os algoritmo busca binária iterativo:*/
   for (i = 0; i < nbuscas; i++){
      p = busca_binaria_itr (dicionario, linhas, palavra);
      if (p != -1){
         printf("Achei a palavra %s no dicionário na posição %d!\n", palavra, p);
      }
      else {
         printf("Não achei a palavra %s no dicionário!\n", palavra);
      }
   }  

   /*------------------------------------------------*/
   /*Executando o algoritmo de busca binária recursivo:*/
   for (i = 0; i < nbuscas; i++){
      p = busca_binaria_rec (dicionario, 0, linhas-1, palavra);
      if (p != -1){
         printf("Achei a palavra %s no dicionário na posição %d!\n", palavra, p);
      }
      else {
         printf("Não achei a palavra %s no dicionário!\n", palavra);
      }
   }   

   /*------------------------------------------------*/
   /*Liberando a memória:*/
   for (i = 0; i < linhas; i++) {
      free(dicionario[i]);
   }
   free(dicionario);
   fclose(arq);
   return 0;
}

