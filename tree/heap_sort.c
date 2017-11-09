#include<stdio.h>
int main()
{
int i,a[100],ele;
int s;
printf("Enter number of elements\n");
int n,f;
scanf("%d",&n);
for(i=0;i<n;i++)
 scanf("%d",&a[i]);
for(i=1;i<n;i++)
{
ele=a[i];
s=i;
//s=2*f+1;
f=(s-1)/2;
while(s>0 && ele>a[f])
{
a[s]=a[f];//Father slides down to son element
s=f;            //Back propogation.
f=(s-1)/2;
}
a[s]=ele;
}
printf("Heapified Elements\n");
for(i=0;i<n;i++)
 printf("%d ",a[i]);
printf("\n");
//sort
int e1,e2,temp;
int j;
int k;
for(i=n-1;i>0;i--)
{
temp=a[0];
a[0]=a[i];
a[i]=temp;
e2=temp;
for(j=1;j<i-1;j++)
{
ele=a[j];
s=j;
f=(s-1)/2;
while(s>0 && ele>a[f])
{
a[s]=a[f];
s=f;
f=(s-1)/2;
}
a[s]=ele;
}
}
if(n%2==0)
{
temp=a[1];                         //When number of elements will be even the last pair is heapified which reverse the sorted order
a[1]=a[2];
a[2]=temp;
}
printf("Sorted elements\n");
for(i=0;i<n;i++)
 printf("%d ",a[i]);
return 0;
}
