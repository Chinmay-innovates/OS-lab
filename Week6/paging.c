#include <stdio.h>
#include <conio.h>
int main()
{
    int ms, ps, nop, np, rempages, pa, offset;
    int s[10], fno[10][20];
    int i, j, x, y;
    printf("\n Enter memory size: ");
    scanf("%d", &ms);

    printf("\n Enter page size: ");
    scanf("%d", &ps);

    nop = ms / ps;

    printf("\n no.of pages  availabe in the memory is %d", nop);

    printf("\n Enter no.of process: ");
    scanf("%d", &np);
    rempages = nop;
    for (i = 1; i <= np; i++)
    {
        printf("Enter no. of pages require for p[%d] : ", i);
        scanf("%d", &s[i]);
        if (s[i] > rempages)
        {
            printf("Memory is Full!");
            break;
        }
        rempages -= s[i];
        printf("\n Enter pageTable for p[%d]: ", i);
        for (j = 0; j < s[i]; j++)
            scanf("%d", &fno[i][j]);
    }
    printf("Enter logical address to find physical address");
    printf("\n Enter (process no. ,page no. , offset)");
    scanf("%d%d%d", &x, &y, &offset);
    if (x > np || y >= s[i] || offset >= ps)
        printf("\n\nInvalid process or page no or offset");
    else
    {
        pa = fno[x][y] * ps + offset;
        printf("\n the physical address is --%d", pa);
    }
    getch();
}