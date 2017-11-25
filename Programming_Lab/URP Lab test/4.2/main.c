/**
* Created By Shuvendu Roy BIkash
* Date 20 Aug 2016
*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main()
{
    char name[50];
    gets(name);

    int length = strlen(name); //function strlen() is definde in header string.h

    int i;
    for(i=0; i<length; i++)
    {
        if(name[i]>=48 && name[i]<=56)  //In ASCII value 0==48 to 9==57
            printf("%c",name[i]+1);
        else if(name[i] == 57)
            printf("0");

        else if(name[i]>=65 && name[i]<=89)  //In ASCII value A==65 to Z==90
            printf("%c",name[i]+1);
        else if(name[i] == 90)
            printf("A");

        else if(name[i]>=97 && name[i]<=121)  //In ASCII value a=97 to z=122
            printf("%c",name[i]+1);
        else if(name[i] == 122)
            printf("a");
	else printf("*"); // The last condition

    }
}
