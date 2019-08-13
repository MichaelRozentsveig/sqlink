#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Header.h"


void lastNlines(int n,char* fileName){

	int* lastLines;
	char ch [128];
	int i=0;
	FILE * fp;
	lastLines=(int*)malloc(sizeof(int)*n);
	
	if((fp=fopen(fileName,"r"))){
		while(!feof(fp)){
			lastLines[i%n]=ftell(fp);
			fgets(ch,128,fp);
			i++;
		}

		fseek(fp,lastLines[i%n],0);

		while(!feof(fp)){
			printf("%s\n",ch);
			fgets(ch,128,fp);
		}
		fclose(fp);
		free(lastLines);
	}
}

void charCount(char* fileName){
	FILE * fp;
	char uppercase[26], lowercase[26];
	char currentChar;
	unsigned int i=0;

	for(i=0;i<26;i++){
		uppercase[i]=0;
		lowercase[i]=0;
	}

	if((fp=fopen(fileName,"r"))){
		while(!feof(fp)){ /*Counting for each character*/
			currentChar=getc(fp);
			if((currentChar>='A')&&(currentChar<='Z')){
				uppercase[currentChar-'A']++;
			}else  if((currentChar>='a')&&(currentChar<='z')){
				lowercase[currentChar-'a']++;
			}
		}
		for(i=0;i<26;i++){ /*Printing the result*/
			if(uppercase[i]>0){
				printf("Letter: %c, Occurrence: %d\n",i+'A',uppercase[i]);
			}else if(lowercase[i]>0){
				printf("Letter: %c, Occurrence: %d\n",i+'a',lowercase[i]);
			}
		}
	fclose(fp);
	}
}


void wordCount(char* fileName){
	FILE * fp, *output;
	char currentWord [64];
	char *out="outputFile.txt";
	wordStruct** countword;
	int i=0;
	int wordIndex=0,wordExists=0;
	
	if((fp=fopen(fileName,"r"))){
		countword=malloc(sizeof(wordStruct *));
		
		while(!feof(fp)){
			fscanf(fp,"%s",currentWord);
			for(wordIndex=0;wordIndex<i;wordIndex++){
				if(strcmp (countword[wordIndex]->word,currentWord)==0){
					wordExists=1;
					countword[wordIndex]->count++;
					break;
				}
			}
			if(wordExists==0){ /*New word*/
				if(i>0){
					countword=(wordStruct**)realloc(countword, sizeof(wordStruct *)*(i+1)); 
				}
				countword[i]=(wordStruct *)realloc(countword[i], sizeof(wordStruct));
				strcpy(countword[i]->word, currentWord);
				countword[i]->count=1;
				i++; 
			}
			wordExists=0;
		}
		if((output=fopen(out,"w"))){ /*Writes in new file*/
			for(wordIndex=0;wordIndex<i;wordIndex++){
				fprintf(output," %s   %d\n",countword[wordIndex]->word,countword[wordIndex]->count);
			}
			fclose(output);
			fclose(fp);
			}
	}
}





