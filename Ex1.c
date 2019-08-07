dd#include <stdio.h>

void func1(int);
void func2(int);
void func3(int);

int main(){

	int lines = 0;
	printf("Enter number of lines\n");
	scanf("%d", &lines);

	func1(lines);
	("\v");

	func2(lines);
	("\v");

	func3(lines);
	("\n");

	return 0;
}



void func1(int n){
	int line=1;
	int stars =1;

	for (line=1;line<=n;line++){
		for (stars=1;stars<=line;stars++){
			printf("*");
		}
		printf("\n");
	}
}


void func2(int n){
	int line = 1;
	int stars = 1;

	func1(n);
	
	for(line =n; line>1;line--){
		for( stars =1; stars<line;stars++){
			printf("*");
		}
		printf("\n");
	}
}




void func3(int n){
	int line =0, stars=1,empty=n;
	
	for (line=1;line<=n;line++){

		for (stars=1;stars<empty;stars++){
			printf(" ");
			
		}
		empty--;
		for (stars=1;stars<=2*line-1;stars++){
			printf("*");
		}
		printf("\n");
	}
}










