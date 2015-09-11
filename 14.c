/*
14 isBST2() -- version 2
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
#define TRUE 1
#define FALSE 0
int isBST2(struct node*,int min,int max);
struct node *BuildTree(void);
struct node *newNode(int);
struct node *insert(struct node*,int);
int minValue(struct node*);
int maxValue(struct node*);
void print(struct node*);
main()
{
	struct node* node=BuildTree();
	struct node* root=NULL;
	int min=0,max=0;
	int type;
	root=newNode(2);
	root->left=newNode(3);
	root->right=newNode(1);
	root->left->left=NULL;
	root->left->right=NULL;
	printf("Tree is: ");
	print(node);
	printf("\n");
	type=isBST2(root,min,max);
	if(type==TRUE)
		printf("Is a binary search tree\n");
	else
		printf("Is not a binary search tree\n");
}
void print(struct node* node)
{
	if(node!=NULL)
	{
		print(node->left);
		printf("%d ",node->data);
		print(node->right);
	}
}
int isBST2(struct node* root,int min,int max)
{
	if(root==NULL){
		return;
	}
	else{
		
		isBST2(root->left,min,max);
		min=minValue(root);
		max=maxValue(root);
		if(root->data >= min && root->data <= max)
			return (TRUE);
		else
			return (FALSE);
	
		isBST2(root->right,min,max);
	}
	
	
}


int maxValue(struct node* root)
{
	while(root->right!=NULL){
		root=root->right;
	}
	return(root->data);
}
int minValue(struct node* root)
{
	while(root->left!=NULL){
		root=root->left;
	}
	return (root->data);
}
struct node* BuildTree(void)
{
        struct node* root=NULL;
        root=insert(root,2);
	root=insert(root,1);
	root=insert(root,3);
	root=insert(root,5);
	return(root);
}
struct node *insert(struct node* root,int data)
{
	if(root==NULL)
		return(newNode(data));
	else{
		if(data<=root->data)
			root->left=insert(root->left,data);
		else
			root->right=insert(root->right,data);
		return(root);
	}
}
struct node *newNode(int data)
{
	struct node* node;
	node=malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
