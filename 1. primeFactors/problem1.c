#include "problem1.h"
#include<stdio.h>
#include<math.h>

int print_factors(int n)
{
	if(n <= 1){
		return(-1);
	}
	int n1 = n;
	for(int i = 2; i <= sqrt(n1); i++){
		while(n > i){
			if(n % i == 0){
				printf("%d\n", i);
				n = n/i;
			}
			else
				break;
		}
	}
  // Fill in this function

  // You'll want to replace this with something that returns a meaningful
  // result.
  printf("%d\n", n);
  return(0); 
}