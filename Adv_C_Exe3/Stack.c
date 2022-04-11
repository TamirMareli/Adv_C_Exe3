#include "Stack.h"
#include <stdio.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	if (s->head == NULL)//if the stack is empty
		return;

	Stack* temp = s;
	while (s->head->next != NULL) {
		s->head = s->head->next;
		free(temp->head);
		temp = s;
	}
	free(temp->head);
}

void push(Stack* s, char data)
{
	charNode* node = (charNode*)malloc(sizeof(charNode));
	if (node == NULL) { printf("alloction faild\n"); exit(1); }
	node->data = data;

	if (s->head == NULL) {//is the stack is empty
		s->head = node;
		s->head->next = NULL;
		return;
	}
	
	node->next = s->head;
	s->head = node;

}

char pop(Stack* s)
{
	char pop = s->head->data;
	charNode* temp = s->head;
	s->head = s->head->next;
	free(temp);
	return pop;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;
	return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	if (sentence == NULL)//the sentence is empty
		return;
	char* ptr = sentence;
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	if (temp == NULL) { printf("allocation fild\n"); exit(1); }
	initStack(temp);

	while (ptr * != '/0') {//chack that we no on the end of sentence
		if (prt *= = '#') {
			prt++;
			while (ptr * != '#' && ptr * != '/0') {
				push(temp, ptr*);
				ptr++;
			}
			if (ptr* == '#') {
				while (!isEmptyStack(temp) {
					printf("%c", pop(temp));
				}
				ptr++;
			}
		}
		else{
			printf("%c", ptr*);
			ptr++;
		}
		}
	destroyStack(temp);
	free(temp);
	}

int isPalindrome(Stack* s)
{
	if (s->head == NULL)//if the stack is empty
		return 1;
	int count = 0;
	Stack sCount;
	initStack(&sCount);
	while (!isEmptyStack(s)) {
		push(&sCount, pop(s));
		count++;
	}
	while (!isEmptyStack(s)) {
		push(s, pop(&sCount));
	}
	destroyStack(&sCount);
	if (count % 2 == 0) {
		return isPalindromeEven(s,count);
	}
	else {
		return isPalindromeOdd(s,count);
	}

}

void rotateStack(Stack* s, int n)
{
	// add your code here
}

int isPalindromeEven(Stack* s, int count) {
	int check = 1;
	Stack temp1, temp2, temp3, temp4;
	initStack(&temp1);
	initStack(&temp2);
	initStack(&temp3);
	initStack(&temp4);

	for (int i = 0; i < count / 2; i++) {
		posh(&temp1, pop(s));
	}
	for (int i = 0; i < count / 2; i++) {
		posh(&temp4, pop(s));
	}
	for (int i = 0; i < count / 2; i++) {
		posh(&temp2, pop(&temp4));
	}

	for (int i = 0; i < count / 2; i++) {
		if (temp1.head != temp2.head) {
			check = 0;
		}
		push(&temp3, pop(&temp1));
		push(s, &temp2);
	}
	for (int i = 0; i < count / 2; i++) {
		push(s, &temp3);
	}
	destroyStack(&temp1);
	destroyStack(&temp2);
	destroyStack(&temp3);
	destroyStack(&temp4);
	destroyStack(&temp5);
	return check;
}

int isPalindromeOdd(Stack* s, int count) {
	int check = 1;
	Stack temp1, temp2, temp3, temp4, temp5;
	initStack(&temp1);
	initStack(&temp2);
	initStack(&temp3);
	initStack(&temp4);
	initStack(&temp5);

	for (int i = 0; i < count / 2; i++) {
		posh(&temp1, pop(s));
	}
	posh(&temp5, pop(s));
	for (int i = 0; i < count / 2; i++) {
		posh(&temp4, pop(s));
	}
	for (int i = 0; i < count / 2; i++) {
		posh(&temp2, pop(&temp4));
	}
	
	for (int i = 0; i < count / 2; i++) {
		if (temp1.head != temp2.head) {
			check = 0;
		}
		push(&temp3, pop(&temp1));
		push(s, &temp2);
	}
	push(s, pop(&temp5));
	for (int i = 0; i < count / 2; i++) {
		push(s, &temp3);
	}
	destroyStack(&temp1);
	destroyStack(&temp2);
	destroyStack(&temp3);
	destroyStack(&temp4);
	destroyStack(&temp5);
	return check;
}