/*
6. printPostorder()
Given a binary tree, print out the nodes of the tree according to a bottom-up "postorder" traversal -- both subtrees of
a node are printed out completely before the node itself is printed, and each left subtree is printed before the right
subtree.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node *Build123(void);
struct node *newNode(int);
struct node *insert(struct node* node,int data);
void printPostorder(struct node*);
main()
{
	struct node* root=Build123();
	printPostorder(root);
}
struct node *Build123(void)
{
	struct node* root=NULL;
	root=insert(root,4);
	root=insert(root,2);
	root=insert(root,5);
	root=insert(root,1);
	root=insert(root,3);
	return (root);
}
void printPostorder(struct node* root)
{
	if(root!=NULL){
		printPostorder(root->left);
		printPostorder(root->right);
		printf("%d ",root->data);
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
