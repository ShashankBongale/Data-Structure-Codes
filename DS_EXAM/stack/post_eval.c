#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
  float data;
  struct node *next;
}node;
typedef struct stack
{
  node *head;
}stack;
void create(stack *);
void push(stack *,float );
void pop(stack *,float *);
void disp(stack *);
int emp(stack *);
float eval(float ,float ,char );
int main()
{
  stack s;
  create(&s);
  float op1,op2,res;
  char post[100];
  printf("Enter a valid postfix expression\n");
  scanf("%s",post);
  int i=0;
  int flag=0;
  int flag1=0;
  while(post[i]!='\0')
  {
    if(isdigit(post[i]))
    {
      push(&s,post[i]-'0');
    }
    else
    {
      if(emp(&s))
      {
        printf("Invalid postfix expression\n");
        flag=1;
        break;
      }
      else
      pop(&s,&op2);
      if(emp(&s))
      {
        printf("Invalid postfix expression\n");
        flag=1;
        break;
      }
      else
      pop(&s,&op1);
      if(flag==0)
      {
      res=eval(op1,op2,post[i]);
      push(&s,res);
    }
    }
    i++;
  }
  if(flag==0)
  {
  if(emp(&s))
  {
   printf("Invalid\n");
   flag1=1;
 }
  else
  pop(&s,&res);
  if(flag1==0)
  {
  if(!emp(&s))
  {
    printf("Invalid postfix expression\n");
  }
  else
  printf("Result=%f\n",res);
}
}
  return 0;
}
void create(stack *s)
{
  s->head=NULL;
}
void push(stack *s,float data)
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
void pop(stack *s,float *data)
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
    printf("%f\n",temp->data);
    temp=temp->next;
  }
}
float eval(float op1,float op2,char ch)
{
  float res;
  switch(ch)
  {
    case '+':res=op1+op2;
             break;
    case '-':res=op1-op2;
             break;
    case '*':res=op1*op2;
             break;
    case '/':res=op1/op2;
             break;
  }
  return(res);
}
