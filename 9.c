/*
9. mirror()
Change a tree so that the roles of the left and right pointers are swapped at every node.
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
void mirror(struct node*); 
main()
{
	int sum;
	struct node* root=BuildTree();
	mirror(root);
	printTree(root);
}
void mirror(struct node* root)
{
	if(root==NULL)
		return;
	else{
		struct node* temp;
		mirror(root->left);
		mirror(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
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
	}else
		return;
	
	
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
