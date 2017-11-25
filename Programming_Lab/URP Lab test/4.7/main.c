/**
*
* Created By Shuvendu Roy Bikash
* Date 20 Aug 2016
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
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

    int sum = 0;
    for(i=0; i<2; i++) //Slecting thr rows
    {
        sum = 0; // sum is initally 0 for each row
        for(j=0; j<2; j++) //Selecting column for each row here for row 0 it will be m[0][0] m[0][1] so on
        {
            sum += m[i][j];
        }
        printf("Row %d sum is = %d\n",i,sum);
    }
    printf("\n");



    for(i=0; i<2; i++)
    {
        sum = 0;
        for(j=0; j<2; j++)
        {
            sum += m[j][i]; //Just change i j from the upper one and copy paste
        }
        printf("Column %d sum is = %d\n",i,sum);
    }
    printf("\n");

}
