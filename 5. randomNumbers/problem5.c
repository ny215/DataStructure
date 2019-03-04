
#include "problem5.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
void print_random(int n, int max)
{	
	if(max== 0){
		printf("%d\n", '0');
	}
	srand((unsigned)time((NULL))); //https://mathbits.com/MathBits/CompSci/LibraryFunc/rand.htm
	for(int i=0; i<n; i++){
		int out = rand()%(max);
		printf("%d\n",out);
	}
  // Fill in this function

}

