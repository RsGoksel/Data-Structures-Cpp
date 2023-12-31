#include<stdlib.h>
#include<stdio.h>

//Base struct
typedef struct n{
	int data;
	n * next;
}node;


//Insert new node
node * insert(node * r,int new_value){
	
	//If root adress is null, than create new node and assign it as root node
	if( r == NULL){
		r = (node*)malloc(sizeof(node));
		r->data = new_value;
		r->next = NULL;
		return r;	
	}
	
	//If not, go straight until next is Null, thus new node will appended to end of linked list
	while(r->next != NULL)
		r = r->next;
	r->next = (node*)malloc(sizeof(node));
	r->next->data = new_value;
	r->next->next = NULL;
	return r;
	
}

//List the linked list
void print(node *r){
	while(r != NULL){
		printf("Value:> %d adress:> %d\n",r->data, r); 
		r = r->next;
	}
	printf("\n");
}

// ordered Insertion
node * Append_Ordered(node*r, int new_value){
	
	// If new value lower than the root, than create new node and assign it as root
	if( new_value < r->data ){
		node * New = (node*)malloc(sizeof(node));
		New->data = new_value;
		New->next = r;
		r = New;
		return r;
	}	
	
	//If not, go straight until new data is greater than previous one
	node * iter = r;
	while( iter->next != NULL && new_value > iter->next->data ){
		iter = iter->next;
	}
	
	node * New = (node*)malloc(sizeof(node));
	New->data = new_value;
	New->next = iter->next;
	iter->next = New;
	return r;
	
}

//Delete any node from the chain
node * Delete(node*r,int new_value){
	
	if( r->data == new_value){
		r = r->next;
		return r;
	
	}
	
	node * iter = r;
	while(iter->next->data != new_value)
		iter = iter->next;
	if(iter->next->data == new_value && iter->next->next == NULL){
		iter->next = NULL;
		return r;
	}
	if(iter->next->data == new_value){
		iter->next = iter->next->next;
		return r;
	}
}

//Get number of chain by Recursive function
int count(node * head)
{
    if (head == NULL) {
        return 0;
    }

    else {
        return 1 + count(head->next);
    }
}

// count, delete, Append_Ordered, print, insert

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
	
	printf("\n\n** Length = %d",count(root));

}

