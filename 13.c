/*
13 isBST() -- version 1
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
int isBST(struct node*);
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
	int type;
	root=newNode(2);
	root->left=newNode(3);
	root->right=NULL;
	root->left->left=NULL;
	root->left->right=NULL;
	printf("Tree is: ");
	print(root);
	printf("\n");
	type=isBST(root);
	if(type==TRUE)
		printf("Is a binery search tree\n");
	else
		printf("Is not a bonary search tree\n");
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
int isBST(struct node* root)
{
	if(root==NULL){
		return;
	}
	else{
		int node_data=root->data;
		isBST(root->left);
		if(node_data < minValue(root))
			return (FALSE);
		else
			return (TRUE);
		isBST(root->right);
		printf("executes....\n");
		if(node_data >maxValue(root))
			return (FALSE);
		else
			return (TRUE);
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
