/*classwork8	problem1*/
/* problem1.c - implementation of Linux `tree` */
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <dirent.h>

int tree(char * path, int depth){
	DIR * dir = NULL;
	struct dirent* dir_ent = NULL; 
	int i = depth;  						//copy depth for output format
	dir = opendir(path);

	if(dir == NULL){						//fail to open a file;
		printf("fail to open file\n");
		return -1;
	}


	while((dir_ent = readdir(dir))!= NULL){
         if (!strcmp(dir_ent->d_name, ".") || !strcmp(dir_ent->d_name, "..")){ //if  is "."" or "..", continue
             continue;   
         }   
        char temp_path[1000];      			//store temp_path;
        memset(temp_path, 0, 1000);
        snprintf(temp_path, sizeof(temp_path), "%s/%s", path, dir_ent->d_name); //copy the path, with old and current
			while(i > 0){					//print out as the required format;
				printf("    ");
				i--;
			}
			printf("%s\n", dir_ent->d_name);
			i = depth;
			if(dir_ent->d_type == 4){         //d_type(4):dir	if it's a directory, then go into it;
				tree(temp_path, depth + 1);
			}

	}
	closedir(dir);
	return 0;
}


int main(int argc, char* argv[])
{
     char path[1000] = ".";					//If no directory is specified, use the current working directory;
     int depth = 0; 
     if (argc == 2) {
         sprintf(path, "%s", argv[1]);		//read from stdin;
     }   
     tree(path, depth);
}

