/*
4. minValue()
Given a non-empty binary search tree (an ordered binary tree), return the minimum data value found in that tree.
Note that it is not necessary to search the entire tree. A maxValue() function is structurally very similar to this
function. This can be solved with recursion or with a simple while loop.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;	
	struct node* left;
	struct node* right;
};
struct node* newNode(int);
struct node* insert(struct node*,int);
int minValue(struct node*);
main()
{
	struct node* root=NULL;
	root=insert(root,5);
	root=insert(root,4);
	root=insert(root,6);
	root=insert(root,3);
	printf("min value is : %d\n",minValue(root));
}
int minValue(struct node* root)
{
	struct node* current=root;
	while(current->left!=NULL){
		current=current->left;
	}
	return (current->data);
	
}
struct node* insert(struct node* root,int data)
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
struct node* newNode(int data)
{
	struct node* node;
	node=malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
