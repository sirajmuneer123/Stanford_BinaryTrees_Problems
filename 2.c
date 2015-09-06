/*
This problem demonstrates simple binary tree traversal. Given a binary tree, count the number of nodes in the tree.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *newNode(int);
struct node* Build123(void);
int size(struct node*);
main()
{
	struct node* root=Build123();
	printf("the number of nodes is : %d n",size(root));
}
int size(struct node* root)
{
	static int count=0;
	if(root!=NULL){
		size(root->left);
		count++;
		size(root->right);
	}
	return (count);
}
struct node *Build123(void)
{
	struct node *root=NULL;
	root=newNode(2);
	root->left=newNode(1);
	root->right=newNode(3);
	return(root);
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
