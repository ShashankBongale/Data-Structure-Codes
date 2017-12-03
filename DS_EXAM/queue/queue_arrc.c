#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct queue
{
  int front,rear;
  int a[MAX];
}queue;
void create(queue *);
void enq(queue *,int );
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
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:if(full(&q))
              printf("Overflow\n");
             else
             {
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
             printf("No elements\n");
            else
            disp(&q);
            break;
     case 4:exit(0);
            break;
     default:printf("Invalid Option\n");
    }
  }
  return 0;
}
void create(queue *q)
{
  q->front=q->rear=MAX-1;
}
void enq(queue *q,int data)
{
  q->rear=(q->rear+1)%MAX;
  q->a[q->rear]=data;
}
void deq(queue *q,int *data)
{
  q->front=(q->front+1)%MAX;
  *data=q->a[q->front];
}
int emp(queue *q)
{
  return(q->front==q->rear);
}
int full(queue *q)
{
  return((q->rear+1)%MAX==q->front);
}
void disp(queue *q)
{
  int temp=(q->front+1)%MAX;
  while(temp!=q->rear)
  {
    printf("%d\n",q->a[temp]);
    temp=(temp+1)%MAX;
  }
  printf("%d\n",q->a[temp]);
}
