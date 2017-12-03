#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *left,*right;
}node;
typedef struct tree
{
  node *root;
}tree;
void create(tree *);
void ins(tree *,int );
void trav(tree *);
int height(tree *);
int height_helper(node *);
int max(int ,int );
void iot(node *);
void prot(node *);
void pot(node *);
int main()
{
  tree t;
  create(&t);
  int ch,ele;
  //int height;
  while(1)
  {
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:scanf("%d",&ele);
             ins(&t,ele);
             break;
      case 2:if(t.root==NULL)
              printf("tree is empty\n");
             else
              trav(&t);
              break;
      case 3:if(t.root==NULL)
              printf("tree is empty\n");
             else
             {
              printf("Height=%d\n",height(&t));
             }
             break;
      case 4:exit(0);
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
  node *p;
  node *q=NULL;
  node *temp=(node *)malloc(sizeof(node));
  temp->data=data;
  temp->left=temp->right=NULL;
  if(t->root==NULL)
   t->root=temp;
  else
  {
    p=t->root;
    while(p!=NULL && p->data!=data)
    {
      q=p;
      if(data>p->data)
       p=p->right;
      else
      p=p->left;
    }
    if(p==NULL)
    {
      if(data>q->data)
      {
        q->right=temp;
      }
      else
      q->left=temp;
    }
    else
    printf("Element already exists\n");
  }
}
void trav(tree *t)
{
  int ch;
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:prot(t->root);
           break;
    case 2:iot(t->root);
           break;
    case 3:pot(t->root);
           break;
  }
}
void prot(node *r)
{
   if(r!=NULL)
   {
     printf("%d\n",r->data);
     prot(r->left);
     prot(r->right);
   }
}
void iot(node *r)
{
   if(r!=NULL)
   {
     iot(r->left);
     printf("%d\n",r->data);
     iot(r->right);
   }
}
void pot(node *r)
{
   if(r!=NULL)
   {
     pot(r->left);
     pot(r->right);
     printf("%d\n",r->data);
   }
}
int height(tree *t)
{
  return(height_helper(t->root));
}
int height_helper(node *r)
{
  if(r==NULL)
  return -1;
  return(1+max(height_helper(r->left),height_helper(r->right)));
}
int max(int a,int b)
{
  if(a>b || a==b)
   return a;
  else
  return b;
}
