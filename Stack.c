include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of stack

// Stack structure
typedef struct
{
    int top;
    int arr[MAX];
} Stack;

// Function to initialize stack
void initialize(Stack *s) 
{
    s->top = -1;
}

// Function to check if stack is full
int isFull(Stack *s) 
{
    return s->top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) 
{
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Function to get the top element of the stack
int peek(Stack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function to display the stack
void display(Stack *s)
{
    if (isEmpty(s))
    
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Main function
int main() 
{
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60); // Stack Overflow case

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));

    display(&stack);

    return 0;
}
