#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *next;
struct node *prev;
int data;
};
typedef struct node node;
struct start
{
node *h;
node *t;
};
typedef struct start start;
void enq(start *,int );
void deq(start *,int *);
void create(start *);
void disp(start *);
int emp(start *);
void dr(start *,int *);
int main()
{
int ch,ele,ele1;
start s;
create(&s);
while(1)
{
printf("Enter your choice\n");
printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n5.Delete at rear\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element\n");
       scanf("%d",&ele);
       enq(&s,ele);
       break;
case 2:if(emp(&s))
        printf("Underflow\n");
       else
       {
        deq(&s,&ele1);
        printf("%d\n",ele1);
      }
      break;
case 3:if(emp(&s))
	printf("Queue is empty\n");
       disp(&s);
       break;
case 4:exit(0);
       break;
case 5:if(emp(&s))
        printf("Queue is empty\n");
       else
       {
        dr(&s,&ele);
	printf("%d\n",ele);
       }
       break;
default:printf("Invalid statement\n");
}
}
return 0;
}
void create(start *s)
{
s->h=NULL;
s->t=NULL;
}
void enq(start *s,int data)
{
node *temp,*temp2;
temp2=s->h;
temp=(node*)malloc(sizeof(node));
temp->next=NULL;
temp->prev=NULL;
temp->data=data;
if(s->h==NULL)
{
s->h=temp;
s->t=temp;
}
else
{
temp->prev=s->t;
s->t->next=temp;
s->t=temp;
}
}
void disp(start *s)
{
node *temp;
temp=s->h;
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}
void deq(start *s,int *e)
{
node *temp,*temp2;
temp=s->h->next;
*e=s->h->data;
if(s->h==s->t)
{
free(s->h);
s->h=NULL;
s->t=NULL;
}
else
{
temp2=s->h;
s->h=temp;
temp->prev=NULL;
free(temp2);
}
}
int emp(start *s)
{
return(s->h==NULL);
}
void dr(start *s,int *e)
{
node *temp;
*e=s->t->data;
if(s->h==s->t)
{
free(s->h);
s->h=NULL;
s->t=NULL;
}
else
{
temp=s->t;
s->t=s->t->prev;
s->t->next=NULL;
free(temp);
}
}












