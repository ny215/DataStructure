/* EE200 classwork7 problem3 */
/* problem3.c - Word counting */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void file_case(char file[], int argc, char* argv[])			//count from file
{
	int newline = 0;
	int words = 0;
	int bytes = 0;
	int flag = 0;
	char buff;

	FILE *fp;
	fp = fopen(file, "r");
	while((buff = fgetc(fp))!=EOF){
		bytes++;
		if(buff == '\n'){
			newline ++;
		}
		if(buff == ' ' || buff == '\n' || buff == '\t'){
			flag = 0;
			continue;
		}
		else{
			if(flag == 0){
				words ++;
				flag = 1;
			}
		}
	}
	if(argc == 2) 
		printf("%d %d %d %s\n", newline, words, bytes, argv[1]);
	else
	{
		int sign[3] = {0,0,0};
		for(int i = 1; i < argc; i++){
			if(strcmp(argv[i],"-l") == 0)
				sign[0] = newline;
			else if(strcmp(argv[i],"-w") == 0)
				sign[1] = words;
			else if(strcmp(argv[i],"-c") == 0)
				sign[2] = bytes;
		}
		for(int i = 0; i < 3; i++){
			if(sign[i] != 0)
				printf("%d ", sign[i]);
		}
		printf("%s\n", file);
	}
	fclose(fp);
}


void stdin_case(int argc, char* argv[])				//count from stdin
{
	int newline = 0;
	int words = 0;
	int bytes = 0;
	int flag = 0;
	char buff;

	while((buff = getchar())!=EOF)
	{
		bytes++;
		if(buff == '\n')
			newline ++;
		if(buff == ' ' || buff == '\n' || buff == '\t')
		{
			flag = 0;
			continue;
		}
		else
		{
			if(flag == 0)
			{
				words ++;
				flag = 1;
			}
		}
	}
	if(argc == 1)
		printf("%d %d %d\n", newline, words, bytes);
	else
	{
		int sign[] = {0,0,0};
		for(int i = 1; i < argc; i++)
		{
			if(strcmp(argv[i],"-l") == 0)
				sign[0] = newline;
			else if(strcmp(argv[i],"-w") == 0)
				sign[1] = words;
			else if(strcmp(argv[i],"-c") == 0)
				sign[2] = bytes;
		}
		for(int i = 0; i < 3; i++)
		{
			if(sign[i] != 0)
				printf("%d ", sign[i]);
		}
	}
}

int main(int argc, char* argv[])
{
	if(argc == 1)					//nothing only stdin
		stdin_case(argc, argv);  
	else if(argc >= 2){	
		int flag = 0;
		for(int i = 1; i < argc; i++){
			if(argv[i][0] == '-')
				continue;
			else{
				flag = 1;
				file_case(argv[i], argc, argv); //get input from file
				break;
			}
		}
		if(flag == 0)
			stdin_case(argc, argv); //get input from stdin
	}
	return 0;
}



