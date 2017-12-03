#include<stdio.h>
#include<stdlib.h>
int main()
{
  int a[100],i,n;
  printf("Enter number of elements\n");
  scanf("%d",&n);
  printf("Enter array elements\n");
  for(i=0;i<n;i++)
   scanf("%d",&a[i]);
  int s,f,ele;
  for(i=1;i<n;i++)
  {
    s=i;
    ele=a[i];
    f=(s-1)/2;
    while(s>0 && ele>a[f])
    {
      a[s]=a[f];
      s=f;
      f=(s-1)/2;
    }
    a[s]=ele;
  }
  printf("Heapified array:\n");
  for(i=0;i<n;i++)
   printf("%d\t",a[i]);
  printf("\n");
//sorting
int j,temp;
for(j=n-1;j>0;j--)
{
  temp=a[0];
  a[0]=a[j];
  a[j]=temp;
  for(i=1;i<j;i++)
  {
    s=i;
    ele=a[i];
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
printf("Sorted elements\n");
for(i=0;i<n;i++)
{
  printf("%d\t",a[i]);
}
printf("\n");
}
