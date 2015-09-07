/*
10. doubleTree()
For each node in a binary search tree, create a new duplicate node, and insert the duplicate as the left child of the
original node. The resulting tree should still be a binary search tree.
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
void doubleTree(struct node*);
main()
{
	struct node* tree=BuildTree();
	doubleTree(tree);
	printTree(tree);
}
void doubleTree(struct node* root)
{
	if(root!=NULL){
		doubleTree(root->left);
		insert(root,root->data);
		doubleTree(root->right);
	}else
		return;
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
