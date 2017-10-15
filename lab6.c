#include <stdio.h>

int main (void) {

	int a = 0;
	int times[6];								/*declare an array with 6 slots*/
	int counter = 0;

	for (a = 0; a < 6; a++) {						/*assign zeros to all of the numbers in the array*/
		times[a] = 0;
	}	

	while (1) {								/*forever loop to repeat program over and over again until the user breaks it*/
		int input;
 
		printf("What do you want to do?\n [1] Schedule an appointment.\n [2] Cancel an appointment.\n [3] List the appointments.\n [4] Quit.\n");	/*display menu for user to select options*/

		scanf("%d", &input);						/*receive input from user to execute different parts of program*/
	
		if (input == 1) {						/*booking appointments option*/
			int i;
		
			if (counter == 6) {					/*checks if there are any appointment slots left*/
                		printf("Sorry, there are no appointment slots left.\n");
                	}
		
			else {							/*makes appointments if there are still slots left*/
				for (i = 0; i < 6; i++) {
					int starttime;
					int endtime;

					if (times[i] == 0) {
						times[i] = i + 1;
						starttime = i + 1;
						endtime = i + 2; 
						printf("Your appointment is booked from %dpm to %dpm! Your appointment ID is %d. Please remember this number in case you want to make any changes to your appointment time at a later time.\n", starttime, endtime, times[i]);
						counter++;			/*counts how many appointments there are*/
						break;
					}
				}

			}
		}
	
		else if (input == 2) {						/*cancelling appoitnments option*/
			int id;

			printf("What is your appointment ID?\n");

			scanf("%d", &id);

			if (times[id - 1] == id) {				/*cancels the appointment*/
				times[id - 1] = 0; 
				printf("Your appointment has been cancelled.\n");
				counter--;					/*decreases number of appointments since user cancelled one*/
			}

			else {							/*in case the appointment ID that user inputs does not exist*/
                		printf("There are no such appointments.\n");
			}
				
		}

		else if (input == 3) {						/*display all existing appointments option*/
			printf("There are %d scheduled for today.\nThe appointments scheduled today are at:\n", counter);
		
			int p;
			int stime;
			int etime;

			for (p = 0; p < 6; p++) {				/*displays all existing appointments*/
				if (times[p] != 0) {
					stime = p + 1;
					etime = p + 2;
					printf("%dpm to %dpm\n", stime, etime);
				}
			
				else {						/*show that there is no appointment for that certain time slot*/
					stime = p + 1;
					etime = p + 2;
					printf("No %dpm to %dpm appointment!\n", stime, etime);
				}
			}
		}

		else {								/*breaks the forever loop if user enters any other number*/
			break;
		}

	}

	return 0;

}
