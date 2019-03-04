#include "problem1.h"
#include<stdio.h>
#include<stdlib.h>
char check_win(char board[3][3])
{
	int i;
	int j;
	int count_x = 0;
	int count_o = 0;
	for(i = 0; i < 3; i++){
		for(j = 0; j <3; j++){
			if(board[i][j] !='x' && board[i][j] != 'o' && board[i][j] != ' '){   // if there is other character in board, it is invalid.
				return '0';
			}			

			if(board[i][j] =='x'){										//count x;
				count_x ++;
				//printf("count_x %d\n",count_x);
			}

			else if(board[i][j] == 'o'){								//count o;
				count_o ++;
			    //printf("count_o %d\n",count_o);
			}
		}
	}
	if (abs(count_x - count_o) >= 2){									// if the difference between count_x and count_o is larger than 2, then it's invalid;
		return '0';
	}


	for(int i = 0; i <3; i++){											//won in row or column;
		if((board[i][0] == board[i][1] && board[i][0] == board[i][2])){
			if(board[i][0] == 'x'){										// if x won the game;
				return 'x';
			}
			else if(board[i][0] == 'o'){								// if o won the game;
				return 'o';			
			}
		}
	}

	for(int i = 0; i <3; i++){											//won in row or column;
		if((board[0][i] == board[1][i] && board[0][i]== board[2][i])){
			if(board[0][i] == 'x'){										// if x won the game;
				return 'x';
			}
			else if(board[0][i] == 'o'){								// if o won the game;
				return 'o';			
			}
		}
	}


	if((board[0][0] == board[1][1] && board[0][0] == board[2][2])){		//won in diagonal;
			if(board[0][0] == 'x'){										// if x won the game;
				return 'x';
			}
			else if(board[0][0] == 'o'){								// if o won the game;
				return 'o';			
			}		
	}

	if(	(board[0][2] == board[1][1] && board[0][2] == board[2][0] )){   //won in diagonal;
			if(board[0][2] == 'x'){										// if x won the game;
				return 'x';
			}
			else if(board[0][2] == 'o'){								// if o won the game;
				return 'o';			
			}		
	}	

	if((count_x + count_o) == 9){      								    //if no one has won and all the spaces are filled ("cat's game")
		return '.';
	}
	else{																//the game is still going;
		return ' ';
	}

  // Fill in this function
  // You don't need to print anything here; just return the correct value

  return(0); // Edit this to return something meaningful
}

