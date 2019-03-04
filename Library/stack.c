#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* str = "HEY HIHIHI";
    printf("%s\n", str);
    char* left = (char*) malloc((strlen(str)+1)*sizeof(char));
    char* right = (char*) malloc((strlen(str)+1)*sizeof(char));
    strncpy(left, str, 3); 
    strncpy(right, str+3,strlen(str)-3+1);
    printf("%s\n", left);
    printf("%s\n", right);
    free(left);
    free(right);
}