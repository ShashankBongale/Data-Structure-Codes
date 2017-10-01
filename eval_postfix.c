#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef float ele_t;
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
float eval(float op1,float op2,char ch);
int main()
{
int ch,ele,ele1;
FIRST f;
crea(&f);
float op1,op2,res;
float temp;
char p[500];
printf("Enter a valid postfix expressin\n");
scanf("%s",p);
int i=0;
while(p[i]!='\0')
{
 if(isdigit(p[i]))
 {
  temp=p[i]-'0';
  push(&f,temp);
 }
else
 {
 pop(&f,&op2);
 pop(&f,&op1);
 res=eval(op1,op2,p[i]);
 push(&f,res);
 } 
i++;
}
pop(&f,&res);
printf("Result=%f\n",res);
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
void pop(FIRST *f,ele_t *data)
{
STACK *temp,*temp1;
temp=f->head;
*data=temp->e;
temp1=temp->next;
f->head=temp1;
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
  printf("%f\n",temp->e);
  temp=temp->next;
 }
}
}
int empty(FIRST *f)
{
return(f->head==NULL);
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


















