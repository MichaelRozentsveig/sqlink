#include <stdio.h>
#include <stdlib.h>

#include "Header.h"


struct Calendar_t* createAD(int capacity){

	struct Calendar_t* cptr= (struct Calendar_t*) malloc (sizeof(struct Calendar_t));
	if (!(cptr)){
		return NULL;
	}
	cptr->capacity = capacity;	
	cptr->count=0;

	cptr->mt = malloc (capacity* sizeof(struct Meeting_t*));
	if (!(cptr->mt)){
		free(cptr);
		return NULL;
	}
	return cptr;
}

struct Meeting_t* createMeeting(){
	
	float begin=0, end=0;
	int r =0;
	struct Meeting_t* me = NULL;
	me = malloc (sizeof(struct Meeting_t));
	if (!(me)){
		return NULL;
	}

	printf("Insert begin hour: \n");
	scanf("%f", &begin);

	printf("Insert end hour: \n");
	scanf("%f", &end);

	printf("Insert room number: \n");
	scanf("%d", &r);

	/*if (begin>=end || end<0 || begin<0 || r<0 || end>24){
		return NULL;	
	}*/
	
	me->beginH =  begin;	
	me->endH = end;
	me->room = r;
	return me;
}

int insertAppo(struct Calendar_t* ca, struct Meeting_t* mptr){
		
	struct Meeting_t** temp ;	
	int success =0;
	int i=0,j=0, current=0;
	
	if (ca == NULL || mptr == NULL){
		return 0;
	}

	temp = ca->mt;
	if (ca->count==0){
		if((ca->count)==(ca->capacity)){
                	temp=(struct Meeting_t **)realloc(ca->mt, sizeof(struct Meeting_t *)*((ca->capacity)*2)); 
			if(!temp) {
				return 0;
			}

			ca->mt=temp;
			(ca->capacity)*=2;
		}
		ca->mt[0]=mptr;
		ca->count++;
		success=1;
	}
	
	else if((ca->mt[0]->beginH)>=(mptr->endH)){
		if((ca->count)==(ca->capacity)){
                	temp=(struct Meeting_t **)realloc(ca->mt, sizeof(struct Meeting_t *)*((ca->capacity)*2)); 
			if(!temp){
				return 0;
			}
	
			ca->mt=temp;
			(ca->capacity)*=2;
		}

		for(i=ca->count;i>0;i--){
		ca->mt[i]=ca->mt[i-1];	      
	}

	ca->mt[0]=mptr; 
	ca->count++;
	success=1;
		   
          
	}else if((ca->mt[ca->count-1]->endH) <= (mptr->beginH)){
		if((ca->count)==(ca->capacity)){
               		temp=(struct Meeting_t **)realloc(ca->mt, sizeof(struct Meeting_t *)*((ca->capacity)*2)); 
			if(!temp){
				return 0;
			}
			ca->mt=temp;
			(ca->capacity)*=2;
		}
		ca->mt[ca->count]=mptr; 
		ca->count++;
		success=1;

	}else{
       		for(i=1;i<ca->count;i++){  
			if(((mptr->beginH)>=(ca->mt[i-1]->endH))&&((mptr->endH)<=(ca->mt[i]->beginH))){
				if((ca->count)==(ca->capacity)){
                       			temp=(struct Meeting_t **)realloc(ca->mt, sizeof(struct Meeting_t *)*((ca->capacity)*2)); 
					if(!temp){
						return 0;
					}
			
					ca->mt=temp;
					(ca->capacity)*=2;
				}
				current=i;
				for( j=ca->count ; j>current ; j--){
					ca->mt[j]=ca->mt[j-1];
				}
				ca->mt[current]=mptr; 
				ca->count++;
				success=1;
			}
		}
		    
	}
	return success;
}

int removeAppo(struct Calendar_t* ca, float begin){
	int success =0;	
	int i=0, current=0;

	if (!(ca))  {return 0;}
	
	for (; i<ca->count;i++){
		if (ca->mt[i]->beginH == begin){
			free(ca->mt[i]);
			for(current=i; current<ca->count;current++){
				ca->mt[current] = ca->mt[current+1];
			}
			ca->count--;
			success = 1 ;
		}
	}
	return success;
} 

struct Meeting_t* findAppo(struct Calendar_t* ca,float begin){		
	
	int i=0;
	if (ca){
		for (i=0; i<ca->count;i++){
			if ((ca->mt[i]->beginH) == begin){
				return ca->mt[i];
			}
		}
	}
	return NULL;
}



void printAD(struct Calendar_t* cptr){ 
	
	int i=0;
	if(!(cptr)){return;}

	for (; i<(cptr->count); i++){
		printf("Time: %.2f ~ %.2f Room: %d\n", cptr->mt[i]->beginH, cptr->mt[i]->endH, cptr->mt[i]->room);
	}
	printf("\n");
}

void destroy(struct Calendar_t* ca){ 
	
	int i=0;
	if (!(ca)) {return;}

	for (;i<ca->capacity;i++){
		if (ca->mt[i]){
			free(ca->mt[i]);
		}
	}
	free(ca->mt);
	free(ca);
}










