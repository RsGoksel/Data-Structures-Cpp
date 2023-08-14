#include<stdlib.h>
#include<stdio.h>

//Base struct
typedef struct n{
	int x;
	n * next;
}node;

//Insert new node
node * insert(node*r, int x){
	
	//If root adress is null, than create new node and assign it as root node
	if( r == NULL){
		r = (node*)malloc(sizeof(node));
		r->x = x;
		r->next = r;
		return r;	
	}
	
	node * iter =r;
	
	while(iter->next != r )
		iter = iter->next;
	
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = r;
	return r;
}

//List the linked list
void print(node*r){
	printf("%d-> ",r->x);
	
	node * iter = r->next;
	
	while (iter != r){
		printf("%d-> ",iter->x);
		iter = iter->next;
	}
	
}

// ordered Insertion
node * Append_Ordered(node * r, int x){

	//If root is null, allocate new space
	if (r == NULL){
		r = (node*)malloc(sizeof(node));
		r->x = x;
		r->next = r;
		return r; 
	}
	
	// for -1'th place. (last index)
	if (r->x > x){
		node * temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;
		
		node * iter = r;
		while(iter->next != r)
			iter = iter->next;
		iter->next = temp;
		return temp;
	}
	
	//between mid-end values
	node * iter = r;
	while(x > iter->x && iter->next != r)
		iter = iter->next;
	
	node * temp = iter->next;
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = temp;
	return r;
	
}

node * Delete(node * r , int x){
	
	//If only one element and if we'll delete it
	if(r->next == r && r->x == x)
		return NULL;
	
	//if we'll delete First element and list has more numbers.
	//Go until last index which its next is root, than create new node, and assign second index to it's next.
	// 1 2 4 5,     go 5, assign 5's next as 2, and delete 1 
	
	if(r->x == x){
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
	while( iter->next->x != x && iter->next != r)
		iter = iter->next;
		
	if(iter->next->x == x){
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










