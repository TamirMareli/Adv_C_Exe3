#include <stdio.h>
#include "Stack.h"
#include "Queue.h"



void main()
{
	printf("Check the Stack fonctio:\n");
	Stack s;
	printf("Check the initStack fonctio:\n");
	initStack(&s);
	printf("Check the push fonctio:\n");
	push(&s, 't');
	push(&s, 'i');
	push(&s, 'C');
	push(&s, 'C');
	push(&s, 'i');
	push(&s, 't');
	printStack(&s);
	printf("Check the isEmptyStack fonctio:\n");
	printf("%d\n", isEmptyStack(&s));
	printf("Check the flipBetweenHashes fonctio:\n");
	char sentence[] = "Remem#reb#thi#carp s#tice\0";
	flipBetweenHashes(sentence);
	printf("\nCheck the isPalindrome fonctio:\t");
	printf("%d\n", isPalindrome(&s));
	printStack(&s);
	printf("Check the pop fonctio:\n");
	pop(&s);
	printStack(&s);
	printf("Check the rotateStack fonctio:\n");
	rotateStack(&s, 3);
	printStack(&s);
	printf("\nCheck the destroyStack fonctio:\n");
	destroyStack(&s);
	
	///Queue:
	printf("\nCheck the Queue fonctio:\n");
	printf("\nCheck the initQueue fonctio:\n");
	Queue q;
	initQueue(&q);
	printf("\nCheck the enqueue fonctio:\n");
		enqueue(&q, 6);
		enqueue(&q, 1);
		enqueue(&q, 5);
		enqueue(&q, 2);
		enqueue(&q, 3);
		enqueue(&q, 1);
		enqueue(&q, 9);
		printQueue(&q);
		printf("\nCheck the dequeue fonctio:\n");
		dequeue(&q);
		printQueue(&q);
		printf("\nCheck the isEmptyQueue fonctio:\n");
		printf("%d", isEmptyQueue(&q));
		printf("\nCheck the rotateQueue fonctio:\n");
		rotateQueue(&q);
		printQueue(&q);
		printf("\nCheck the cutAndReplace fonctio:\n");
		cutAndReplace(&q);
		printQueue(&q);
		printf("\nCheck the sortKidsFirst fonctio:\n");
		sortKidsFirst(&q);
		printQueue(&q);
		printf("\nCheck the destroyQueue fonctio:\n");
		destroyQueue(&q);

}