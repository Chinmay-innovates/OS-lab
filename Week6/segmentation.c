#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct list
{
    int limit;
    int base;
    int seg;
    struct list *next;
} *p;

void insert(struct list *q, int base, int limit, int seg)
{
    if (p == NULL)
    {
        p = malloc(sizeof(struct list));
        p->limit = limit;
        p->base = base;
        p->seg = seg;
        p->next = NULL;
    }
    else
    {
        while (q->next != NULL)
        {
            q = q->next;
            printf("yes");
        }
        q->next = malloc(sizeof(struct list));
        q->limit = limit;
        q->base = base;
        q->seg = seg;
        q->next->next = NULL;
    }
}
int find(struct list *q, int seg)
{
    while (q->seg != seg)
    {
        q = q->next;
    }
    return q->limit;
}
int search(struct list *q, int seg)
{
    while (q->seg != seg)
    {
        q = q->next;
    }
    return q->base;
}
int main()
{
    int seg, offset, limit, base, c, s, physical;
    p = NULL;
    printf("Enter -1 to terminate segmentation value\n");
    do
    {
        printf("Enter segment no :");
        scanf("%d", &seg);
        if (seg != -1)
        {
            printf("Enter base value : ");
            scanf("%d", &base);
            printf("Enter limit value : ");
            scanf("%d", &limit);

            insert(p, base, limit, seg);
        }
    } while (seg != -1);
    printf("Enter offset : ");
    scanf("%d", &offset);
    printf("Enter Segmentation number : ");
    scanf("%d", &seg);
    if (offset < c)
    {
        physical = s + offset;
        printf("Address in physical memory is-- %d\n", physical);
    }
    else
        printf("error");
}
