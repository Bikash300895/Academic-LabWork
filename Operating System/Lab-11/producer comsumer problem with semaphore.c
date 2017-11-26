#include<stdio.h>
void main()
{
    int bufsize = 3;
    int buffer[bufsize], in, out, produce, consume, choice=0;
    in = 0;
    out = 0;

    while(choice !=3)
    {
        printf("\n1. Produce \t 2. Consume \t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            if(in==bufsize)
                printf("\nBuffer is Full");
            else
            {
                printf("\nEnter the value: ");
                scanf("%d", &produce);
                buffer[in] = produce;
                in = in+1;
            }
            break;
        case 2:
            if(in == out)
                printf("\nBuffer is Empty");
            else
            {
                consume = buffer[out];
                printf("\nThe consumed value is %d", consume);
                out = out + 1;
            }
            break;
        }
    }
}
