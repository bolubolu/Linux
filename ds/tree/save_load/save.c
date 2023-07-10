/*
利用广义表来存储二叉树

*/


#include <stdio.h>
#include <stdlib.h>

#define  FNAME   "/tmp/out"


struct node_st
{
	char data;
	struct node_st *l,*r;
};

static struct node_st *tree = NULL;


/**************二叉树按id从小到大插入（与根节点比小的为左大的在右）*********************/
int insert(struct node_st **root,int data)
{
	struct node_st *node;
	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = data;
		node->l = NULL;
		node->r = NULL; 
		
		*root = node;
		return 0;
	}
	if(data <= (*root)->data)
		return insert(&(*root)->l,data);  //递归思想
	return insert(&(*root)->r,data);
}


/****************横着画树，从上到下先右再根再左***************/
void draw_(struct node_st *root,int level)  
{
	if(root == NULL)
		return ;
	draw_(root->r,level+1);  //递归到最右节点

	for(int i = 0; i < level; i++)  //第level层的节点前面level个tab(5个空格)
		printf("     ");
	printf("%c\n",root->data);   //打印当前节点数据
	draw_(root->l,level+1);  //递归画当前节点左节点
}

void draw(struct node_st *root)
{
	draw_(root,0);
	printf("\n\n");	
}

/***************递归实现广义表存储二叉树*************/
int save_(struct node_st *root,FILE *fp)
{
	fputc('(',fp);
	/* if error */
	if(root == NULL)
	{
		fputc(')',fp);
		return 0;
	}
	fputc(root->data,fp);
	/* if error */
	save_(root->l,fp);
	save_(root->r,fp);

	fputc(')',fp);
	/* if error */
	return 0;
}

int save(struct node_st *root,const char *path)
{
	FILE *fp;

	fp = fopen(path,"w");
	if(fp == NULL)
		return -1;
	save_(tree,fp);
	return 0;
}



int main()
{
	char arr[] = "cefadjlh";

	for(int i = 0; i < sizeof(arr)/sizeof(*arr)-1; i++)  //-1除去\0
	{
		insert(&tree,arr[i]);
	}

	draw(tree);

	save(tree,FNAME);

	exit(0);
}







