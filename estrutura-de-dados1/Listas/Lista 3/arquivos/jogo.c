#include "pilha.h"

int main () {

   Pilha *player1, *player2;
   int i, n1, n2;

   /*Create and fill stacks
   ========================================================================*/
   player1 = create_stack(20);
   player2 = create_stack(20);

   srand(time(NULL));

   fill_stack(player1);
   fill_stack(player2);
   /*=======================================================================*/

   printf("\nPlayer 1: \n");
   print_pilha(player1);
   printf("\nPlayer 2: \n");
   print_pilha(player2);
      

   /*Playing the game
   =========================================================================*/
   while(!empty_stack(player1) && !empty_stack(player2)){
      printf("\nPlayer 1: \n");
      print_pilha(player1);
      printf("\nPlayer 2: \n");
      print_pilha(player2);
      
      n1 = pop(player1);
      n2 = pop(player2);
      
      if(n1 > n2){
         for(i = 0; i < n1-n2; i++){
            if(!empty_stack(player1)){ 
               push(player2, pop(player1));
            }      
         } 
      }
      else if(n2 > n1){
         for(i = 0; i < n2-n1; i++){
            if(!empty_stack(player2)){
               push(player1, pop(player2));
            }       
         } 
      }
      
      sleep(3);
      //system("clear");
   }
   /*========================================================================*/


   /*Declaring winner
   ==========================================================================*/
   if(empty_stack(player1)) printf("\nWinner : Player 1\n");
   else printf("\nWinner : Player 2\n");

   destroy_stack(player1);
   destroy_stack(player2);

   return 0;
   /*======================================================================*/
}

