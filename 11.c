/*
11. sameTree()
Given two binary trees, return true if they are structurally identical -- they are made of nodes with the same values
arranged in the same way. (Thanks to Julie Zelenski for suggesting this problem.)
*/
#include<stdio.h>
#include<stdlib.h>
# define TRUE 1
# define FALSE 0
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data);
struct node *insert(struct node*,int);
struct node *BuildTree1(void);
struct node *BuildTree2(void);
void printTree(struct node*);
int sameTree(struct node*,struct node*);
main()
{
	struct node* tree1=BuildTree1();
	struct node* tree2=BuildTree2();
	int type=sameTree(tree1,tree2);
	if(type==TRUE)
		printf("same tree\n");
	else
		printf("not same tree\n");
}
int sameTree(struct node* a,struct node* b)
{
	if(a==NULL && b==NULL)
		return (TRUE);
	else if(a!=NULL && b!=NULL)
		return (a->data == b->data && sameTree(a->left,b->left) &&sameTree(a->right,b->right));
	else
		return(FALSE);
	
}
struct node *BuildTree1(void)
{
	struct node* root=NULL;
	root=insert(root,2);
	root=insert(root,1);
	root=insert(root,3);
	return(root);
}
struct node *BuildTree2(void)
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
