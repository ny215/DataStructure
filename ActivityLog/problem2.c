/* EE200 classwork7 problem2 */
/* problem2.c - Activity summary */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int isNumber(char c){
    return (c>='0'&&c<='9');
}

int main(int argc, char* argv[])
{	

	if(argv[1] == NULL){      			//if summary duration is not specifed,or it only has a number/letter;
	 printf("%s\n","usage: The argument consists of an integer plus one of d, w, or y.");
		return 0;
	}

	int len = strlen(argv[1]);
	if(argv[1] == NULL || len == 1){      			//if summary duration is not specifed,or it only has a number/letter;
	 printf("%s\n","usage: The argument consists of an integer plus one of d, w, or y.");
		return 0;
	}
	for(int i = 0; i < strlen(argv[1])-1; i++){	 	//if duration has letter mixed in number: e.g.: w12w;
		if(isNumber(argv[1][i]) == 0){
			printf("%s\n","usage: The argument consists of an integer plus one of d, w, or y.");
			return 0;
		}
	}
	if(isNumber(argv[1][len-1])){					//if duration only has number without d,w,or y;
		printf("%s\n","usage: The argument consists of an integer plus one of d, w, or y.");
		return 0;
	}

	int number;										//duration time(number);
	long int duration;									
	long int factor;								//factor for convert d,w,y into second;
	for(int i = 0; i < len; i++){						//get number of d/w/y from input
		number = atoi (argv[1]);
	}

	switch(argv[1][len-1])					//get factor
	{
		case 'd':
			factor = 86400;					// 1day = 86400s;
			break;
		case 'w':
			factor = 604800;				// 1week = 86400 * 7 = 604800s;
			break;
		case  'y':
			factor = 31449600;				// 1year = 604800 * 52 = 31449600s;
			break;
	}

	duration = number * factor;


	FILE * fp;								//read file
	fp = fopen("activity.tsv", "r");

	if(fp == NULL){						    //check if the file does not exist or is corrupted; 
		printf("error\n");
		exit(-1);
	}




	char buff[255];				//get a buffer to store the read content.
	int min = 0;  				//calculate the sum of minute;



	time_t t;					//get current time;
	t = time(NULL);

    


	while(fgets(buff,255,fp)!= NULL){
		char* epoch = strtok(buff,"\t");
		char* act = strtok(NULL,"\t");
		char* dur = strtok(NULL,"\t");
		long int t_epoch = atoi(epoch);
		if((t - duration) <= t_epoch){
			int num = atoi(dur);
			min = min + num;
		}

	}


	fclose(fp);
	printf("Total exercise: %d minutes\n",min);
  	return(0);
}


