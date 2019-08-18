#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Header.h"

static void decimalToBinChar(unsigned int decimal) { 
	
	char str[128];
	int i=0;

	while(decimal>0){
		str[i]=decimal%2+'0';
		decimal/=2;
		i++;
	} 
	str[i]='\0';

	for(i=8;i>=0;i--){
		if(i<=strlen(str)){
		printf("%c",str[i]);
		}else{
		printf("%c",'0');
		}
	}
} 

int invertBits(unsigned char* x){
	unsigned char converter = 0;
	unsigned int ans=0;
	if (!x){
		return 0;
	}
	converter =~ converter;
	*x=*x^converter;
	
	ans = (unsigned int)(*x);
	decimalToBinChar(ans); 
	return 1;
}

int rotateBits(unsigned char* x, int rotNum){
	
	unsigned char str=0;
	unsigned int num=0;

	if (!x){
		return 0;
	}
	str=*x;
	str <<= (8-rotNum);
	*x>>=rotNum;
	*x|=str;

	num = (unsigned int)(*x);
		decimalToBinChar(num); 
	return 1;			
}

int setBitsFromY(unsigned char* x, int p,int n, unsigned char* y){
	unsigned int ans=0;	
	unsigned char setter = pow(2,n)-1;
	if (!x || !y || n>8){
		return 0;
	}
	setter<<=(p-n);
	setter=~setter;
	*x&=setter;
	*y<<=(8-n);
	*y>>=(8-p);
	*x|=*y;
	
	ans = (unsigned int)(*x);
	decimalToBinChar(ans); 
	return 1;	
}

int setBits(unsigned char* w,int i,int j,int value){
	unsigned int ans;
	unsigned char setter = pow(2,j-i+1)-1;
	if (!w){
		return 0;
	}
	setter<<=(i-1);
	if (value==1){
		*w|=setter;
	}else{
		setter=~setter;
		*w&=setter;
	}
	ans=(unsigned int)(*w);
	decimalToBinChar(ans); 
	return 1;
}
		




















