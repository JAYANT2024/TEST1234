#include<stdio.h>
int main ()
{

    int x = 5 , y = 10 , t;

    t = x;
    x = y;
    y = t;

    printf(" x = %d , y = %d",x,y);
    return 0;
}