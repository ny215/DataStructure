/* problem3.c - Word counting */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Case1: Count based on file 
void process_file(char file[], int argc, char* argv[])
{
	int newlines = 0;
	int words = 0;
	int bytes = 0;
	int flag = 0;
	char ch;
	FILE *f;
	f = fopen(file, "r");
	while((ch = fgetc(f))!=EOF)
	{
		bytes++;
		if(ch == '\n')
			newlines += 1;
		if(ch == ' ' || ch == '\n' || ch == '\t')
		{
			flag = 0;
			continue;
		}
		else
		{
			if(flag == 0)
			{
				words += 1;
				flag = 1;
			}
		}
	}
	if(argc == 2) 
		printf("%d %d %d %s\n", newlines,words,bytes,argv[1]);
	else
	{
		//Up to 3 options
		int options[3] = {0,0,0};
		for(int i = 1; i < argc; i++)
		{
			if(strcmp(argv[i],"-l")==0)
				options[0] = newlines;
			else if(strcmp(argv[i],"-w")==0)
				options[1] = words;
			else if(strcmp(argv[i],"-c")==0)
				options[2] = bytes;
		}
		for(int i = 0; i < 3; i++)
		{
			if(options[i] != 0)
				printf("%d ", options[i]);
		}
		printf("%s\n", file);
	}
	fclose(f);
}

//Case2: Count based on stdin
void process_stdin(int argc, char* argv[])
{
	int newlines = 0;
	int words = 0;
	int bytes = 0;
	int flag = 0;
	char ch;

	while((ch = getchar())!=EOF)
	{
		bytes++;
		if(ch == '\n')
			newlines += 1;
		if(ch == ' ' || ch == '\n' || ch == '\t')
		{
			flag = 0;
			continue;
		}
		else
		{
			if(flag == 0)
			{
				words += 1;
				flag = 1;
			}
		}
	}
	if(argc == 1)
		printf("%d %d %d\n", newlines,words,bytes);
	else
	{
		//Up to 3 options
		int options[3] = {0,0,0};
		for(int i = 1; i < argc; i++)
		{
			if(strcmp(argv[i],"-l")==0)
				options[0] = newlines;
			else if(strcmp(argv[i],"-w")==0)
				options[1] = words;
			else if(strcmp(argv[i],"-c")==0)
				options[2] = bytes;
		}
		for(int i = 0; i < 3; i++)
		{
			if(options[i] != 0)
				printf("%d ", options[i]);
		}
	}
}

int main(int argc, char* argv[])
{
	if(argc == 1)
		process_stdin(argc, argv);  //Get input from stdin
	else if(argc >= 2)
	{	
		int flag = 0;
		for(int i = 1; i < argc; i++)
		{
			if(argv[i][0] == '-')
				continue;
			else
			{
				flag = 1;
				process_file(argv[i],argc,argv); //Get input from file
				break;
			}
		}
		if(flag == 0)
			process_stdin(argc, argv); //Get input from stdin
	}
	return 0;
}
