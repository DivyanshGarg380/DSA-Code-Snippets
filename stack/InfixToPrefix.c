#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n/2; i++) {
        char t = exp[i];
        exp[i] = exp[n-i-1];
        exp[n-i-1] = t;
    }
}

void swapBrackets(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter Infix: ");
    scanf("%s", infix);

    reverse(infix);
    swapBrackets(infix);

    int k = 0;
    top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c))
            postfix[k++] = c;

        else if (c == '(')
            push(c);

        else if (c == ')') {
            char x;
            while ((x = pop()) != '(')
                postfix[k++] = x;
        }

        else {
            while (top != -1 && precedence(stack[top]) > precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    reverse(postfix);

    printf("Prefix: %s", postfix);

    return 0;
}
