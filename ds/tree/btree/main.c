#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define  NAMESIZE   32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

struct node_st
{
	struct score_st data;
	struct node_st *l,*r;
};

static struct node_st *tree = NULL;

void print_s(struct score_st *d)
{
	printf("%d %s %d %d\n",d->id,d->name,d->math,d->chinese);	
}

/**************二叉树按id从小到大插入（与根节点比小的为左大的在右）*********************/
int insert(struct node_st **root,struct score_st *data)
{
	struct node_st *node;
	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = *data;
		node->l = NULL;
		node->r = NULL; 
		
		*root = node;
		return 0;
	}
	if(data->id <= (*root)->data.id)
		return insert(&(*root)->l,data);  //递归思想
	return insert(&(*root)->r,data);
}

/****************按id找节点***************/
struct score_st *find(struct node_st *root, int id)
{
	if(root == NULL)
		return NULL;
	if(id == root->data.id)
		return &root->data;
	if(id < root->data.id)
		return find(root->l,id);  //递归
	else
		return find(root->r,id);
}

/****************横着画树，从上到下先右再根再左***************/
void draw_(struct node_st *root,int level)  
{
	if(root == NULL)
		return ;
	draw_(root->r,level+1);  //递归到最右节点

	for(int i = 0; i < level; i++)  //第level层的节点前面level个tab(5个空格)
		printf("     ");
	print_s(&root->data);   //打印当前节点数据
	draw_(root->l,level+1);  //递归画当前节点左节点
}

void draw(struct node_st *root)
{
	draw_(root,0);
	printf("\n\n");	
//	getchar();   //回车查看每一步平衡
}

/************************平衡二叉树的实现**********************/
static int get_num(struct node_st *root)  //获取节点数
{
	if(root == NULL)
		return 0;
	return get_num(root->l) + 1 + get_num(root->r);
}

static struct node_st *find_min_l(struct node_st *root) //找到最左边的节点
{
	if(root->l == NULL)
		return root;
	return find_min_l(root->l);
}

static void turn_left(struct node_st **root) //右边节点多，左旋 
{
	struct node_st *cur = *root;
	*root = cur->r;   //右节点成为新的根节点
	cur->r = NULL;    //旧根节点的右节点为空
	find_min_l(*root)->l = cur;    //找到新的根节点最后一个左节点，将原根节点挂到该节点的左边
//	draw(tree);
}

static struct node_st *find_min_r(struct node_st *root)  //找到当前节点最右边的节点
{
	if(root->r == NULL)
		return root;
	return find_min_r(root->r);
}

static void turn_right(struct node_st **root)  //左边节点多，右旋
{
	struct node_st *cur = *root;
	*root = cur->l;    //左节点成为新的根节点
	cur->l = NULL;     //旧根节点的左节点为空
	find_min_r(*root)->r = cur;    //将原根节点接到新根的最后一个右节点的右边
//	draw(tree);
}

void balance(struct node_st **root)   //平衡二叉树
{
	if(*root == NULL)
		return ;

	while(1)
	{
		int sub = get_num((*root)->l) - get_num((*root)->r);
		if(sub >= -1 && sub <=1) //左右节点总数差值<=1则为平衡
			break;
		if(sub < -1)
			turn_left(root);
		else 
			turn_right(root);
	}
	balance(&(*root)->l);
	balance(&(*root)->r);
}

/***********删除对应id的树的节点(左孩子作为新根，右孩子挂到原左孩子的最右)**********/
void delete(struct node_st **root,int id)
{
	struct node_st **node = root;
	while(*node != NULL && (*node)->data.id != id)  //找==id的节点
	{
		if(id < ((*node)->data.id))
			node = &(*node)->l;
		else 
			node = &(*node)->r;
	}
	if(*node == NULL)   
		return ;    //找不到则返回空

	struct node_st *cur = *node;
	if(cur->l == NULL)
		*node = cur->r;   //左节点为空则令右节点为新根
	else 
	{
		*node = cur->l;   //左节点为新根
		find_min_r(cur->l)->r = cur->r;  //原右边节点接到新根的最右
	}
	free(cur);
}

#if 0
void travel(struct node_st *root)    //先序遍历(根左右)
{
	if(root == NULL)
		return ;
	print_s(&root->data);
	travel(root->l);
	travel(root->r);
}
#endif

void travel(struct node_st *root)    //按层遍历(利用队列)
{
	QUEUE *qu;
	struct node_st *cur;
	qu = queue_create(sizeof(struct node_st *));
	if(qu == NULL)
		return ;

	queue_en(qu,&root);

	while(1)
	{
		int ret = queue_de(qu,&cur);
		if(ret == -1)
			break;
		print_s(&cur->data);
		
		if(cur->l != NULL)
			queue_en(qu,&cur->l);
		if(cur->r != NULL)
			queue_en(qu,&cur->r);
	}
	queue_destroy(qu);
	
}

int main()
{
	int arr[] = {1,2,3,7,6,5,9,8,4};
	struct score_st tmp;	

	for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		tmp.id = arr[i];
		snprintf(tmp.name,NAMESIZE,"stu%d",arr[i]);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;		

		insert(&tree,&tmp);
	}
#if 0
	int tmpid = 2;
	struct score_st *datap;
	datap = find(tree,tmpid);
	if(datap == NULL)
		printf("Can not find the id %d\n",tmpid);
	else 
		print_s(datap);	
#endif

	draw(tree);
//	printf("\n");

	balance(&tree);
	draw(tree);
	travel(tree);
/*
	int tmpid2 = 5;
	delete(&tree,tmpid2);
	draw(tree);	
*/

	exit(0);
}







