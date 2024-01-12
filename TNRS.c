#include<stdio.h>
int add();

int main()
{
    int c;

    c = add();

    printf("Addition of 2 number is %d \n\n",c);

    return 0;
}

int add()
{
    int a,b,sum;
    printf("Enter 2 numbers\n");
    scanf("%d %d",&a,&b);
    sum = a+b;
    return sum;
}
