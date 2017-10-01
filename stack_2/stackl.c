#include<stdio.h>
#include<stdlib.h>
typedef int ele_t;
struct stack
{
 ele_t e;
 struct stack *next;
};
typedef struct stack STACK;
struct first
{
STACK *head;
};
typedef struct first FIRST;
void crea(FIRST *);
void push(FIRST *,ele_t);
void pop(FIRST *,ele_t *);
void disp(FIRST *);
int empty(FIRST *);
int main()
{
int ch,ele,ele1;
FIRST *f;
crea(f);
while(1)
{
printf("Enter choice\n");
printf("1.Push\n2.Pop\n3.Display\n.4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element\n");
       scanf("%d",&ele);
       push(f,ele);
       break;
case 2:if(empty(f))
        printf("Underflow\n");
       else
       {
        pop(f,&ele1);
        printf("%d\n",ele1);
       }
       break;
case 3:if(empty(f))
        printf("Stack is empty\n");
       else
       disp(f);
       break;
case 4:exit(0);
       break;
default:printf("invalid statement\n");
}
}
return 0;
}
void crea(FIRST *f)
{
f->head=NULL;
}
void push(FIRST *f,ele_t ele)
{
STACK *temp;
temp=(STACK *)malloc(sizeof(STACK));
temp->next=NULL;
temp->e=ele;
if(f->head==NULL)
{
 f->head=temp;
}
else
{
temp->next=f->head;
f->head=temp;
}
}
void pop(FIRST *f,ele_t *ele)
{
STACK *temp;
*ele=f->head->e;
temp=f->head;
f->head=f->head->next;
free(temp);
}
void disp(FIRST *f)
{
STACK *temp;
temp=f->head;
if(empty(f))
 printf("Stack is empty\n");
else
{
 while(temp!=NULL)
 {
  printf("%d\n",temp->e);
  temp=temp->next;
 }
}
}
int empty(FIRST *f)
{
return(f->head==NULL);
}

















