#include <stdio.h>
#include <ctype.h>

int main()
{
    int i=0;

    char start[]="Tutorials Point";
    while(start[i])
    {
        if(islower(start[i]))
        {
            printf("%c",toupper(start[i]));
            i++;
        }


        else if(isupper(start[i]))
        {
            printf("%c",tolower(start[i]));
            i++;
        }
        else
        {
            printf("%c",start[i]);
            i++;
        }
    }
    return 0;
}
