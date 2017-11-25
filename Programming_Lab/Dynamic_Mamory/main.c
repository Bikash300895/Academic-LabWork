#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int *ptr;
    ptr=(int *)malloc(n*sizeof(int));

    int i;
    for(i=0; i<n; i++)
        *(ptr+i)=i;
    for(i=0;i<n;i++)
        printf("%d ",*(ptr+i));

    //ptr=(int *)realloc(ptr,5);
    return 0;
}
