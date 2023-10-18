#include<stdlib.h>
#include<stdio.h>

//Base struct
typedef struct n{
	int data;
	n * next;
}node;

//Insert new node
node * insert(node*r, int new_value){
	
	//If root adress is null, than create new node and assign it as root node
	if( r == NULL){
		r = (node*)malloc(sizeof(node));
		r->data = new_value;
		r->next = r;
		return r;	
	}
	
	node * iter =r;
	
	while(iter->next != r )
		iter = iter->next;
	
	iter->next = (node*)malloc(sizeof(node));
	iter->next->data = new_value;
	iter->next->next = r;
	return r;
}

//List the linked list
void print(node*r){
	printf("%d-> ",r->data);
	
	node * iter = r->next;
	
	while (iter != r){
		printf("%d-> ",iter->data);
		iter = iter->next;
	}
	
}

// ordered Insertion
node * Append_Ordered(node * r, int new_value){

	//If root is null, allocate new space
	if (r == NULL){
		r = (node*)malloc(sizeof(node));
		r->data = new_value;
		r->next = r;
		return r; 
	}
	
	// for -1'th place. (last index)
	if (r->data > new_value){
		node * temp = (node*)malloc(sizeof(node));
		temp->data = new_value;
		temp->next = r;
		
		node * iter = r;
		while(iter->next != r)
			iter = iter->next;
		iter->next = temp;
		return temp;
	}
	
	//between mid-end values
	node * iter = r;
	while(new_value > iter->data && iter->next != r)
		iter = iter->next;
	
	node * temp = iter->next;
	iter->next = (node*)malloc(sizeof(node));
	iter->next->data = new_value;
	iter->next->next = temp;
	return r;
	
}

node * Delete(node * r , int new_value){
	
	//If only one element and if we'll delete it
	if(r->next == r && r->data == new_value)
		return NULL;
	
	//if we going to delete First element while the list has more numbers, 
	// Than go straight until the last index which it's next is root. Then create a new node, and assign second index to it's next.
	// 1 2 4 5,     go to 5, assign 5's next as 2, and delete 1 
	
	if(r->data == new_value){
		node * iter =r;
		while(iter->next != r)
			iter = iter->next;
		
 		node * temp = r;
 		iter->next = r->next;
 		free(temp);
 		return iter->next;  // previous function call, we've call the command as root = Delete, so our new root will become iter->next
	}
	
	
	// Mid and End values
	node * iter = r;
	while( iter->next->data != new_value && iter->next != r)
		iter = iter->next;
		
	if(iter->next->data == new_value){
		iter->next = iter->next->next;
		return r;
	}
	
	if(iter->next == r){
		return r;
	}
	
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
	root = Append_Ordered(root,-2);
	print(root);
	
	printf("Append to mid (4)\n");
	root = Append_Ordered(root,4);
	print(root);
	
	printf("Append to end (19)\n");
	root = Append_Ordered(root,19);
	print(root);	
	
	
	
	
	
}










