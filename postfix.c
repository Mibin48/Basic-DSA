#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int intStack[MAX];
int topInt = -1;
char stack[MAX];
int top = -1;
void pushInt(int c) {
    if (topInt == MAX - 1) {
        printf("Int Stack overflow\n");
        return;
    }
    intStack[++topInt] = c;
}

int popInt() {
    if (topInt == -1) {
        printf("Int Stack underflow\n");
        return 0;
    }
    return intStack[topInt--];
}

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0'; // Stack underflow
    }
    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void eval(char *postfix) {
    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            pushInt(c - '0');  // Convert char digit to int
        }
        else if (isOperator(c)) {
            int result = 0;
            int a = popInt();  // Left operand
            int b = popInt();  // Right operand
            switch (c) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = a != 0 ? b / a : 0; break;
                case '^': {
                    result = 1;
                    for (int j = 0; j < a; j++) result *= b;
                    break;
                }
            }
            pushInt(result);
        }
    }
    printf("After evaluation of %s = %d\n", postfix, popInt());
}
void infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    int x=0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) { 
            postfix[k++] = c;
            if(isdigit(c)){
                x=1;
            }
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            if (peek() == '(')
                pop(); 
        }
        else if (isOperator(c)) {
            while (isOperator(peek()) && precedence(c) <= precedence(peek())) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
    if(x=1){
        eval(postfix);
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    return 0;
}
