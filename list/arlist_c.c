#include<stdio.h>
#include "arlist.h"
int main()
{
int ele,ch;
int k;
ARLIST al;
al.last=-1;
do
{
printf("Enter your choice\n");
printf("1.Insert\n2.Remove\n3.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:if(over(&al))
        printf("Overflow\n");
       else
       {
       printf("Enter element\n");
       scanf("%d",&ele);
       ins(&al,ele);
       }
       break;
case 2:if(emp(&al))
        printf("underflow\n");
       else 
       {
         k=rem(&al);
         printf("%d\n",k);
       }
       break;
case 3:disp(&al);
       break;
}
}while(ch<4);
return 0;
}
       
