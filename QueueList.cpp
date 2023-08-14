#include<stdlib.h>
#include<stdio.h>

// First in First out

typedef struct n{
	int data;
	n * next;
}node;

node * root = NULL;
node * end = NULL;

void enque(int new_value){
	if(root == NULL){
		root = (node*)malloc(sizeof(node));
		root->data = new_value;
		root->next = NULL;
		end = root;
		return;	
	}
	
	end->next = (node*)malloc(sizeof(node));
	end->next->data = new_value;
	end = end->next;
	end->next = NULL;
}

int deque(){
	if(root == NULL){
		printf("Already Empty ");
		return -1;	
	}
	
	node *temp = root;
	int Rvalue = root->data;
	root = root->next;
	free(temp);
	return Rvalue;
}

void print(){
	node * iter = root;
	
	for(int i=0; iter != NULL ;i++){
		
		printf("%d->",iter->data);
		iter = iter->next;
	}
	printf("\n");
	
}

int main(){
	enque(2);
	enque(3);
	enque(5);
	enque(5);
	print();
	deque(); //delete from left side which first in (which will first out)
	print();
}


