#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push element into stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop element from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

// Peek at top element
char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

// Precedence of operators
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return -1;
    }
}

// Convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (isalnum(c)) { // Operand → directly add to postfix
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
        else { // Operator
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
