/*
Given a binary tree, compute its "maxDepth" -- the number of nodes along the longest path from the root node down
to the farthest leaf node. The maxDepth of the empty tree is 0, the maxDepth of the tree on the first page is 3.
*/
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int);
struct node* insert(struct node*,int);
void treeprint(struct node*);
int maxDepth(struct node*);
main()
{
	struct node* root=NULL;
	root=insert(root,2);
	root=insert(root,1);
	root=insert(root,3);
	root=insert(root,5);
//	treeprint(root);
	printf("Depth  is : %d\n",maxDepth(root));
}
int maxDepth(struct node* node) {
	if (node==NULL) {
		return(0);
	}
	else {
	// compute the depth of each subtree
	int lDepth = maxDepth(node->left);
	int rDepth = maxDepth(node->right);
	// use the larger one
	if (lDepth > rDepth) return(lDepth+1);
	else return(rDepth+1);
}
}
void treeprint(struct node* root)
{
	if(root!=NULL){
		treeprint(root->left);
		printf("%d  ",root->data);
		treeprint(root->right);
	}
}
struct node* insert(struct node* root,int data)
{
	if(root== NULL)
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

