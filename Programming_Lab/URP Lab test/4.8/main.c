#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Follow the previous program
    int m[2][2];  // 1st is row size , the column

    //take input
    int i,j;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            scanf("%d",&m[i][j]); //give in putlike 1 2
                                                //  3 4
        }
    }

    int m1[2][2];  // 1st is row size , the column

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            scanf("%d",&m1[i][j]); //give in putlike 1 2
                                                //  3 4
        }
    }


    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ",m[i][j]+m1[i][j]); //give in putlike 1 2
                                                //  3 4
        }
        printf("\n");
    }

}
