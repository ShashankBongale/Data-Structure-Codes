#include<stdio.h>
#include<stdlib.h>
#include "link.h"
void ins(LINK **p,ele_t e)
{
LINK *temp;
temp=(LINK *)malloc(sizeof(LINK));
temp->data=e;
temp->next=NULL;
if(*p==NULL)
{
 *p=temp;
}
else
{
 temp->next=*p;
 *p=temp;
}
}
void disp(LINK *p)
{
LINK *temp;
temp=p;
if(temp==NULL)
 printf("Linked list is empty\n");
else
{
 while(temp!=NULL)
 {
   printf("%d\n",temp->data);
   temp=temp->next;
 }
}
}
int rem(LINK **p,ele_t e)
{
int flag=0;
LINK *temp,*prev,*temp1;
prev=*p;
temp=*p;
if(temp==NULL)
 return 0;
else
{
 while(temp->data!=e)
 { 
  flag=1;
  prev=temp;
  temp=temp->next;
 }
if(flag)
{
temp1=temp->next;
prev->next=temp1;
free(temp);
}
else
{
*p=temp->next;
free(temp);
}
return 1;
}
}













