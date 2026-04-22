#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '#';
    return stack[top--];
}

int isMatchingPair(char a, char b) {
    if (a == '(' && b == ')') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '[' && b == ']') return 1;
    return 0;
}

int isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else {
            char popped = pop();
            if (!isMatchingPair(popped, exp[i]))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    printf("Name: animesh yadav\nPRN: 25070521212\n\n");

    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}