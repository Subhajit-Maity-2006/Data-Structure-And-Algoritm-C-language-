#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct stack
{
    int top;
    char arr[MAX];
} stack;

// Function declaration
void create(stack *s);
void push(stack *s, char x);
char peek(stack *s);
char pop(stack *s);
int isempty(stack *s);
int precedence(char x);
void infixtopostfix(char infix[], char postfix[]);

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixtopostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function definition

// Create empty stack
void create(stack *s)
{
    s->top = -1;
}

// Check stack empty or not
int isempty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push
void push(stack *s, char x)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }

    s->top++;
    s->arr[s->top] = x;
}

// Pop
char pop(stack *s)
{
    char temp;

    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    temp = s->arr[s->top];
    s->top--;

    return temp;
}

// Peek
char peek(stack *s)
{
    return s->arr[s->top];
}

// Precedence
int precedence(char x)
{
    if (x == '^')
        return 3;

    if (x == '*' || x == '/' || x == '%')
        return 2;

    if (x == '+' || x == '-')
        return 1;

    return 0;
}

// Infix to Postfix
void infixtopostfix(char infix[], char postfix[])
{
    stack s;
    int i = 0, j = 0;
    char x;

    create(&s);

    while (infix[i] != '\0')
    {
        x = infix[i];

        // a) If symbol is operand
        if (isalnum(x))
        {
            postfix[j] = x;
            j++;
        }

        // b) If symbol is '('
        else if (x == '(')
        {
            push(&s, x);
        }

        // c) If symbol is ')'
        else if (x == ')')
        {
            while (!isempty(&s) && peek(&s) != '(')
            {
                postfix[j] = pop(&s);
                j++;
            }

            // Remove '(' from stack
            if (!isempty(&s))
            {
                pop(&s);
            }
        }

        // d) If symbol is an operator
        else
        {
            while (!isempty(&s) &&
                   peek(&s) != '(' &&
                   precedence(peek(&s)) >= precedence(x))
            {
                postfix[j] = pop(&s);
                j++;
            }

            push(&s, x);
        }

        i++;
    }

    // Pop remaining operators
    while (!isempty(&s))
    {
        postfix[j] = pop(&s);
        j++;
    }

    postfix[j] = '\0';
}
