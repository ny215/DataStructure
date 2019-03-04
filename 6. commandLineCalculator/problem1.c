
#include <math.h>
#include <stdio.h>

double calculate(double x, char operation, double y)
{
	//char operation = '';
  // Fill in this function
	switch(operation)
	{
		case '+':
			return (x + y);
			break;
		
		case '-':
			return (x - y);
			break;
		
		case '*':
			return  (x * y);
			break;

		case '/':
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

int main(int argc, char* argv[])
{
	double number1;
	double number2;
	char oper;
	double result;
	scanf("%lf %c %lf", &number1, &oper, &number2);
	result = calculate(number1, oper, number2);
	printf("%lf\n", number1);
	printf("%c\n", oper);
	printf("%.13lf\n", result);
  // Your code goes here
  // Feel free to add other functions to this file, but don't add
  // other files since the autograder won't know about them.
  //return(0);

}





