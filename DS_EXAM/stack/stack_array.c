#include<stdio.h>
#include<stdlib.h>
#define MAX 6
typedef struct stack
{
  int a[MAX];
  int top;
}stack;
void create(stack *);
void push(stack *,int );
void pop(stack *,int *);
int isfull(stack *);
int isemp(stack *);
void disp(stack *);
int main()
{
  stack s;
  create(&s);
  int ele,ch;
  while(1)
  {
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:if(isfull(&s))
              printf("Overflow\n");
             else
           {
             scanf("%d",&ele);
             push(&s,ele);
           }
             break;
      case 2:if(isemp(&s))
             printf("Underflow\n");
             else
             {
               pop(&s,&ele);
               printf("%d\n",ele);
             }
             break;
     case 3:if(isemp(&s))
             printf("No elements\n");
            else
            {
              disp(&s);
            }
            break;
    case 4:exit(0);
           break;
    default:printf("Invalid\n");
    }
  }
  return 0;
}
void create(stack *s)
{
  s->top=-1;
}
void push(stack *s,int data)
{
  s->top++;
  s->a[s->top]=data;
}
void pop(stack *s,int *data)
{
  *data=s->a[s->top];
  s->top--;
}
int isfull(stack *s)
{
  return(s->top==MAX-1);
}
int isemp(stack *s)
{
  return(s->top==-1);
}
void disp(stack *s)
{
  int i;
  for(i=s->top;i>=0;i--)
  {
    printf("%d\t",s->a[i]);
  }
  printf("\n");
}
