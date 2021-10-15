#include <string.h>
#include "stack.h"

int main () {

   char *seq = "() ()"; 	

   int i = 0;
    
   Stack *p = create_stack(strlen(seq));

   while (seq[i] != '\0') {
      if ( (seq[i] == '(') || (seq[i] == '[') ) {
	 p = push (p, seq[i]);     
      }
      else if (seq[i] == ')') {
	 if (empty_stack(p) || top(p) != '(') {
            printf("mal formada\n");
            return 0; 	    
	 }	 
	 p = pop (p);
      }
      else if (seq[i] == ']') {
	 if (empty_stack(p) || top(p) != '[') {
            printf("mal formada\n");
            return 0; 	    
	 }	 
	 p = pop (p);
      } 
      i++;
   }
   if (empty_stack(p)) {
      printf("bem formada\n"); 
   }
   else {
      printf("mal formada\n"); 
   }
   return 0;
}

