#include <stdio.h>
#include "set.h"
int main()
{

    Set s;
    CreateEmpty(&s);
    if (IsEmpty(s))
    {
        printf("Set is empty\n");
    }
    Insert(&s, 5);
    Insert(&s, 3);
    Insert(&s, 8);
    Insert(&s, 3);

    printf("Set elements: ");
    for (int i = 0; i < s.Count; i++)
    {
        printf("%d ", s.Elements[i]);
    }
    printf("\n");

    printf("Is 3 a member? %s\n", IsMember(s, 3) ? "Yes" : "No");
    printf("Is 7 a member? %s\n", IsMember(s, 7) ? "Yes" : "No");

    Delete(&s, 3);
    printf("Set elements after deleting 3: ");
    for (int i = 0; i < s.Count; i++)
    {
        printf("%d ", s.Elements[i]);
    }
    printf("\n");

    if (IsFull(s))
    {
        printf("Set is full\n");
    }
    else
    {
        printf("Set is not full\n");
    }
    return 0;
}