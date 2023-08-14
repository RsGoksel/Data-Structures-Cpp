#include<stdlib.h>
#include<stdio.h>

//Base struct
typedef struct n{
	int data;
	n * next;
	n * prev;
}node;


void print(node * r){
	
	if (r->prev == NULL){
		printf("Previous is NULL | Own Value %d \n",r->data);
	}
	
	node * iter = r->next;
	while(iter != NULL){
		printf("Previous %d | Value %d\n",iter->prev->data,iter->data);
		iter = iter->next;
		}
}

node * insert(node *r, int new_value){
	
	//If root adress is null, than create new node and assign it as root node
	if( r == NULL){
		r = (node*)malloc(sizeof(node));
		r->data = new_value;
		r->next = NULL;
		r->prev = NULL;
		return r;	
	}
	
	node * iter = r;
	while(iter->next != NULL)
		iter = iter->next;
	
	iter->next = (node*)malloc(sizeof(node));
	iter->next->data = new_value;
	iter->next->next = NULL;
	iter->next->prev = iter;
	return r;
}

n * Append_Ordered(node * r,int new_value){
	node * iter = r;
	
	// If new value lower than the root, than create new node and assign it as root
	if( new_value < iter->data ){
		node * temp = (node*)malloc(sizeof(node));
		temp->data = new_value;
		temp->next = r;
		r->prev = temp;
		temp->prev = NULL;
		return temp;
	}	
	
	// Else (if new value will insert in the middle)
	while( iter->next != NULL && new_value > iter->next->data )
		iter = iter->next;
	
	//First, create new space and fill it
	node * temp = (node*)malloc(sizeof(node));
	temp->data = new_value;
	temp->next = iter->next; 
	iter->next = temp;
	
	//and as not break pointers, assign new assigments
	temp->prev = iter;
	if(temp->next != NULL)  //if new node is not the last element, than new node's next's prev is has to point new one
		temp->next->prev = temp;
	return r;
	
}

node * Delete(node * r, int new_value){
	
	node * iter = r;
	
	// If first value, new root will become second one
	if( new_value == r->data){
		node * temp = r;
		r = r->next;
		free(temp);
		return r;
	}
	
	while( iter->data != new_value && iter->next != NULL)
		iter = iter->next;

	if (iter->next == NULL && iter->data == new_value){
		iter->prev->next = NULL;
	//	free(iter);
		return r;
		}
	if(iter->next == NULL){
		printf("number non existing");
		return r;
	}
		
	node * temp = iter;
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;			
	free(temp);
	return r;

}

int main(){

	node * root = NULL;
	
	root = insert(root,0);
	
	
	for(int i=1;i<10;i++)
		insert(root,i);
	
	print(root);
	
	printf("Delete from the head ( delete 0)\n");
	root = Delete(root,0);
	print(root);
	
	printf("Delete from the Mid (delete 5)\n");
	root = Delete(root,5);
	print(root);
	
	printf("Delete from the end (delete 9)\n");
	root = Delete(root,9);
	print(root);
	
	
	printf("Append to head (-1)\n");
	root = Append_Ordered(root,-1);
	print(root);
	
	printf("Append to mid (4)\n");
	root = Append_Ordered(root,4);
	print(root);
	
	printf("Append to end (19)\n");
	root = Append_Ordered(root,19);
	print(root);
	

}


