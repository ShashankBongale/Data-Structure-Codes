typedef int ele_t;
struct queue
{
ele_t data;
struct queue *next;
};
typedef struct queue QUEUE;
void ins(QUEUE **,ele_t );
int del(QUEUE **,ele_t *);
void disp(QUEUE *);

