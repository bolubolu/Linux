#ifndef QUEUE_H__
#define QUEUE_H__

#include "llist.h"

typedef LLIST  QUEUE;
typedef int datatype;

QUEUE *queue_create(int );

int queue_en(QUEUE *,const void *data);

int queue_de(QUEUE *,void *);

void queue_destroy(QUEUE *);





#endif

