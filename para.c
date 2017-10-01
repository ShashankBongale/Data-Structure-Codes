#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef char ele_t;
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
int eval(start *,char []);
int main()
{
start s;
float op1,op2,res;
char a[100];
create(&s);
printf("Enter an expresson consisting of parenthesis");
gets(a);
if(eval(&s,a))
 printf("Parenthesis matched\n");
else
 printf("Parenthesis not matched\n");
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
printf("%c\n",temp->data);
temp=temp->next;
}
} 
int emp(start *s)
{
return(s->h==NULL);
}
int eval(start *s,char p[])
{
char a,temp;
int i=0;
a=p[i];
while(a!='\0')
{
//printf("%c\n",a);
if((a=='(') || (a=='{') || (a=='['))
 push(s,a);
else if(a==')')
{
if(emp(s))
 return 0;
else
{
pop(s,&temp);
if(temp!='(')
 return 0;
}
}
else if(a=='}')
{
if(emp(s))
 return 0;
else
{
pop(s,&temp);
if(temp!='{')
 return 0;
}
}
else if(a==']')
{
if(emp(s))
 return 0;
else
{
pop(s,&temp);
if(temp=']')
 return 0;
}
}
i++;
a=p[i];
}
if(emp(s))
return 1;
else
return 0;
}

