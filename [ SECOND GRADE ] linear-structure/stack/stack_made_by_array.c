#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3

int stack[STACK_SIZE];
int top = -1;

int isFull() {
	if(top == STACK_SIZE - 1)
		printf("Stack is Full!\n");
	return top == STACK_SIZE - 1;
}

int isEmpty() {
	if(top == -1)
		printf("Stack is empty!\n");
	return top == -1;
}

void push(int data) {
	if(isFull()) {
		printf("stack overflow\n");
		return;
	}
	stack[++top] = data;
}

int pop() {
	if(isEmpty())
		return top;
	return stack[--top];
}

int peek() {
	if(isEmpty())
		return top;
	return stack[top];
}

void printStack() {
	printf("스택의 최상단\n");
	for(int i = 0; i <= top; i++)
		printf("%d\n", stack[i]);
	printf("스택의 최하단\n");
}

int main() {
	while(1) {
		int input;
		scanf("%d", &input);
		if(!input) return;
		switch(input) {
			case 1:
				int data;
				scanf("%d", &data);
				push(data);
				break;
				
			case 2:
				printf("pop: %d", pop());
				break;
				
			case 3:
				printf("peek: %d", peek());
				break;
				
			case 4:
				printStack();
				break;
		}
	}
	return 0;
}