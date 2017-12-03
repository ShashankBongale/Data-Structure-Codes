#include<stdio.h>
#include<stdlib.h>
#define MAX 7
typedef struct tree
{
  int data;
  int info;
}tree;
int main()
{
  tree a[MAX];
  int i,ele,ch;
  int flag=0;
  for(i=0;i<MAX;i++)
  {
    a[i].info=0;
  }
  int n=0;
  int c;
  while(1)
  {
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:if(n>MAX || n==MAX)
             {
              //printf("N==%d\n",n);
              printf("Overflow");
            }
            else
            {
             scanf("%d",&ele);
             if(a[0].info==0)
             {
               a[0].info=1;
               a[0].data=ele;
               n++;
             }
             else
             {
              c=0;
              while(c<MAX && a[c].info==1)
              {

                if(a[c].data!=ele)
                {
                  if(ele>a[c].data)
                   c=2*c+2;
                  else
                   c=2*c+1;
                }
                else
                {
                printf("Element already present\n");
                flag==1;
                break;

                }
                //printf("C=%d\n",c);
             }
             if(c>MAX || c==MAX)
             {
               printf("Overflow\n");
               //flag=1;
             }
             if(a[c].info==0 && flag==0)
             {
               a[c].info=1;
               a[c].data=ele;
               n++;
             }
          }
        }
        break;
    case 2:for(i=0;i<MAX;i++)
           {
             if(a[i].info==1)
              printf("%d\n",a[i].data);
           }
           break;
    case 3:exit(0);
           break;
    default:printf("Invalid\n");
  }
}
return 0;
}
