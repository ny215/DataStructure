//Write a function that behaves like a simple calculator: it takes two double-precision arguments and 
//a character operand (one of '+', '-', '*', '/', or '^') and returns the result as a double.
//You might want to use the 'pow' function; type 'man pow' at the command-line for the reference page. 
//(If you use 'pow', you'll need to add -lm to your gcc command.)
#include "problem3.h"
#include<math.h>

double calculate(double x, char operation, double y)
{
	//char operation = '';
  // Fill in this function
	switch(operation)
	{
		case '+':
			return  (x + y);
			break;
		
		case '-':
			return  (x - y);
			break;
		
		case '*':
			return  (x * y);
			break;

		case '/':
			if(y==0){
				return 0.0;
			}
			return  (x / y);
			break;
		case '^':
			return  (pow(x,y));
			break;
	}
  // You'll want to replace this with something that returns a meaningful
  // result.
  return(0); 
}

