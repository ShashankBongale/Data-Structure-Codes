#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct tree_node
{
  char data;
  struct tree_node *left,*right;
}tree_node;
typedef struct node
{
  tree_node *data;
  struct node *next;
}node;
typedef struct stack
{
  node *head;
}stack;
void create(stack *);
void push(stack *,tree_node *);
tree_node* pop(stack *);
//void disp(stack *);
int emp(stack *);
void iot(tree_node *);
tree_node* make_node(char );
float eval(tree_node *);
int main()
{
  stack s;
  tree_node *temp,*op1,*op2;
  create(&s);
  char post[100];
  printf("Enter a valid postfix expression\n");
  scanf("%s",post);
  int i=0;
  while(post[i]!='\0')
  {
    if(isdigit(post[i]))
    {
      temp=make_node(post[i]);
      push(&s,temp);
      //printf("Inserted into stack\n");
    }
    else
    {
      temp=make_node(post[i]);
      op2=pop(&s);
      op1=pop(&s);
      temp->right=op2;
      temp->left=op1;
      push(&s,temp);
    }
    i++;
  }
temp=pop(&s);
iot(temp);
printf("\n");
float value;
value=eval(temp);
printf("Answer=%f\n",value);
return 0;
}
tree_node* make_node(char data)
{
  tree_node *temp=(tree_node *)malloc(sizeof(tree_node));
  temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}
void iot(tree_node *r)
{
  if(r!=NULL)
  {
    iot(r->left);
    printf("%c",r->data);
    iot(r->right);
  }
}
void create(stack *s)
{
  s->head=NULL;
}
void push(stack *s,tree_node *data)
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
tree_node* pop(stack *s)
{
  tree_node *temp1=s->head->data;
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
  return temp1;
}
int emp(stack *s)
{
  return(s->head==NULL);
}
/*void disp(stack *s)
{
  node *temp=s->head;
  while(temp!=NULL)
  {
    printf("%d\n",temp->data);
    temp=temp->next;
  }
}*/
float eval(tree_node *r)
{
  float res;
  switch(r->data)
  {
    case '+':res=eval(r->left)+eval(r->right);
             break;
    case '-':res=eval(r->left)-eval(r->right);
            break;
    case '*':res=eval(r->left)*eval(r->right);
            break;
    case '/':res=eval(r->left)/eval(r->right);
             break;
    default:res=r->data-'0';
  }
  return res;
}
