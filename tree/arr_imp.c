#include<stdio.h>
#include<stdlib.h>
#define max 50
typedef struct node
{
int data;
int info;
}node;
int main()
{
int data,ch,c;
node a[max];
int i;
int num=0;
for(i=0;i<max;i++)
{
a[i].info=0;
}
while(1)
{
printf("Enter choice\n");
printf("1.Insert\n2.Display\n3.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter element\n");
        scanf("%d",&data);
        if(a[0].info==0)
        {
         a[0].data=data;    //INSERTING VERY FIRST ELEMENT
         a[0].info=1;
        }
        else
	{
	 c=0;
	 while(c<max && a[c].info!=0)
	 { if(a[c].data!=data)
           {
           if(data>a[c].data)
            c=2*c+2;            //RIGHT CHILD
           else if(data<a[c].data)
	    c=2*c+1;           //LEFT CHILD
	  }
         else
          {
          printf("Element already present\n");
          break;
          }
         }
         if(a[c].data!=data)
         {
         a[c].info=1;
         a[c].data=data; //UPDATING NEW ELEMENT
         num++;
	}
       }
       break;
case 2:for(i=0;i<max;i++)         
       {
        if(a[i].info==1)
        printf("%d ",a[i].data);  /*DISPLAY HERE DOES NOT FOLLOW ANY TRAVERAL METHOD INSTEAD JUST PRINTS
                                   DIGITS PRESENT IN THE ARRAY IN THE ORDER IN WHICH THEY APPEAR*/      
       }
       break;
case 3:exit(0);
       break;
default:printf("Invalid option\n");
}
}
return 0;
}
/*
void iot(node a[])
{
c=0;
iot_r(c);
}
void iot(int c)
{
static int i=0;
if(i!=max)
{
if(a[i].info!=0)
 printf("%d ",a[i].data);
iot(c*2+1);
iot(c*2+2);
}
}
*/
