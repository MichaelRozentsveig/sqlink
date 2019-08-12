#include <stdio.h>
#include <stdlib.h>

#include "Header.h"

typedef int l;

int main(){
	
	int capacity = 0;
	int cont = 1;
	unsigned int option;
	int success=0;
	float begin=0;
	struct Calendar_t* cal = NULL;
	struct Meeting_t* meet = NULL;

	printf("Enter number of Meetings:\n");
	scanf("%d",&capacity);
	
	while (cont) {
		printf("Choose option: \n");
		printf("1: Create Appointment Diary  \n"); 
		printf("2: Create Meeting   \n");
		printf("3: Insert appointment  \n");
		printf("4: Remove appointment  \n");
		printf("5: Find appointment \n");
		printf("6: Print diary  \n");

		printf("Any another number - stop \n");

		scanf("%u", &option);

		switch (option) {
			case 1: cal=createAD(capacity);
 				break;

			case 2: meet=createMeeting();
				break;

			case 3: success = insertAppo(cal,meet);
				if (!success) printf("Insert Failed !\n");
				break;

			case 4: printf("Insert begin time of the appointment you would like to remove:");
				scanf("%f",&begin);
				success = removeAppo(cal,begin);
				if (!success) printf("Remove Failed !\n");
				break;

			case 5: printf("Insert begin time of the appointment you would like to find:");
				scanf("%f",&begin);
				meet = findAppo(cal,begin);
				if (!meet) printf("Appointment was not found !\n");
				else{
					("Found! \nYour meeting starts at %f, ends at %f in room %d",meet->beginH,meet->endH,meet->room);
				}
				break;

			case 6: printAD(cal);
				break;

			default: cont=0; break;
		}
	}
	destroy(cal);
	return 0;
}
































