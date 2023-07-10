/*
读取广义表存储的二叉树
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

/*****************读取广义表*************/
struct node_st *load_(FILE *fp)
{
	int c;
	struct node_st *root;
	c = fgetc(fp);
	/* if error */
	if(c != '(')
	{
		fprintf(stderr,"fgetc():error.\n");
		exit(1);
	}
	c = fgetc(fp);
	if(c == ')')
		return NULL;
	
	root = malloc(sizeof(*root));
	if(root == NULL)
		exit(1);
	root->data = c;
	root->l = load_(fp);
	root->r = load_(fp);
	fgetc(fp);
//	if(fgetc(fp) != ')')
//		exit(1);

	return root;
}

struct node_st *load(const char *path)
{
	FILE *fp;
	struct node_st *root;
	fp = fopen(path,"r");
	if(fp == NULL)
		return NULL;

	root = load_(fp);
	fclose(fp);

	return root;
}



int main()
{
	struct node_st *root;
printf("%d\n",__LINE__);
	
	root = load(FNAME);	
printf("%d\n",__LINE__);
	draw(root);

	exit(0);
}







