#include <stdio.h>

/* The Collatz conjecture is an unsolved problem in mathematics: 
Does the Collatz sequence eventually reach 1 for all positive integer initial values? 

The Collatz sequence: Start with a number n > 1. Find the number of steps it takes to reach one using the following process: 
If n is even, divide it by 2. If n is odd, multiply it by 3 and add 1. 

This program outputs the Collatz sequence for positive integers > 1 */

int collatz(int n, int *c){
    
    int count = *c;
    printf("Step: %d \n", count);
	printf("Value: %d \n", n);
	
	if(n!=1){

		if((n%2)==0){
		n = n/2;
		count++;
		}
		
		else {
		n = (3*n)+1;
		count++;
		}
        
	    collatz(n, &count);
	}
	else {
        printf("After %d iterations, the value is 1 \n", count);
	}
	
return n, *c;

}

/* Main function */

int main()
{
    int n = 5;
    int counter = 0;

    printf( "Enter a value :");
    scanf("%d", &n);

    collatz(n, &counter);

    return 0;
}
