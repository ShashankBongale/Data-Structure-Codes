#define MAX 5
#include<stdio.h>
#include<stdlib.h>
typedef int ele_t;
struct stack
{
int top;
ele_t a[MAX];
};
typedef struct stack STACK;
void ins(STACK *,ele_t );
int rem(STACK *,ele_t *);
void disp(STACK *);
int empty(STACK *);
int full(STACK *);
void init(STACK *);
int main()
{
int ch,ele,ele1;
STACK s;
init(&s);
while(1)
{
 printf("Enter choice\n");
 printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
 scanf("%d",&ch);
 switch(ch)
{
 case 1:if(full(&s))
         printf("Stack is full\n");
        else
        {
         printf("Enter element\n");
         scanf("%d",&ele);
         ins(&s,ele);
        }
        break;
 case 2:if(!rem(&s,&ele1))
         printf("Underflow\n");
        else
         printf("%d\n",ele1);
        break;
 case 3:disp(&s);
        break;
 case 4:exit(0);
        break;
 default:printf("Invalid option\n");
}
}
return 0;
}
void ins(STACK *s,ele_t e)
{
 s->top=s->top+1;
 s->a[s->top]=e;
// printf("top=%d\n",s->top);
}
int full(STACK *s)
{
 return(s->top==MAX-1);
}
int rem(STACK *s,ele_t *e)
{
 if(empty(s))
  return 0;
 else
 {
  *e=s->a[s->top];
   s->top=s->top-1;
  // printf("top=%d\n",s->top);
   return 1;
 }
}
int empty(STACK *s)
{
return(s->top==-1);
}
void disp(STACK *s)
{
int i;
if(empty(s))
 printf("Stack is empty\n");
else
{
 for(i=s->top;i>=0;i--)
  printf("%d\n",s->a[i]);
}
}
void init(STACK *s)
{
s->top=-1;
}















       
 
