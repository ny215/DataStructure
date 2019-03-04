
#include "problem3.h"
#include<stdio.h>
#include<math.h>
int main(int argc, char* argv[])
{
	double result = calculate(2, '/',0);
	// 	double result = calculate(-1, '^',0.00000001); overflow
  // Put anything here that you think is appropriate to test your function
  // e.g, double result = calculate(37, '+', 1);
  //      if(result ...
	if(result == 0){
		printf("true\n");
	}
	printf("%f\n", result);
  return(0);
}

