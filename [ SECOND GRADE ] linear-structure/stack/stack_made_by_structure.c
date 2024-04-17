#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int max;
    int top;
    int* data;
} IntStack;

int Initialize(IntStack* stack, int max) {
    stack->top = -1;
    if((stack->data = calloc(max, sizeof(int))) == NULL) {
        return 0;
    }
	stack->max = max;
    return 1;
}

int clearStack(IntStack* stack) {
    free(stack->data);
}

int isFull(IntStack *stack) {
	if(stack->top == stack->max - 1)
		printf("Stack is Full!\n");
	return stack->top == stack->max - 1;
}

int isEmpty(IntStack* stack) {
	if(stack->top == -1)
		printf("Stack is empty!\n");
	return stack->top == -1;
}

void push(IntStack* stack, int data) {
	if(isFull(stack)) {
		printf("stack overflow\npush 실패\n");
		return;
	}
	stack->data[++(stack->top)] = data;
}

void pop(IntStack* stack) {
    if(isEmpty(stack)) {
        printf("pop 실패\n");
        return;
    }
    printf("%d\n", stack->data[stack->top--]);
}

void peek(IntStack* stack) {
	if(isEmpty(stack)) {
        printf("peek 실패\n");
        return;
    }
    printf("%d\n", stack->data[stack->top]);
}

void printStack(IntStack* stack) {
	printf("스택의 최상단\n");
	for(int i = stack->top; i >= 0; i--)
		printf("%d\n", stack->data[i]);
	printf("스택의 최하단\n");
}

int main() {
    IntStack stack;
    int max;
    scanf("%d", &max);
    if(!Initialize(&stack, max)) {
        printf("스택 생성 실패");
        return 0;
    }
    
    while(1) {
		int input;
		scanf("%d", &input);
		if(!input) {
            clearStack(&stack);
            return;
        }

		switch(input) {
			case 1:
				int data;
				scanf("%d", &data);
				push(&stack, data);
				break;
				
			case 2:
				pop(&stack);
				break;
				
			case 3:
                peek(&stack);
				break;
				
			case 4:
				printStack(&stack);
				break;
		}
	}
}