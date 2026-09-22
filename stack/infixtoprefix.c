#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct stack
{
    int top;
    char arr[MAX];
} stack;

// Function declaration
void create(stack *s);
void push(stack *s, char x);
char pop(stack *s);
char peek(stack *s);
int isempty(stack *s);
int precedence(char x);
void reverse(char str[]);
void swapparenthesis(char str[]);
void infixtoprefix(char infix[], char prefix[]);

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixtoprefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

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

// Reverse the expression
void reverse(char str[])
{
    int i, j;
    char temp;

    i = 0;
    j = strlen(str) - 1;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

// Interchange '(' and ')'
void swapparenthesis(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }

        i++;
    }
}

// Infix to Prefix
void infixtoprefix(char infix[], char prefix[])
{
    stack s;
    char postfix[MAX];
    int i = 0, j = 0;
    char x;

    // Step 1: Reverse infix expression
    reverse(infix);

    // Step 2: Interchange '(' and ')'
    swapparenthesis(infix);

    create(&s);

    // Step 3: Convert reversed expression to postfix
    while (infix[i] != '\0')
    {
        x = infix[i];

        // If symbol is operand
        if (isalnum(x))
        {
            postfix[j] = x;
            j++;
        }

        // If symbol is '('
        else if (x == '(')
        {
            push(&s, x);
        }

        // If symbol is ')'
        else if (x == ')')
        {
            while (!isempty(&s) && peek(&s) != '(')
            {
                postfix[j] = pop(&s);
                j++;
            }

            // Remove '('
            if (!isempty(&s))
            {
                pop(&s);
            }
        }

        // If symbol is operator
        else
        {
            while (!isempty(&s) &&
                   peek(&s) != '(' &&
                   precedence(peek(&s)) > precedence(x))
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

    // Step 4: Reverse postfix to get prefix
    reverse(postfix);

    strcpy(prefix, postfix);
}
