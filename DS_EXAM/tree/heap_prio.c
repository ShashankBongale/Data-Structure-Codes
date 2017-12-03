#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct queue
{
  int n;
  int a[MAX];
}queue;
int main()
{
  int ch,ele,s,f,i,j;
  queue q;
  q.n=0;
  int temp;
  while(1)
  {
    printf("Enter choice\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:if(q.n>=MAX)
              printf("Overflow\n");
            else
            {
             printf("Enter element\n");
             scanf("%d",&ele);
             if(q.n==0)
             {
             q.a[0]=ele;
             q.n++;
           }
           else
           {
             s=q.n;
             f=(s-1)/2;
             while(s>0 && ele>q.a[f])
             {
               q.a[s]=q.a[f];
               s=f;
               f=(s-1)/2;
             }
             q.a[s]=ele;
             q.n++;
           }
         }
           break;
    case 2:if(q.n==0)
            printf("Underflow\n");
          else
          {
            printf("%d\n",q.a[0]);
            for(i=q.n-1;i>0;i--)
            {
              temp=q.a[0];
              q.a[0]=q.a[i];
              q.a[i]=temp;
              for(j=1;j<i;j++)
              {
                s=j;
                ele=q.a[j];
                f=(s-1)/2;
                while(s>0 && ele>q.a[f])
                {
                  q.a[s]=q.a[f];
                  s=f;
                  f=(s-1)/2;
                }
                q.a[s]=ele;
              }
            }
            q.n--;
            for(i=1;i<q.n;i++)
            {
              s=i;
              ele=q.a[i];
              f=(s-1)/2;
              while(s>0 && ele>q.a[f])
              {
                q.a[s]=q.a[f];
                s=f;
                f=(s-1)/2;
              }
              q.a[s]=ele;
            }
            }
            break;
  case 3:if(q.n==0)
          printf("No elements\n");
         else
         {
           for(i=0;i<q.n;i++)
           {
             printf("%d\t",q.a[i]);
           }
           printf("\n");
         }
         break;
 case  4:exit(0);
         break;
 default:printf("Invalid\n");

    }

  }
    return 0;
}
