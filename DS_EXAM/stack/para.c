#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  char data;
  struct node *next;
}node;
typedef struct stack
{
  node *head;
}stack;
void create(stack *);
void push(stack *,char );
void pop(stack *,char *);
void disp(stack *);
int emp(stack *);
int main()
{
  stack s;
  create(&s);
  char exp[100];
  int flag=0;
  char temp;
  int i=0;
  printf("Enter a expression\n");
  scanf("%s",exp);
  while(exp[i]!='\0')
  {
    if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
     push(&s,exp[i]);
    else
    {
      if(exp[i]=='}')
      {
        if(emp(&s))
        {
         printf("Parenthesis not matched\n");
         flag=1;
         break;
       }
        else
        {
          pop(&s,&temp);
          if(temp!='{')
          {
           printf("Parenthesis not matched\n");
           flag=1;
           break;
         }
        }
      }
      else if(exp[i]==')')
      {
        if(emp(&s))
        {
         printf("Parenthesis not matched\n");
         flag=1;
         break;
       }
        else
        {
          pop(&s,&temp);
          if(temp!='(')
          {
           printf("Parenthesis not matched\n");
           flag=1;
           break;
         }
        }
      }
      else if(exp[i]==']')
      {
        if(emp(&s))
        {
         printf("Parenthesis not matched\n");
         flag=1;
         break;
       }
        else
        {
          pop(&s,&temp);
          if(temp!='[')
          {
           printf("Parenthesis not matched\n");
           flag=1;
           break;
         }
        }
      }
    }
    i++;
  }
  if(flag==0)
  {
    if(emp(&s))
     printf("Parenthesis matched\n");
    else
    printf("Parenthesis not matched\n");
  }
  return 0;
}
void create(stack *s)
{
  s->head=NULL;
}
void push(stack *s,char data)
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
void pop(stack *s,char *data)
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
