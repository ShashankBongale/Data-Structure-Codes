#include "arlist.h"
#include<stdio.h>
void ins(ARLIST *h,ele_t e)
{
if(h->last==max-1)
 printf("Overflow\n");
else
{
 h->last++;
 h->a[h->last]=e;
}
}
ele_t rem(ARLIST *h)
{
int temp;
temp=h->a[h->last];
h->last--;
return temp;
}
void disp(ARLIST *h)
{
int i;
for(i=0;i<=h->last;i++)
 printf("%d\n",h->a[i]);
}
int emp(ARLIST *h)
{
return(h->last==-1);
}
int over(ARLIST *h)
{
return(h->last==max-1);
}


