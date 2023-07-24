#include <stdio.h>

/* Factorial Calculator - The Factorial of a positive integer, n, is defined as the product of the sequence n, n-1, n-2, ...1 and the 
factorial of zero, 0, is defined as being 1. */

int factorial(int a) {
	
	int product = 1;
	
	if(a==0){
		printf("The factorial of %d is %d", a, product);
	}
	else{
		for (int x = a; x > 0; x-- ) {
			printf( "%d times %d \n", product, x );
			product =  product*x;
			printf("Product = %d \n", product);
			}
	}
	
	printf("The factorial of %d is %d \n", a, product);
	
	return product;
}

/* Main function */

int main()
{
  int n = 5;
    
  printf( "Enter an integer value :");
  scanf("%%d", ni);
   
  factorial(n);

  return 0;
}
