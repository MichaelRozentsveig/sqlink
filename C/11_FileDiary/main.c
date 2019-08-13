#include <stdio.h>
#include <stdlib.h>

#include "Header.h"

typedef int l;

int main(){
	
	int capacity = 0;
	int cont = 1;
	unsigned int option;
	int success=0;
	float begin=0, end=0;
	struct Calendar_t* cal = NULL;
	struct Meeting_t* meet = NULL;
	
	int room;
	
	FILE* fp;
	
	printf("Enter number of Meetings:\n");
	scanf("%d",&capacity);
	
	cal=createAD(capacity);
	while (cont) 

	{
		printf("Choose option: \n");
		printf("1: Create Appointment Diary  \n"); 
		printf("2: Create Meeting   \n");
		printf("3: Insert appointment  \n");
		printf("4: Remove appointment  \n");
		printf("5: Find appointment \n");
		printf("6: Load From File  \n");

		printf("Any another number - stop \n");

		scanf("%u", &option);
		switch (option) 
		{
			case 1: cal=createAD(capacity);
 				break;

			case 2: printf("Insert begin hour: \n");
				scanf("%f", &begin);

				printf("Insert end hour: \n");
				scanf("%f", &end);

				printf("Insert room number: \n");
				scanf("%d", &room);
				meet=createMeetingToFile(begin,end,room);
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

			case 6: loadFromFile(cal);
				break;

			default: cont=0; break;
		}
	}
	saveInFile(cal);
	destroyAD(cal);
	return 0;
}
































