#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
struct node *next;
int data;
}node;
typedef struct queue
{
struct node *head;
}queue;
void create(queue *);
void enq(queue *,int);
int emp(queue *);
void deq(queue *,int *);
void disp(queue *);
int main()
{
int ch,ele;
queue h;
create(&h);
while(1)
{
printf("Enter choice\n");
printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Insert element\n");
       scanf("%d",&ele);
       enq(&h,ele);
       break;
case 2:if(emp(&h))
        printf("Underflow\n");
       else
       {
        deq(&h,&ele);
        printf("%d\n",ele);
       }
       break;
case 3:if(emp(&h))
       printf("No elements\n");
       else
       disp(&h);
       break;
case 4:exit(0);
       break;
default:printf("Invalid option\n");
}
}
return 0;
}
void create(queue *h)
{
h->head=NULL;
}
void enq(queue *h,int data)
{
node *temp,*p;
p=h->head;
temp=(node *)malloc(sizeof(node));
temp->data=data;
temp->next=NULL;
if(h->head==NULL)
 h->head=temp;
else
{
while(p->next!=NULL)
 p=p->next;
p->next=temp;
}
}
void deq(queue *h,int *ele)
{
node *p;
p=h->head;
*ele=h->head->data;
if(p->next==NULL)
{
free(p);
h->head=NULL;
}
else
{
h->head=p->next;;
free(p);
}
}
void disp(queue *h)
{
node *temp;
temp=h->head;
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}
int emp(queue *h)
{
return(h->head==NULL);
}
