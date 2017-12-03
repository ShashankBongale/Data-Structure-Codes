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
void create(tree *);
void trav(tree *,int );
void iot(node *);
void pot(node *);
void prot(node *);
void sib(tree *,int );
int main()
{
int ele,ch,ch1;
tree t;
int k;
create(&t);
while(1)
{
printf("Enter your choice\n");
printf("1.Insert\n2.Traversal\n3Sibling of an element\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element\n");
       scanf("%d",&ele);
       ins(&t,ele);
       break;
case 2:printf("Enter type of traversal\n");
       printf("1.Inorder\n2.Postorder\n3.Preorder\n");
       scanf("%d",&ch1);
       trav(&t,ch1);
       break;
case 3:printf("Enter element\n");
       scanf("%d",&ele); 
       sib(&t,ele);
       break;
case 4:exit(0);
       break;
default:printf("Invalid option\n");
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
node *temp,*p,*q;
temp=(node *)malloc(sizeof(node));
temp->left=NULL;
temp->right=NULL;
temp->data=data;
if(t->root==NULL) 
 t->root=temp;
p=t->root;
q=NULL;
while(p!=NULL && p->data!=data)
{
q=p;
if(data<p->data)
 p=p->left;
else
 p=p->right;
}
if(p==NULL)
{
if(data<q->data)
 q->left=temp;
else
 q->right=temp;
}
}
void trav(tree *t,int ch)
{
switch(ch)
{
case 1:iot(t->root);
       printf("\n");
       break;
case 2:pot(t->root);
       printf("\n");
       break;
case 3:prot(t->root);
       printf("\n");
}
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
void pot(node *r)
{
if(r!=NULL)
{
pot(r->left);
pot(r->right);
printf("%d ",r->data);
}
}
void prot(node *r)
{
if(r!=NULL)
{
printf("%d ",r->data);
prot(r->left);
prot(r->right);
}
}
void sib(tree *t,int data)
{
node *p,*q;
p=t->root;
q=NULL;
if(data==t->root->data)
 printf("No siblings\n");
else
{
while(p!=NULL & p->data!=data)
{
q=p;
if(data>p->data)
 p=p->right;
else
 p=p->left;
}
if(p==NULL)
 printf("element not present\n");
else
{
if(q->right==NULL || q->left==NULL)
 printf("No siblings\n");
else if(q->right->data==data)
 printf("Sibling=%d",q->left->data);
else
 printf("Sibling=%d",q->right->data);
}
}
}


