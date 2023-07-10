#ifndef LINUX_H__
#define LINUX_H__

//指针指向prev和next节点，即数据中包含的节点而非结构体起始地址
struct list_head
{
	struct list_head *prev;
	struct list_head *next;
};

#define LIST_HEAD_INIT(name)  {&(name),&(name)}

#define LIST_HEAD(name)  struct list_head name = LIST_HEAD_INIT(name)

static inline void __list_add(struct list_head *new,struct list_head *prev,struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new,struct list_head*head)
{
	__list_add(new,head,head->next);
}

#define __list_for_each(pos,head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

//计算node在type类型的结构体中的偏移量
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)  

//利用偏移量得到结构体起始地址
#define container_of(ptr, type, member) \
	({(type *)((char *)ptr - offsetof(type,member));})  

//结构体入口地址
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)







#endif 


