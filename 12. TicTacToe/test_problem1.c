
#include "problem1.h"
#include<stdio.h>


int main(int argc, char* argv[])
{
	
	//test with invalid char;
	printf("test1\n");
	char board1[3][3] = {{' ','A','x'}, 
						 {'o','x','o'}, 
						 {' ','o',' '}};   
	char out1 = check_win(board1);
	printf("%c\n", out1);
	
	//test with invalid mount of x and o;
	printf("test2\n");	
	char board2[3][3] = {{'x','x','x'}, 
						 {'o','x','o'}, 
						 {'x','o',' '}};   
	char out2 = check_win(board2);
	printf("%c\n", out2);
	

	
	//won in row;
	printf("test3\n");	
	char board3[3][3] = {{'x','x',' '}, 
						 {'o','o','o'}, 
						 {' ',' ','x'}};   
	char out3 = check_win(board3);
	printf("%c\n", out3);
	

	
	//won in colomn;
	printf("test4\n");	
	char board4[3][3] = {{'x','o',' '}, 
						 {'x','x','o'}, 
						 {'x','o',' '}};   
	char out4 = check_win(board4);
	printf("%c\n", out4);
	

	
	//won in diagonal;
	printf("test5 diagonal\n");	
	char board5[3][3] = {{'x','o','o'}, 
						 {'x','o','x'}, 
						 {'o',' ',' '}};   
	char out5 = check_win(board5);
	printf("%c\n", out5);
	

	//on going;
	printf("test6\n");		
	char board6[3][3] = {{' ','o',' '},
						 {' ','x','o'}, 
						 {'x',' ','x'}};   
	char out6 = check_win(board6);
	printf("%c\n", out6);
	

	//cat game;
	printf("test7\n");	
	char board7[3][3] = {{'x','o','x'}, 
						 {'x','o','o'}, 
						 {'o','x','x'}};   
	char out7 = check_win(board7);
	printf("%c\n", out7);



  // Put anything here that you think is appropriate to test your function

  return(0);
}

