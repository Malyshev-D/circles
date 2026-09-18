#include <stdio.h>

int main()
{
    int a[] = {1,2,5,6,3,44};
    int len = sizeof(a) / sizeof(a[0]);
    a[len] = {};
    for (int i=0; i < len; i++)
        printf("%d", a[i]);


}
