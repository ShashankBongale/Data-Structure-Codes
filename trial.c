#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
struct node *left,*right;
int data;
}node;
typedef struct tree
{
node *root;
}tree;
void ins(tree *,int );
void trav(tree *);
void create(tree *);
void iot(node *);
int main()
{
tree t;
create(&t);
int ele,ch;
while(1)
{
printf("Enter choice\n");
printf("1.Insert\n2.Traverse\n.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element\n");
       scanf("%d",&ele);
       ins(&t,ele);
       break;
case 2:trav(&t);
       break;
case 3:exit(0);
       break;
default:printf("Invalid statement\n");
}
}
return 0;
}
void create(tree *t)
{
t->root=NULL;
}
void ins(tree *t,int data)
{
node *temp;
node *p,*q;
p=t->root;
q=NULL;
temp=(node *)malloc(sizeof(node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
if(t->root==NULL)
 t->root=temp;
else
{
 while(p!=NULL && p->data!=temp->data)
 {
  q=p;
  if(p->data>temp->data)
   p=p->left;
  else
   p=p->right;
 }
 if(temp->data>q->data)
  q->right=temp;
 else
  q->left=temp;
}
}
void trav(tree *t)
{
 iot(t->root);
 
}
void iot(node *r)
{
if(r!=NULL)
{
iot(r->left);
printf("%d ",r->data);
iot(r->right);
}
}





