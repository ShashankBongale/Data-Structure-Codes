#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef float ele_t;
typedef struct stack
{
ele_t data;
struct stack *next;
}stack;
typedef struct start
{
stack *h;
}start;
void push(start *,ele_t );
void pop(start *,ele_t *);
int emp(start *);
void disp(start *);
void create(start *);
float eval(float ,float, char );
int main()
{
start s;
float op1,op2,res;
char a[100];
create(&s);
printf("Enter a valid postfix expression\n");
gets(a);
int i=0;
while(a[i]!='\0')
{
if(isdigit(a[i]))
 push(&s,a[i]-'0');
else
{
 pop(&s,&op2);
 pop(&s,&op1);
 res=eval(op1,op2,a[i]);
 push(&s,res);
}
 i++;
}
pop(&s,&res);
printf("%f\n",res);
return 0;
}
void create(start *s)
{   
s->h=NULL;
}
void push(start *s,ele_t data)
{
stack *temp=s->h;
stack *temp1;
temp1=(stack *)malloc(sizeof(stack));
temp1->data=data;
temp1->next=NULL;
if(temp==NULL)
 s->h=temp1;
else
{
temp1->next=s->h;
s->h=temp1;
}
}
void pop(start *s,ele_t *e)
{
stack *temp=s->h;
*e=s->h->data;
s->h=temp->next;
free(temp);
}
void disp(start *s)
{
stack *temp;
temp=s->h;
while(temp!=NULL)
{
printf("%f\n",temp->data);
temp=temp->next;
}
} 
int emp(start *s)
{
return(s->h==NULL);
}
float eval(float op1,float op2,char ch)
{
float res;
//printf("op1=%f",op1);
//printf("op2=%f",op2);
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
printf("%f\n",res);
return(res);
}
