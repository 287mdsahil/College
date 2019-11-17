#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node *next;
};

struct Queue
{
	struct Node *head;
	struct Node *tail;
};

void queue_init(struct Queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

int queue_isempty(struct Queue *q)
{
	return q->head == NULL;
}

void queue_enqueue(int val, struct Queue *q)
{
	struct Node *newnode;
	newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->val = val;
	newnode->next = NULL;

	if(q->head == NULL)
	{
		q->head = newnode;
		q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
}

int queue_dequeue(struct Queue *q)
{
	if(q->head == NULL)
	{
		//underflow
		return -1;
	}
	else
	{
		int val = q->head->val;
		struct Node *cur = q->head;
		if(q->head == q->tail)
			q->head = q->tail = NULL;
		else
			q->head = cur->next;
		free(cur);
		return val;
	}
}

int queue_head(struct Queue *q)
{
	if(queue_isempty(q))
		return -1;
	else
		return q->head->val;
}

