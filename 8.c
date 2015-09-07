/*
8. printPaths()
Given a binary tree, print out all of its root-to-leaf paths, one per line.
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
int printTree(struct node*);
void printPaths(struct node*);
void printPathRec(struct node*,int [],int);
void printArray(int [],int);
main()
{
	int sum;
	struct node* root=BuildTree();
	printPaths(root);
}
void printPaths(struct node* root)
{
	int paths[1000];
	int index=0;
	printPathRec(root,paths,index);
}
void printPathRec(struct node* root,int paths[],int index)
{
	if(root==NULL)
		return;
	paths[index]=root->data;
	index++;
	if(root->left==NULL && root->right==NULL){
		printArray(paths,index);
	}
	else{
		printPathRec(root->left,paths,index);
		printPathRec(root->right,paths,index);
	}	
	
}
void printArray(int paths[],int index)
{
	int i;
	static int p=0;
	printf("path %d : ",++p);
	for(i=0;i<index;i++)
		printf("%d ",paths[i]);
	printf("\n");
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
int printTree(struct node* root)
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
