#include<stdio.h>
#include<stdlib.h>
#include "link.h"
int main()
{
int ele,ch,k,ele1;
LINK *first=NULL;
while(1)
{
printf("Enter your choice\n");
printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element to be inserted\n");
       scanf("%d",&ele);
       ins(&first,ele);
       break;
case 2:printf("Enter element to be deleted\n");
       scanf("%d",&ele1);
       k=rem(&first,ele1);
       if(k==0)
        printf("Underflow\n");
       else
        printf("Deleted Succesfully\n");
       break;
case 3:disp(first);
       break;
case 4:exit(0);
       break;
default:printf("Invalid option\n");
}
}
return 0;
}
       
