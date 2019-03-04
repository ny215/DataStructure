int left_start;
int left_end;
int right_start;
int right_end;
int count = 0;
for(int i = 1; i < strlen(str)-1; i++){
	if(str[1] != '{'){
		root->left_child = NULL;
		left_end = 1;
	}
	if(str[i] =='{'){
		left_start = i;
		count++;
	}
	if(str[i] =='}'){
		count --;
	}
	if(count == 0){
		left_end = i;
		strncpy(left, str+left_start, (left_end-left_start+1));	
		root->left_child = create_tree(left);
		break;
	}
}

for(int i = left_end + 1; i<strlen(str)-1;i++){
	if(str[left_end + 1] != '{'){
		root->right_child = NULL;
		right_end = left_end + 1;
	}
	if(str[i] =='{'){
		right_start = i;
		count++;
	}
	if(str[i] =='}'){
		count --;
	}
	if(count == 0){
		right_end = i;
		strncpy(left, str+right_start, (right_end-right_start+1));	
		root->right_child = create_tree(right);
		break;
	}

}