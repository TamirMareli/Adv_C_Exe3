#include "Queue.h"
#include <stdio.h>

void initQueue(Queue* q);
void destroyQueue(Queue* q);
void enqueue(Queue* q, unsigned int data);
unsigned int dequeue(Queue* q);
int isEmptyQueue(const Queue* q);
void rotateQueue(Queue* q);
void cutAndReplace(Queue* q);
void sortKidsFirst(Queue* q);
void cutAndReplaceOdd(Queue* q, int count);
void cutAndReplaceEven(Queue* q, int count);
void printQueue(Queue* q);
void chance(Queue*q);
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
	if (temp == NULL) { printf("allocation faild\n"); exit(1); }
	temp->data = data;
	temp->next = NULL;
	if (q->head == NULL) {// if the queue is entpy
		q->head = temp;
		q->tail = temp;
		return;
	}
	//the Queue not empty
	q->tail->next = temp;
	q->tail = temp;
	
}

unsigned int dequeue(Queue* q)
{
	if (q->head == NULL) {//if the Queue is empty
		printf("Cannot dequeue an empty queue\n");
		return;
	}
	unsigned int temp= q->head->data;
	intNode* ptr = q->head;
	if (q->head->next==NULL) {//if have only one object
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
	if (q->head == NULL)
		return;
	if (q->head->next == NULL)
		return;

	Queue temp;
	initQueue(&temp);
	while (q->head->next!=NULL) {
		enqueue(&temp, dequeue(q));
	}
	while (temp.head!=NULL) {
		enqueue(q, dequeue(&temp));
	}
}

void cutAndReplace(Queue* q)
{
	if (q == NULL)//if NULL
		return;
	if (q->head == NULL)//if empty
		return;

	Queue temp1;
	initQueue(&temp1);
	int count = 0;
	while (!isEmptyQueue(q)) {
		enqueue(&temp1, dequeue(q));
		count++;
	}
	while (!isEmptyQueue(&temp1)) {
		enqueue(q, dequeue(&temp1));
	}
	if (count % 2 == 1) {
		cutAndReplaceOdd(q, count);
	}
	else {
		cutAndReplaceEven(q, count);
	}
}


void sortKidsFirst(Queue* q)
{
	if (q == NULL)//if NULL
		return;
	if (q->head == NULL)//if empty 
		return;
	if (q->head->next == NULL) //have one object
		return;
	// more one object
	intNode* p = q->head;
	intNode* pN = q->head->next;
	int temp = 0;
	while (p != NULL) {
		while (pN!=NULL) {
			if (p->data > pN->data) {
				temp = p->data;
				p->data = pN->data;
				pN->data = temp;
			}
			pN = pN->next;
		}
		p = p->next;
		pN = p;
	}
	
}

void cutAndReplaceOdd(Queue* q,int count)
{
	int sum = 0;
	int data = 0;
	Queue temp4;
	initQueue(&temp4);
	for (int i = 0; i < count; i++) {
		data = dequeue(q);
		sum += data;
		enqueue(&temp4, data);
	}
	sum = sum / count;
	enqueue(&temp4, sum);
	count++;
	for (int i = 0; i < count; i++) {
		enqueue(q, dequeue(&temp4));
	}
	cutAndReplaceEven(q, count);
}

void cutAndReplaceEven(Queue* q, int count)
{
	Queue temp2;
	initQueue(&temp2);
	Queue* temp3 = (Queue*)malloc(sizeof(Queue));
	if (temp3 == NULL) { printf("allocation faild\n"); exit(1); }
	initQueue(temp3);
	for (int i = 0; i < count / 2; i++) {
		enqueue(&temp2, dequeue(q));
	}
	for (int i = 0; i < count / 2; i++) {
		enqueue(temp3, dequeue(q));
	}

		chance(temp3);

	for (int i = 0; i < count / 2; i++) {
		enqueue(q, dequeue(temp3));
	}
	for (int i = 0; i < count / 2; i++) {
		enqueue(q, dequeue(&temp2));
	}
	free(temp3);

}

void printQueue(Queue* q) {
	int data;
	Queue temp;
	initQueue(&temp);
	while (!isEmptyQueue(q)) {
		data = q->head->data;
		printf("%d\t", data);
		enqueue(&temp, dequeue(q));
	}

	while (!isEmptyQueue(&temp))
	{
		enqueue(q, dequeue(&temp));
	}
}
void chance(Queue* q) {
		Queue temp1, temp2;
		initQueue(&temp1);
		initQueue(&temp2);
	
		while (!isEmptyQueue(q))
		{
			while (!isEmptyQueue(&temp1))
				enqueue(&temp2, dequeue(&temp1));
			enqueue(&temp1, dequeue(q));
			while (!isEmptyQueue(&temp2))
				enqueue(&temp1, dequeue(&temp2));
		}
	
		while (!isEmptyQueue(&temp1))
			enqueue(q, dequeue(&temp1));
	}