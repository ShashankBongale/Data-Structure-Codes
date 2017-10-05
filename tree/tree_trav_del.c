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
void del(tree *,int );
int main()
{
int ele,ch,ch1;
tree t;
create(&t);
while(1)
{
printf("Enter your choice\n");
printf("1.Insert\n2.Traversal\n3.Exit\n4.Del");
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
case 3:exit(0);
       break;
case 4:printf("Enter element to be deleted\n");
       scanf("%d",&ele);
       del(&t,ele);
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
void del(tree *t,int data)
{
node *p,*q,*temp;
p=t->root;
q=NULL;
if(p==NULL)
 printf("tree does not contain any elements\n");
else
{
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
 printf("Element not present\n");
}
else
{

 if(q==NULL)
 {
  temp=p->right;           //If Root elemented has to be deleted
  while(temp->left!=NULL)
 {
  temp=temp->left;
 }
  temp->left=p->left;
  t->root=p->right;
  free(p);
 }
 else if(p->left==NULL && p->right==NULL)
 { 
  if(p->data>q->data)
  {
   free(p);
   q->right=NULL;         
  }
  else
  {
  free(p);
  q->left=NULL;
  }
 }
 else if(p->left==NULL && p->right!=NULL)
 { 
  if(p->data>q->data)
  {
   q->right=p->right;
  }
  else  
  q->left=p->right;
  free(p);
 }
 else if(p->right==NULL && p->left!=NULL)
 { 
  if(p->data>q->data)
   q->right=p->left;
  else
   q->left=p->left;
  free(p);
 }
 else
 {
  temp=p->right;
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  q->right=p->right;
  temp->left=p->left;
  free(p);
 }
}
}
}
