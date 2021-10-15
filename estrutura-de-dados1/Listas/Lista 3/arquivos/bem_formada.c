#include <string.h>
#include "pilha.h"

int main () {

   Pilha *stack1, *stack2;

   stack1 = create_stack(15);
   stack2 = create_stack(15);
   
   char *seq = "(]"; /*Suponha que a string esta armazenada em um string!*/	

   int i = 0, last_element = 1;
    
   /*TERMINAR!!!*/

   while (seq[i] != '\0') {
      printf ("%c\n", seq[i]);
      push(stack1, (int)seq[i]);
      i++;
   }

   //print_pilha(stack1);

   do{
     
      last_element = pop(stack1);

      if(last_element == 41 || last_element == 93){
         push(stack2, last_element);
      }
      
      else if(!empty_stack(stack2)){
         if(pop(stack2)/last_element != 1){
            printf("\nMal formada\n");
            last_element = 0;
         }
      }
      
      else{
         printf("\nMal formada!\n");
         last_element = 0;
      }
      }while(!empty_stack(stack1) && last_element != 0);

      if((empty_stack(stack1) && empty_stack(stack2)) && i >= 2) printf("\nBem formada!\n");
      else printf("\nMal formada!\n");

      destroy_stack(stack1);
      destroy_stack(stack2);
   

   return 0;
}

