#include "queue.h"

int main () {
   Fila *queue1, *queue2, *queue3;
   int i, qtd, element;

   queue1 = create_queue(10);
   queue2 = create_queue(10);
   queue3 = create_queue(10);

   
   for(i = 1; i < 10; i++){
      enqueue(queue1, i);
      enqueue(queue2, i);
      enqueue(queue3, i);
   }

   srand(time(NULL));

   do{
      qtd = 1 + (rand()%9);

      for(i = 0; i < qtd; i++){
         element = dequeue(queue1);
         enqueue(queue1, element);
      }
      print_first(queue1);
      
      qtd = 1 + (rand()%9);
      
      for(i = 0; i < qtd; i++){   
         element = dequeue(queue2);
         enqueue(queue2, element);
      }
      
      print_first(queue2);
      
      qtd = 1 + (rand()%9);
      
      for(i = 0; i < qtd; i++){   
         element = dequeue(queue3);
         enqueue(queue3, element);
      }
      
      print_first(queue3);
      printf("\n");

   }while(queue1->vetor[queue1->ini] != queue2->vetor[queue2->ini] || queue2->vetor[queue2->ini] != queue3->vetor[queue3->ini
   ]);

   printf("\nGanhou!!\n");
   /*TERMINAR*/
   /*Criar três filas para simular uma máquina caça-níqueis!*/
   /*Obrigatório usar as funções vistas em aula!*/
   /*Pode criar funções na TAD fila caso seja necessário, por exemplo, mostrar primeiro elemento da fila!*/
   /*Pode criar funções adicionais para girar uma fila!*/
   /*...*/

   return 0;
}
