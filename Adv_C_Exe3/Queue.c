#include "Queue.h"
#include <stdio.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	if (q->head == NULL)
		return;
	intNode* temp = q->head;

	while (q->head->next != NULL) {
		q->head = q->head->next;
		free(temp);
		temp = q->head;
	}
	free(temp);
	q->head = NULL;
	q->tail = NULL;

}

void enqueue(Queue* q, unsigned int data)
{
	intNode* temp = (intNode*)malloc(sizeof(intNode));
	if (temp == NULL) { printf("allocation faild\n"; exit(1)); }
	temp->data = data;
	temp->next = NULL;
	if (q->head == NULL) {// if the queue is entpy
		q->head = temp;
		q->tail = temp;
		return;
	}
	//the Queue not empty
	temp->next = q->tail;
	q->tail = temp;
}

unsigned int dequeue(Queue* q)
{
	if (q->head == NULL) {//if the Queue is empty
		printf("Cannot dequeue an empty queue\n");
		return;
	}
	unsigned int temp;
	intNode* ptr = q->head;
	if (q->head->next) {//if have only one object
		temp = q->head->data;
		q->head = NULL;
		q->tail = NULL;
		free(ptr);
		return temp;
	}
	//if have more than one object
	q->head = q->head->next;
	free(ptr);
	return temp;
		
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL)
		return 1;
		return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{

}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
}