#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  struct node *next,*prev;
  int data;
}node;
typedef struct queue
{
  node *front,*rear;
}queue;
void create(queue *);
void enq(queue *,int );
void deq(queue *,int *);
int emp(queue *);
void disp(queue *);
int main()
{
  int ele,ch;
  queue q;
  create(&q);
  while(1)
  {
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:scanf("%d",&ele);
             enq(&q,ele);
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
    default:printf("Invalid\n");
    }
  }
  return 0;
}
void create(queue *q)
{
  q->front=q->rear=NULL;
}
void enq(queue *q,int data)
{
  node *temp=(node *)malloc(sizeof(node));
  temp->data=data;
  temp->next=temp->prev=NULL;
  if(q->front==NULL)
  q->front=q->rear=temp;
  else
  {
    q->rear->next=temp;
    temp->prev=q->rear;
    q->rear=temp;
  }
}
void deq(queue *q,int *data)
{
  node *temp;
  *data=q->front->data;
  if(q->front->next==NULL)
  {
    free(q->front);
    q->front=NULL;
    q->rear=NULL;
  }
  else
  {
    temp=q->front;
    q->front->next->prev=NULL;
    q->front=q->front->next;
    free(temp);
  }
}
void disp(queue *q)
{
  node *temp=q->front;
  while(temp!=NULL)
  {
    printf("%d\n",temp->data);
    temp=temp->next;
  }
}
int emp(queue *q)
{
  return(q->front==NULL);
}
