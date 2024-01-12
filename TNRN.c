#include <stdio.h>

void add();  // Take nothing and Return Nothing

int main() {

   add();

   return 0;
}


void add()
{
   int a,b;

   printf("Enter 2 number\n");
   scanf("%d %d",&a,&b);

   printf("Addition = %d\n\n",a+b);

}
