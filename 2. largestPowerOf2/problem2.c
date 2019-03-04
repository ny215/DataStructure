
#include "problem2.h"
#include<stdio.h>

//Write a function that returns the largest power of 2 that is less than or equal to N (i.e., 5 returns 4, 12 returns 8, etc.).

int find_power(int n)
{	
	if(n == 1){
		return 1;
	}
	else if(n < 1){
		return -1; 
	}
	int num = 1;
	while(num < n){
		num *= 2;
	}
	if(num > n){
		return num/2;
	}
	return num;
	
  // Fill in this function

  // You'll want to replace this with something that returns a meaningful
  // result.
  //printf("%d\n", num);
  //return 0;
}

