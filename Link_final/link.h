typedef int ele_t;
struct link_list
{
ele_t data;
struct link_list *next;
};
typedef struct link_list LINK;
void ins(LINK **,ele_t );
int rem(LINK **,ele_t );
void disp(LINK *);

