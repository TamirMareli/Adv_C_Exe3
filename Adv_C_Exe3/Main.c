#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void initStack(Stack* s);
void destroyStack(Stack* s);
void push(Stack* s, char data);
char pop(Stack* s);
int isEmptyStack(const Stack* s);
void flipBetweenHashes(const char* sentence);
int isPalindrome(Stack* s);
void rotateStack(Stack* s, int n);
int isPalindromeEven(Stack* s, int count);
int isPalindromeOdd(Stack* s, int count);
void printStack(Stack* s);

void main()
{
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
	printf("\nCheck the isPalindrome fonctio:\n");
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
}