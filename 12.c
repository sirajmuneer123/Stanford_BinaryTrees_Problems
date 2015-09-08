/*
12. countTrees()
This is not a binary tree programming problem in the ordinary sense -- it's more of a math/combinatorics recursion
problem that happens to use binary trees. (Thanks to Jerry Cain for suggesting this problem.)
*/
#include<stdio.h>
#include<stdlib.h>
int countTree(int);
main()
{
	printf("%d\n",countTree(2));
}
int countTree(int nodes)
{
	if(nodes<=1)
		return 1;
	else{
		int root,left,right;
		int sum=0;
		for(root=1;root<=nodes;root++){
			left=countTree(root-1);
			right=countTree(nodes-root);
			sum +=left*right;
		}	
	return(sum);
	}
}

