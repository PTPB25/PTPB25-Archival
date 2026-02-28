#include <stdio.h>
#include "stack.h"

void printStack(Stack s)
{
    printf("Stack: ");
    if (isEmpty(s))
    {
        printf("EMPTY\n");
    }
    else
    {
        for (int i = 0; i <= s.idxTop; i++)
        {
            printf("%d ", s.buffer[i]);
        }
        printf("\n");
    }
}

int main()
{
    Stack s;
    ElType val;

    CreateStack(&s);
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
    }

    push(&s, 5);
    push(&s, 3);
    push(&s, 8);
    push(&s, 3);
    printStack(s);

    printf("Top element: %d\n", TOP(s));

    printf("Length: %d\n", length(s));

    pop(&s, &val);
    printf("Popped: %d\n", val);
    printStack(s);

    if (isFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }

    while (!isFull(s))
    {
        push(&s, 1);
    }
    printf("Filled the stack.\n");
    printf("Length after filling: %d\n", length(s));
    printf("Is full: %s\n", isFull(s) ? "true" : "false");

    return 0;
}