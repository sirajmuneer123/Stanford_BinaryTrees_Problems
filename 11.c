/*
11. sameTree()
Given two binary trees, return true if they are structurally identical -- they are made of nodes with the same values
arranged in the same way. (Thanks to Julie Zelenski for suggesting this problem.)
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data);
struct node *insert(struct node*,int);
struct node *BuildTree(void);
void printTree(struct node*);
int sameTree(struct node*,struct node*);
main()
{
	struct node* tree1=BuildTree();
	struct node* tree2=BuildTree();
	int x=sameTree(tree1,tree2);
	printf("re   %d\n",x);
	printTree(tree);
}
int sameTree(struct node* a,struct node* b)
{
	if(a==NULL && b==NULL)
		return (1);
	else if(a!=NULL && b!=NULL)
		return (a->data == b->data && sameTree(a->left,b->left) &&sameTree(a->right,b->right));
	else
		return(0);
	
}
void printTree(struct node* root)
{
	if(root!=NULL){
		printTree(root->left);	
		printf("%d ",root->data);
		printTree(root->right);
	}
}
struct node *BuildTree(void)
{
	struct node* root=NULL;
	root=insert(root,2);
	root=insert(root,1);
	root=insert(root,3);
	return(root);
}
struct node *insert(struct node* root,int data)
{
	if(root==NULL)
		return(newNode(data));
	else{
		if(data <= root->data)
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
