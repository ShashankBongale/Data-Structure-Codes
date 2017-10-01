typedef int ele_t;
#define max 60 
struct ar_list
{
ele_t a[max];
int last;
};
typedef struct ar_list ARLIST;
void ins(ARLIST *,ele_t);
int rem(ARLIST *);
int emp(ARLIST *);
void disp(ARLIST *);
int over(ARLIST *);


