#include<stdio.h>
#include<stdlib.h>
struct link
{
int data;
struct link *next;
};
void insert_beg(struct link **,int);
void insert_end(struct link **,int);
void disp(struct link *);
void insert_aft(struct link **,int,int);
int main()
{
int ch,ele,aft;
struct link *first=NULL;
while(1)
{
printf("Enter choice\n");
printf("1.Enter at the start\n2.Enter at the end\n3.Display\n4.Insert after an elemnet\n5.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element\n");
       scanf("%d",&ele);
       insert_beg(&first,ele);
       break;
case 2:printf("Enter element\n");
       scanf("%d",&ele);
       insert_end(&first,ele);
       break;
case 3:disp(first);
       break;
case 4:printf("Enter ele\n");
       scanf("%d",&ele);
       printf("Enter after which element\n");
       scanf("%d",&aft);
       insert_aft(&first,aft,ele);
       break;
case 5:exit(0);
       break;
default:printf("Invalid option\n");
}
}
return 0;
}
void insert_beg(struct link **p,int e)
{
 struct link *temp;
 temp=(struct link *)malloc(sizeof(struct link));
 temp->data=e;
 temp->next=NULL;
 if(*p==NULL)
  *p=temp;
 else
 {
   temp->next=*p;
   *p=temp;
 }
}
void insert_end(struct link **p,int e)
{
 struct link *temp1,*temp2;
 temp1=(struct link *)malloc(sizeof(struct link));
 temp1->data=e;
 temp1->next=NULL;
 temp2=*p;
 if(*p==NULL)
  *p=temp1;
 else
 {
  while(temp2->next!=NULL)
   temp2=temp2->next;
  temp2->next=temp1;
 }
}
void disp(struct link *p)
{
 struct link *temp;
 temp=p;
 while(temp!=NULL)
 {
  printf("%d\n",temp->data);
  temp=temp->next;
 }
} 
void insert_aft(struct link **p,int aft,int ele)
{
struct link *temp1,*temp2,*temp3;
temp2=*p;
temp1=(struct link *)malloc(sizeof(struct link));
temp1->data=ele;
temp1->next=NULL;
while(temp2->data!=aft)
{
temp2=temp2->next;
}
temp3=temp2->next;
temp2->next=temp1;
temp1->next=temp3;
}
