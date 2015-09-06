/*
1. build123()
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
void printtree(struct node*);
main()
{
	struct node* root=Build123();

	printtree(root);
}
struct node *Build123(void)
{
	struct node* root=NULL;
	root=insert(root,2);
	root=insert(root,1);
	root=insert(root,3);
	return (root);
}
void printtree(struct node* root)
{
	if(root!=NULL){
		printtree(root->left);
		printf("%d ",root->data);
		printtree(root->right);
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
