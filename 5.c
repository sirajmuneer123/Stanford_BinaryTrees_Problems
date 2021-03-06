/*
5. printTree()
Given a binary search tree (aka an "ordered binary tree"), iterate over the nodes to print them out in increasing
order. So the tree...
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node *BuildTree(void);
struct node *newNode(int);
struct node *insert(struct node* node,int data);
void printTree(struct node*);
main()
{
	struct node* root=BuildTree();

	printTree(root);
}
struct node *BuildTree(void)
{
	struct node* root=NULL;
	root=insert(root,4);
	root=insert(root,2);
	root=insert(root,5);
	root=insert(root,1);
	root=insert(root,3);
	return (root);
}
void printTree(struct node* root)
{
	if(root!=NULL){
		printTree(root->left);
		printf("%d ",root->data);
		printTree(root->right);
	}
	
}
struct node *insert(struct node* node,int data)
{
	
	if(node==NULL)
		return (newNode(data));
	else{	
		if(data <= node->data)
			node->left=insert(node->left,data);
		else
			node->right=insert(node->right,data);
		return(node);
	}

}
struct node *newNode(int data)
{
	struct node* newNode;
	newNode=malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return (newNode);
}
