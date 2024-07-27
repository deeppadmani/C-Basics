#include <stdio.h>

int main()
{
    int num, BitNo, op;
    printf("Enter No: ");
    scanf("%d", &num);

    int i;
    for(i = 31; i >= 0; i--)
        printf("%d", (num >> i) & 1);
    printf("\n");
    
    printf("1)Set a Bit\n2)Clear a bit\n3)Toggle a Bit\n");
    scanf(" %d",&op);
    
    printf("Bit No: ");
    scanf("%d", &BitNo);
    
    switch(op)
    {
        case 1:
            num = num | (1<<BitNo);
        break;
        
        case 2:
            num = num & ~(1<<BitNo);
        break;
        
        case 3:
            num = num ^ (1<<BitNo);
        break;
    }
    
    for(i = 31; i >= 0; i--)
        printf("%d", (num >> i) & 1);
    printf("\n");
    
    return 0;
}
