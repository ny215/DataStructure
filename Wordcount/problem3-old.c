/* EE200 classwork7 problem3 */
/* problem3.c - Word counting */
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int bytes = 0;							//initialize counters;
	int words = 0;
	int newline = 0;
	char buff;								//buffer to store current reading character;
	int flag = 0;							//flag to mark the postion;
	int sign = 0;


	FILE * fp;								//read file;

	char *filename = argv[argc-1];				//get file's name;
        
	fp = fopen(filename,"r");
	if(fp == NULL){	
		sign = 1;					    //check if the file does not exist or is corrupted; 
		fp = fopen("newfile.tsv", "w+");	//if not exist, build a new file to collect stdin;
		for(int count = 1; count < argc; count ++){
			if((strcmp(argv[count],"-w") != 0) && (strcmp(argv[count],"-w") != 0) && (strcmp(argv[count],"-w") != 0)){
				fprintf(fp, "%s ", argv[count]);			
			}

		}
		fclose(fp);
		fp = fopen("newfile.tsv", "r");
	}

	while((buff = getc(fp))!= EOF){		    //read by character;
		bytes ++;						    //count bytes;
		if(buff == ' '){
			flag = 0;
		}
		else if(buff =='\n' || buff == '\t'){   
			newline++;						//count lines;
			flag = 0;
		}
		else{
			if(flag == 0){					//count words;
				flag = 1;
				words++;
			}
		}
	}


	if(argv[2] == NULL){				   //cases of output;
		printf("%d %d %d %s\n", newline, words, bytes, filename);
	}

	if(strcmp(argv[1],"-l") == 0){
		printf("%d ",newline);
	}
	else if(strcmp(argv[1],"-w") == 0 || strcmp(argv[2],"-w") == 0){
		printf("%d ", words);
	}
	else if(strcmp(argv[1],"-c") == 0 || strcmp(argv[2],"-c") == 0){
		printf("%d ", bytes);
	}
	if(strcmp(argv[2],"-l") == 0){
		printf("%d ",newline);
	}
	else if(strcmp(argv[2],"-w") == 0 || strcmp(argv[2],"-w") == 0){
		printf("%d ", words);
	}
	else if(strcmp(argv[2],"-c") == 0 || strcmp(argv[2],"-c") == 0){
		printf("%d ", bytes);
	}
	if(sign == 0){
		printf("%s\n", filename);
	}
	else{
		printf("\n");	
	}

    fclose(fp);
    return(0);
}

