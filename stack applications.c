#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Initialize stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push item onto stack
void push(Stack* stack, char item) {
    if (stack->top < MAX - 1) {
        stack->items[++stack->top] = item;
    }
}

// Pop item from stack
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0';  // Return null character if stack is empty
}

// Peek at the top item of the stack
char peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    }
    return '\0';
}

// Check if character is an operator
int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

// Get precedence of operators
int precedence(char symbol) {
    if (symbol == '+' || symbol == '-') {
        return 1;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    }
    return 0;
}

// Convert infix expression to postfix expression
void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0, j = 0;
    char symbol;

    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) {
            postfix[j++] = symbol;  // Append operand to postfix expression
        } else if (symbol == '(') {
            push(&stack, symbol);  // Push '(' to stack
        } else if (symbol == ')') {
            while (peek(&stack) != '(') {
                postfix[j++] = pop(&stack);  // Pop until '(' is found
            }
            pop(&stack);  // Remove '(' from stack
        } else if (isOperator(symbol)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(symbol)) {
                postfix[j++] = pop(&stack);  // Pop operators with higher or equal precedence
            }
            push(&stack, symbol);  // Push current operator to stack
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);  // Pop remaining operators
    }

    postfix[j] = '\0';  // Null-terminate postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';  // Remove newline character from input

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
