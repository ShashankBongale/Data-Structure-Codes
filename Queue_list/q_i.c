#include<stdlib.h>
#include "q.h"
#include<stdio.h>
void ins(QUEUE **p,ele_t e)
{
QUEUE *temp,*temp1;
temp1=*p;
temp=(QUEUE *)malloc(sizeof(QUEUE));
temp->data=e;
temp->next=NULL;
if(*p==NULL)
{
 *p=temp;
}
else
{
 while(temp1->next!=NULL)
 {
  temp1=temp1->next;
 }
 temp1->next=temp;
}
}
void disp(QUEUE *p)
{
QUEUE *temp;
temp=p;
if(temp==NULL)
 printf("Queue is empty\n");
else
{
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}
}
int del(QUEUE **p,ele_t *e)
{
QUEUE *temp,*temp1;
temp=*p;
if(temp==NULL)
 return 0;
else
{
 temp1=temp->next;
 *p=temp1;
 *e=temp->data;
  free(temp);
  return 1;
}
}

