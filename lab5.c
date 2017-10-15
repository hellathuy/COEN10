#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
   srand((int) time(NULL));
   int correct = 0; /*declare a variable for the number of correct answers*/ 
   int ans; /*declare a variable for the correct answer*/ 
   int i = 0; 
 
   while (i < 10) {		/*loop to run the game 10 times*/
      int x = rand() % 13;      /*assign random numbers to x an y*/
      int y = rand() % 13; 
      
      printf("%d *", x);
      printf(" %d\n", y);
      scanf("%d", &ans);
      
      if (x * y == ans) {	/*if statement for correct input*/
	 printf("You got the answer right!\n");
	 correct++; 		/*counts how many correct responses there are*/
      }
      
      else {			/*else statement for wrong input*/
	 int c = x * y;
	 printf("You got the answer wrong. The right answer is %d.\n", c);
      }
      
      i++;
   }

   double p = ((double)correct/10)*100;		/*calculates percentages*/
   
   printf("You got %.0f%% of the questions right!\n", p);
  
}


