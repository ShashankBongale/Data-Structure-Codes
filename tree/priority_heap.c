#include<stdio.h>
#include<stdlib.h>
#define MAX 25
typedef struct heap
{
int n;
int ele[MAX];
}heap;
void create(heap *);
void enq(heap *,int);
void deq(heap *,int *);
void disp(heap *);
int main()
{
int ch,ele;
heap h;
create(&h);
while(1)
{
printf("Enter choice\n");
printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element\n");
       scanf("%d",&ele);
       enq(&h,ele);
       break;
case 2:if(h.n==0)
	printf("Heap is Empty\n");
       else
       {
        deq(&h,&ele);
        printf("%d\n",ele);
       }
       break;
case 3:if(h.n==0)
	printf("Heap is empty\n");
       else
	disp(&h);
       break;
case 4:exit(0);
       break;
default:printf("Invalid statement\n");
}
}
return 0;
}
void create(heap *h)
{
h->n=0;
}
void enq(heap *h,int data)
{
int s,f;
s=h->n;
f=(s-1)/2;
while(s>0 && data>h->ele[f])
{
h->ele[s]=h->ele[f];
s=f;
f=(s-1)/2;
}
h->ele[s]=data;
h->n++;
}
void deq(heap *h,int *data)
{
int ele;
*data=h->ele[0];
ele=h->ele[h->n-1];
int d=h->ele[h->n-1];
int i;
int e1,e2,temp;
int j;
int k,s,f;
if(h->n==1)
 h->n=0;
else
{
//printf("In else part\n");
for(i=h->n-1;i>0;i--)
{
temp=h->ele[0];
h->ele[0]=h->ele[i];
h->ele[i]=temp;
e2=temp;
for(j=1;j<i-1;j++)
{
ele=h->ele[j];
s=j;
f=(s-1)/2;
while(s>0 && ele>h->ele[f])
{
h->ele[s]=h->ele[f];
s=f;
f=(s-1)/2;
}
h->ele[s]=ele;
}
}
if(h->n%2==0)
{
temp=h->ele[1];                         //When number of elements will be even the last pair is heapified which reverse the sorted order
h->ele[1]=h->ele[2];
h->ele[2]=temp;
}
h->n--;
int data1;
for(i=0;i<h->n;i++)
{
data1=h->ele[i];
s=i;
f=(s-1)/2;
while(s>0 && data1>h->ele[f])
{
h->ele[s]=h->ele[f];
s=f;
f=(s-1)/2;
}
h->ele[s]=data1;
}
}
}
void disp(heap *h)
{
int i;
for(i=0;i<=h->n-1;i++)
printf("%d\t",h->ele[i]);
printf("\n");
}
