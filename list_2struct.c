#include<stdio.h>
#include<stdlib.h>
typedef int ele_t;
struct ar_list
{
ele_t data;
struct ar_list *next;
};
typedef struct ar_list ARLIST;
struct start
{
ARLIST *head;
int c;
};
typedef struct start START;
void create(START *);
void ins(START *,ele_t );
void rem(START *,ele_t *);
void disp(START *);
int emp(START *);
int main()
{
START *s;
create(s);
int ch,ele,ele1;
while(1)
{
printf("Enter choice\n");
printf("1.Insert\n2.Remove\n3.Display\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element\n");
       scanf("%d",&ele);
       ins(s,ele);
       break;
case 2:if(emp(s))
        printf("List is empty\n");
       else
       {
        rem(s,&ele1);
        printf("%d\n",ele1);
       }
       break;
case 3:disp(s);
       break;
case 4:exit(0);
       break;
default:printf("Invalid statement\n");
}
}
return 0;
}
void create(START *s)
{
s->head=NULL;
s->c=0;
}
void ins(START *s,ele_t data)
{
ARLIST *temp,*temp2;
temp=(ARLIST *)malloc(sizeof(ARLIST));
temp->data=data;
temp->next=NULL;
temp2=s->head;
if(s->head==NULL)
{
 s->head=temp;
 s->c=s->c+1;
}
else
{
 while(temp2->next!=NULL)
 temp2=temp2->next;
 temp2->next=temp;
 s->c=s->c+1;
}
}
void rem(START *s,ele_t *data)
{
ARLIST *temp,*prev;
temp=s->head;
prev=s->head;
if(s->c==1)
{
 temp=s->head;
 *data=temp->data;
 s->head=NULL;
 free(temp);
 s->c=s->c-1;
}
else
{
while(temp->next!=NULL)
{
prev=temp;
temp=temp->next;
}
*data=temp->data;
free(temp);
prev->next=NULL;
s->c=s->c-1;
}
}
int emp(START *s)
{
return(s->head==NULL);
}
void disp(START *s)
{
ARLIST *temp;
temp=s->head;
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}



 











