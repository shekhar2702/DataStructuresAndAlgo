#include <stdio.h>
int main()
{
    int y = 7;
    int z = (--y) + (y = 10);
    printf("%d\n", z);
}
