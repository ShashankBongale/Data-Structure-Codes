#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  struct node *next;
  int data;
}node;
typedef struct queue
{
  node *front;
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
  q->front=NULL;
}
void enq(queue *q,int data)
{
  node *temp=(node *)malloc(sizeof(node));
  node *temp1;
  temp->data=data;
  temp->next=NULL;
  if(q->front==NULL)
   q->front=temp;
  else
  {
    temp1=q->front;
    while(temp1->next!=NULL)
     temp1=temp1->next;
    temp1->next=temp;
  }
}
void deq(queue *q,int *data)
{
  *data=q->front->data;
  node *temp;
  if(q->front->next==NULL)
  {
    free(q->front);
    q->front=NULL;
  }
  else
  {
    temp=q->front;
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
