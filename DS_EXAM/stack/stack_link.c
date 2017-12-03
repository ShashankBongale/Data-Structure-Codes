#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}node;
typedef struct stack
{
  node *head;
}stack;
void create(stack *);
void push(stack *,int );
void pop(stack *,int *);
void disp(stack *);
int emp(stack *);
int main()
{
  stack s;
  create(&s);
  int ch,ele;
  while(1)
  {
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:scanf("%d",&ele);
             push(&s,ele);
             break;
      case 2:if(emp(&s))
              printf("Underflow\n");
            else
            {
              pop(&s,&ele);
              printf("%d\n",ele);
            }
            break;
     case 3:if(emp(&s))
             printf("Empty\n");
            else
            disp(&s);
            break;
     case 4:exit(0);
            break;
    default:printf("Invalid statement\n");
    }
  }
  return 0;
}
void create(stack *s)
{
  s->head=NULL;
}
void push(stack *s,int data)
{
  node *temp;
  temp=(node *)malloc(sizeof(node));
  temp->data=data;
  temp->next=NULL;
  if(s->head==NULL)
   s->head=temp;
  else
  {
    temp->next=s->head;
    s->head=temp;
  }
}
void pop(stack *s,int *data)
{
  *data=s->head->data;
  node *temp=s->head;
  if(s->head->next==NULL)
  {
    free(s->head);
    s->head=NULL;
  }
  else{
    s->head=s->head->next;
    free(temp);
  }
}
int emp(stack *s)
{
  return(s->head==NULL);
}
void disp(stack *s)
{
  node *temp=s->head;
  while(temp!=NULL)
  {
    printf("%d\n",temp->data);
    temp=temp->next;
  }
}
