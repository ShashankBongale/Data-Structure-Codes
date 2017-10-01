#include<stdio.h>
#include<stdlib.h>
#include "q.h"
int main()
{
QUEUE *first=NULL;
int ch,ele,ele1,k;
while(1)
{
 printf("Enter your choice\n");
 printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:printf("Enter element\n");
         scanf("%d",&ele);
	 ins(&first,ele);
         break;
 case 2:k=del(&first,&ele1);
        if(k==0)
         printf("Underflow\n");
        else
         printf("%d\n",ele1);
        break;
 case 3:disp(first);
        break;
 case 4:exit(0);
        break;
 default:printf("Invalid statement\n");
 }
}
return(0);
}
