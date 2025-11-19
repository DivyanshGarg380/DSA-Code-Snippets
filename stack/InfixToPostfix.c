#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], x;
    printf("Enter Infix: ");
    scanf("%s", infix);

    printf("Postfix: ");

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c))
            printf("%c", c);

        else if (c == '(')
            push(c);

        else if (c == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        }

        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
    }

    while (top != -1)
        printf("%c", pop());

    return 0;
}
