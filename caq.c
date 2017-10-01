#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct queue
{
int a[max];
int r;
int f;
int count;
}queue;
void create(queue *);
void enq(queue *,int);
void deq(queue *,int *);
int full(queue *);
int emp(queue *);
void disp(queue *);
int main()
{
int ch,ele;
queue q;
create(&q);
while(1)
{
printf("Enter choice\n");
printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:if(full(&q))
       printf("Overflow\n");
       else
       {
        printf("Enter an element\n");
        scanf("%d",&ele);
        enq(&q,ele);
       }
       break;
case 2:if(emp(&q))
        printf("Underflow\n");
       else
       {
        deq(&q,&ele);
        printf("%d\n",ele);
       }
       break;
case 3:if(emp(&q))
        printf("Underflow\n");
       else
	disp(&q);
       break;
case 4:exit(0);
       break;
default:printf("Invalid option\n");
}
}
return 0;
}
void create(queue *q)
{
q->r=-1;
q->f=0;
q->count=0;
}
void enq(queue *q,int data)
{
q->r=(q->r+1)%max;
q->a[q->r]=data;
q->count++;
}
void deq(queue *q,int *data)
{
*data=q->a[q->f];
q->f=(q->f+1)%max;
q->count--;
}
int full(queue *q)
{
return(q->count==max);
}
int emp(queue *q)
{
return(q->count==0);
}
void disp(queue *q)
{
int i;
for(i=q->f;i<=q->r;i++)
{
printf("%d\n",q->a[i]);
}
}

