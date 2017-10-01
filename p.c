#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef float ele_t;
typedef struct stack
{
ele_t data;
struct stack *next;
}stack;
typedef struct first
{
int c;
stack *head;
}first;
void create(first *);
void ins(first *,ele_t);
void rem(first *,ele_t *);
void disp(first *);
int empty(first *);
float eval(float ,float ,char );
int main()
{
first *f;
create(f);
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
  ins(f,temp);
 }
else
 {
 rem(f,&op2);
 rem(f,&op1);
 res=eval(op1,op2,p[i]);
 } 
i++;
}
rem(f,&res);
printf("Result=%f\n",res);
return 0;
}
void create(first *f)
{
f->head=NULL;
f->c=0;
}
void ins(first *f,ele_t data)
{
stack *temp;
temp=(stack *)malloc(sizeof(stack));
temp->next=NULL;
temp->data=data;
if(f->head==NULL)
{
f->head=temp;
}
else
{
temp->next=f->head;
f->head=temp;
}
f->c++;
}
void rem(first *f,ele_t *data)
{
stack *temp,*temp2;
temp=f->head;
*data=temp->data;
temp2=temp->next;
f->head=temp2;
free(temp);
f->c--;
}
int empty(first *f)
{
return(f->head==NULL);
}
void disp(first *f)
{
stack *temp;
temp=f->head;
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


















