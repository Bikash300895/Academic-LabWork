#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dd,mm,yy;
    char c ; //gourbage collector
    scanf("%d %c %d %c %d",&dd,&c,&mm,&c,&yy);

    //Month printing
    if(mm==1)
        printf("January ");
    else if(mm==2)
        printf("Februaty ");
    //Write more 10 condition


    //Print the month
    if(dd==1 || dd>=4)
        printf("%dst",dd);  //1 && 4-31 has st like 31st
    else if(dd==2)
        printf("%dnd",dd);
    else if(dd==3)
        printf("%drd",dd);


    //print the Yeat
    printf(",%d",yy);
}
