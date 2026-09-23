#include <stdio.h>
#include <stdlib.h>
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
int isempty(stack *s);
int palindrome(char str[]);

int main()
{
    char str[MAX];

    printf("Enter the string: ");
    scanf("%s", str);

    if (palindrome(str))
        printf("String is Palindrome\n");
    else
        printf("String is NOT Palindrome\n");

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

// Check palindrome
int palindrome(char str[])
{
    stack s;
    int i = 0;
    char x;

    create(&s);

    // Push all characters into stack
    while (str[i] != '\0')
    {
        push(&s, str[i]);
        i++;
    }

    // Compare original string with popped characters
    i = 0;

    while (str[i] != '\0')
    {
        x = pop(&s);

        if (str[i] != x)
        {
            return 0;
        }

        i++;
    }

    return 1;
}
