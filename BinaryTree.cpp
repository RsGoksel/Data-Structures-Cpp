#include<stdlib.h>
#include<stdio.h>

typedef  struct n{
	int data;
	n * left;
	n * right;
}node;

void inorder(node *root){
	
	if( root == NULL)
		return;
		
	inorder(root->left);
	printf("%d ->",root->data);
	inorder(root->right);
	
}

void postorder(node* root){
	
	if( root == NULL)
		return;
		
	postorder(root->left);
	postorder(root->right);	
	printf("%d ->",root->data);
}

void preorder(node* root){
	
	if( root == NULL)
		return;
		
	printf("%d ->",root->data);	
	preorder(root->left);
	preorder(root->right);
}

node * insert(node*root, int new_value){
	
	if (root == NULL){
		
		node *root = (node*)malloc(sizeof(node));
		root->right = NULL;
		root->left = NULL;
		root->data= new_value;
		return root;
		}
		
	if( new_value > root->data){
		root->right = insert(root->right, new_value);
		return root;
	}
	
	root->left = insert(root->left,new_value);
	return root;

}

void find(node *r, int new_value){
	
	if( r == NULL)
		return;
		
	find(r->left,new_value);
	
	if( r->data == new_value ){
	
		printf("\n** %d bulundu",r->data);
		return;
	}
	
	find(r->right,new_value);
}

int max(node*r){
	while( r->right != NULL)
		r = r->right;
	return r->data;	
}

int min(node*r){
	while( r->left != NULL)
		r = r->left;
	return r->data;
}


int main(){
	node * root = NULL;
	
	for(int i=5;i<10;i++)
		root = insert(root,i);
		
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
}
