#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int intStack[MAX];
int topInt = -1;

char charStack[MAX];
int topChar = -1;

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

// Char stack functions
void pushChar(char c) {
    if (topChar == MAX - 1) {
        printf("Char Stack overflow\n");
        return;
    }
    charStack[++topChar] = c;
}

char popChar() {
    if (topChar == -1) return '\0';
    return charStack[topChar--];
}

char peekChar() {
    if (topChar == -1) return '\0';
    return charStack[topChar];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void eval(char *prefix) {
    strrev(prefix);
    for (int i = 0; i < strlen(prefix); i++) {
        char c = prefix[i];
        if (isdigit(c)) {
            pushInt(c - '0');  // Convert char digit to int
        }
        else if (isOperator(c)) {
            int result = 0;
            int b = popInt();  // Left operand
            int a = popInt();  // Right operand
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
    strrev(prefix);
    printf("After evaluation of %s = %d\n", prefix, popInt());
}

void infixToPrefix(char *infix, char *prefix) {
    strrev(infix);
    int i = 0, j = 0;
    int containsDigit = 0;

    while (infix[i] != '\0') {
        char c = infix[i];
        if (isalnum(c)) {
            prefix[j++] = c;
            if (isdigit(c)) containsDigit = 1;
        }
        else if (c == ')') {
            pushChar(c);
        }
        else if (c == '(') {
            while (peekChar() != ')' && topChar != -1)
                prefix[j++] = popChar();
            popChar(); 
        }
        else if (isOperator(c)) {
            while (isOperator(peekChar()) && precedence(c) < precedence(peekChar())) {
                prefix[j++] = popChar();
            }
            pushChar(c);
        }
        i++;
    }

    while (topChar != -1) {
        prefix[j++] = popChar();
    }
    prefix[j] = '\0';
    strrev(prefix);
    printf("Prefix expression: %s\n", prefix);

    if (containsDigit)
        eval(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    return 0;
}
