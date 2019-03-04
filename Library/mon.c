#include "mon.h"
#include<stdlib.h>
#include <stdlib.h>
#include<string.h>

Element* create_left(Element* root, char* data)
{
	if(root == NULL){
		return NULL;
	}
	if(root->left_child != NULL){
		return NULL;
	}
	Element* newNode = (Element*)malloc(sizeof(Element));
	newNode->name = data;
	newNode->left_child = NULL;  //initialize children of newNode
	newNode->right_child = NULL;
	root->left_child = newNode;  // add left_child to the root
  	return newNode;
}

Element* create_right(Element* root, char* data)
{	
	if(root == NULL){
		return NULL;
	}
	if(root->right_child != NULL){
		return NULL;
	}
	Element* newNode = (Element*)malloc(sizeof(Element));
	newNode->name = data;
	newNode->left_child = NULL;  //initialize children of newNode
	newNode->right_child = NULL;
	root->right_child = newNode; // add right_child to the root
  	return newNode;
}


void free_tree(Element* root)
{
	if(root != NULL){
		free_tree(root->right_child);
		free(root->name);
		free_tree(root->left_child);
		free(root);
	}
}

int write_tree(FILE* f, Element* e)
{
	if(e == NULL){
		fprintf(f,"NULL ");
		return 0;
	}
	else{
		fprintf(f, "{");
		write_tree(f,e->left_child);
		write_tree(f,e->right_child);
		fprintf(f,"%s",e->name);
		fprintf(f, "}");
	}	
  return 0;
}

void preOrder(Element* node)    //print the tree to check
{ 
    if (node == NULL) 
        return; 
    preOrder(node->left_child); 
    preOrder(node->right_child); 
    printf("name is %s\n", node->name); 

} 

Element* create_tree(char* str)
{	
	int left_start;
	int left_end;
	int right_start;
	int right_end;
	int flag = 0;
	int count = 0;


	char* name = (char*) malloc((strlen(str)+1)*sizeof(char));		
	Element* root = (Element*)malloc(sizeof(Element));


	if(str[1] != '{'){												 //if left child is NULL
		root->left_child = NULL;
		left_end = 5;
	}
	else{
		char* left = (char*) malloc((strlen(str)+1)*sizeof(char));	 //if left child not NULL
		for(int i = 1; i < strlen(str)-1; i++){
			if(str[i] =='{'){										//mark the start point of left_child
				if(flag == 0){
					left_start = i;
					flag = 1;
				}
				count++;
			}
			else if(str[i] =='}'){
				count --;
			}
			if(count == 0){											//mark the end point of left_child
				left_end = i;
				strncpy(left, str+left_start, (i-left_start+1));   	//copy the left substring
				left[i-left_start+1] = '\0';	
				root->left_child = create_tree(left);
				free(left);

				break;												//free space
			}
		}
	}
	
	if(str[left_end + 1] != '{'){									//if right child is NULL
		root->right_child = NULL;
		right_end = left_end + 5;
	}
	else{
		char* right = (char*) malloc((strlen(str)+1)*sizeof(char));  //if right child not NULL
		for(int i = left_end + 1; i< strlen(str)-1;i++){
			if(str[i] =='{'){										//mark the start point of right_child
				right_start = i;
				count++;
			}
			else if(str[i] =='}'){
				count --;
			}
			if(count == 0){													//mark the end point of right_child
				right_end = i;
				strncpy(right, str+right_start, (right_end-right_start+1));	//copy the right substring
				right[right_end-right_start+1] = '\0';	
				root->right_child = create_tree(right);
				free(right);										//free space
				break;
			}
		}
	}


	strncpy(name, str+right_end+1, strlen(str)-1-right_end-1);   //copy the name
	root->name = name;
	return root;
}


Element* load_tree(FILE* f)
{	
	char buff[255];
	fgets(buff, 255, f);
	if(strlen(buff) > 2){
		Element* root = create_tree(buff);
		preOrder(root);
		free_tree(root);
	}
	
}

