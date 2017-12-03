#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
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
int prec(stack *,char );
int main()
{
  stack s;
  create(&s);
  char infix[100],postfix[100];
  printf("Enter a infix expression\n");
  scanf("%s",infix);
  char temp,dummy;
  int j,i;
  i=0;
  j=0;
  while(infix[i]!='\0')
  {
    if(isalpha(infix[i]))
     postfix[j++]=infix[i];
    else
    {
      while(!emp(&s) && prec(&s,infix[i]))
      {
        pop(&s,&temp);
        postfix[j++]=temp;
      }
      if(infix[i]==')')
       pop(&s,&dummy);
      else
      push(&s,infix[i]);
    }
    i++;
  }
  while(!emp(&s))
  {
    pop(&s,&temp);
    postfix[j++]=temp;
  }
  postfix[j]='\0';
  printf("Postfix Expression=%s\n",postfix);
  return 0;
}
int prec(stack *s,char curr)
{
  switch(curr)
  {
    case '(':return 0;
    case ')':if(s->head->data=='(')
              return 0;
             else
              return 1;
    case '+':
    case '-':if(s->head->data=='(')
              return 0;
             else
              return 1;
    case '*':
    case '/':if(s->head->data=='*' || s->head->data=='/')
               return 1;
              else
              return 0;
  }
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
