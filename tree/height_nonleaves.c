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
int non_leaf(tree *);
int nl(node *);
void iot(node *);
void pot(node *);
void prot(node *);
int max(int ,int);
int height(tree *);
int ht(node *);
int main()
{
int ele,ch,ch1;
tree t;
int k;
create(&t);
while(1)
{
printf("Enter your choice\n");
printf("1.Insert\n2.Traversal\n3.Exit\n4.No of non-leaf\n5.Height\n");
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
case 4:k=non_leaf(&t);
       printf("No of non-leaves=%d",k);
       break;
case 5:k=height(&t);
       printf("Height=%d",k);
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
int non_leaf(tree *t)
{
return(nl(t->root));
}
int nl(node *r)
{
static int cnt=0;
if(r!=NULL)
{
nl(r->left);
if(r->left!=NULL || r->right!=NULL)
 cnt++;
nl(r->right);
}
return(cnt);
}
int max(int a,int b)
{
if(a>b)
 return a;
else
 return b;
}
int height(tree *t)
{
return(ht(t->root));
}
int ht(node *r)
{
if(r==NULL)
 return -1;
return(1+max(ht(r->left),ht(r->right)));
}
