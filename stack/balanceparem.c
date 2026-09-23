#include <stdio.h>
#include <stdlib.h>

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
int isempty(stack *s);
int balanced(char str[]);

int main()
{
    char str[MAX];

    printf("Enter the string: ");
    scanf("%s", str);

    if (balanced(str))
        printf("Parentheses are Balanced\n");
    else
        printf("Parentheses are NOT Balanced\n");

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
        return 1;
    else
        return 0;
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

// Check balanced parentheses
int balanced(char str[])
{
    stack s;
    int i = 0;

    create(&s);

    while (str[i] != '\0')
    {
        // If opening parenthesis
        if (str[i] == '(')
        {
            push(&s, str[i]);
        }

        // If closing parenthesis
        else if (str[i] == ')')
        {
            if (isempty(&s))
            {
                return 0;
            }

            pop(&s);
        }

        i++;
    }

    // If stack is empty, parentheses are balanced
    if (isempty(&s))
        return 1;
    else
        return 0;
}
