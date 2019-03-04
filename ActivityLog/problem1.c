/* EE200 classwork7 problem1 */
/* problem1.c - Activity log */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int isNumber(char c){
    return (c>='0'&&c<='9');
}

int main(int argc, char* argv[])
{

	FILE *file1;
	file1 = fopen("activity.tsv", "a+");			 //If the file does not exist, create one;
	if(argv[1] == NULL || argv[2] == NULL){			 //check the input if it's valid: should have activity and time;
		printf("%s\n","usage: you should enter the activity, duration(in minutes), and note(optional).");
		return 0;
	}
	for(int i = 0; i <strlen(argv[2]); i++){	     //check the input if it's valid: time should be numbers;
		if(isNumber(argv[2][i]) == 0){
			printf("%s\n","usage: you should enter the activity, duration(in minutes), and note(optional).");
			return 0;
		}
	}
	time_t t;
	t = time(NULL);								     //epoch time;
	fprintf(file1, "%ld",t);

	for(int count = 1; count < argc; count ++){	     //write into file;
		fprintf(file1, "\t");
		fprintf(file1, "%s", argv[count]);
		}
	fprintf(file1, "\n");							//get a new line after each input;
	fclose(file1);
  return(0);
}

