/*
7. hasPathSum()
We'll define a "root-to-leaf path" to be a sequence of nodes in a tree starting with the root node and proceeding
downward to a leaf (a node with no children). We'll say that an empty tree contains no root-to-leaf paths. So for
example, the following tree has exactly four root-to-leaf paths:
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
void hasPathSum(struct node*,int);
main()
{
	int sum=0;
	struct node* root=BuildTree();
	hasPathSum(root,sum);
}
void hasPathSum(struct node* root,int sum)
{
	static int p=0;
	if(root==NULL)
		return;
	sum=sum+root->data;
	if(root->left==NULL && root->right==NULL)
		printf("sum of path %d = %d\n",++p,sum);
	else{
		hasPathSum(root->left,sum);
		hasPathSum(root->right,sum);
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
	root=insert(root,6);
	return (root);
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
