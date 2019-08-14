#include <stdio.h>

int palindrome(int);
int ascendingOrder(int);
int perfectNumber(int);
int reverseNumber(int);
int isPrime(int);


int main(){
	
	int num =0;
	int ans =0;

	printf("Please enter a number between 0 and 2,000,000,000 to check if its a palindrome:\n");
	scanf("%d",&num);
	ans = palindrome(num);
	printf("The answer is : %d\n\n", ans);

	printf("Please enter a positive number to check for ascending order:\n");
	scanf("%d",&num);
	ans = ascendingOrder(num);
	printf("The answer is : %d\n\n",ans);

	printf("Please enter a positive number to check if its a perfect number:\n");
	scanf("%d",&num);
	ans = perfectNumber(num);
	printf("The answer is : %d\n\n",ans);

	printf("Please enter a positive number to reverse:\n");
	scanf("%d",&num);
	ans = reverseNumber(num);
	printf("The answer is : %d\n\n",ans);
	
	printf("Please enter a positive number to check if its a prime number:\n");
	scanf("%d",&num);
	ans = isPrime(num);
	printf("The answer is : %d\n",ans);

}

int palindrome(int num){ 
	int ans =0;
	int num1 = num;
	int rev = 0;
	rev = reverseNumber(num);
	if (rev == num1){
		ans =1;
	}
	return ans;
}

int ascendingOrder(int num){
	int ans =1;
	if (num<10 && num>=0)
		ans=1;
	while (num!=0){
		if (num%10 < (num/10)%10){
			ans=0;
		}
		num/=10;
	}
		return ans;
}

int perfectNumber(int num){
	int ans =0;
	int sum=0;
	int divisor=1;
	for (; divisor*2 <=num ; divisor++){
		if (num%divisor == 0){
			sum+=divisor;
		}
	}
	if (sum == num){
		ans=1;
	}
	
	return ans;
}

int reverseNumber(int num){
	int rev = 0;
	while (num>0){
		rev = (rev*10)+ (num%10);	
		num/=10;
	}
	
	return rev;
}

int isPrime(int num){
	int ans = 1;
	int divisor = 2;
	if (num>2){
		for (;divisor*divisor <=num ;divisor ++){
			if (num%divisor ==0){
				ans=0; break;
			}
		}
	}
	return ans;
}




















