/*
 *Name: Thuy Le
 *Date:	11/5/15
 *File: lab7.c
 *
 *Description: The same program as lab 6 except instead of if else statements, used switch function. 
 *          
 */

#include <stdio.h>
#include <string.h>

char schd[6][20];                               	/*declare an array with 6 slots with 20 characters in each slot*/
int counter = 0;

int schedule();
int cancel();
int list();

int main (void) {

	int a = 0;
	
	for (a = 0; a < 6; a++) {			/*assign zeros to all of the numbers in the array*/
		schd[a][0] = 0;
	}

	while (1) {					/*forever loop to repeat program over and over again until user breaks it*/
		int input;

		printf("What do you want to do?\n [1] Schedule an appointment.\n [2] Cancel an appointment.\n [3] List the appointments.\n [4] Quit.\n");

                scanf("%d", &input);                    /*receive input from user to execute different parts of program*/

		switch(input) {
			case 1:
				schedule();		/*calls the schedule function*/
				break;
			case 2:
				cancel();		/*calls the cancel function*/
				break;
			case 3:
				list();			/*calls the list function*/
				break;
			case 4:
				return 0;		/*exits out of the program*/
		}
	}
}	

int schedule () {					/*function to schedule an appointment*/
	int i;
	
        if (counter == 6) {				/*checks if there are any appointment slots left*/
		printf("Sorry, there are no appointment slots left.\n");
	}

	else {						/*books appointment if there are still slots left*/
		for (i = 0; i < 6; i++) {
			int starttime;
			int endtime;

			if (schd[i][0] == '\0') {
                        	printf("What is your name?\n");
                        	scanf("%s", &schd[i][0]);
				starttime = i + 1;
				endtime = i + 2;
				printf("Thank you, %s. Your appointment is booked from %dpm to %dpm!\n", schd[i], starttime, endtime);
				counter++;		/*counts how many appointments there are*/
				break;
                        }
		}
	}

	return 0;
}

int cancel() {						/*function to cancel an appointment*/
	int c;
	int m;
	char id[20];

	printf("Please enter your name.\n");
	scanf("%s", id);

	for (c = 0; c < 6; c++) {
		if (strcmp(id, schd[c]) == 0) {		/*check array for name and cancels that appointment*/
			schd[c][0] = '\0';
			printf("Your appointment has been successfully cancelled.\n");
		
			for (m = c + 1; m < 6; m++) { 	/*shifts appointments up*/
				strcpy(schd[m - 1], schd[m]);
			}

			schd[counter - 1][0] = '\0';
			counter--;

			break;
		}
		
		else if (c == 5) {			/*if there are no appointments for that name*/
			printf("There are no appointments scheduled under that name.\n");
		}	
	}

	return 0;
}

int list() {						/*function to list all appointments*/
	printf("There are %d appointments scheduled for today.\nThe appointments scheduled today are at:\n", counter);

	int p;
	int stime;
	int etime;

	for (p = 0; p < 6; p++) {			/*lists busy appointments*/
		if (schd[p][0] != '\0') {
			stime = p + 1;
			etime = p + 2;
			printf("%dpm to %dpm..........%s\n", stime, etime, schd[p]);
		}

		else {					/*lists free appointments*/
			stime = p + 1;
			etime = p + 2;
			printf("%dpm to %dpm..........FREE\n", stime, etime);
		}
	}

	return 0;
}
				
				

	


