#include<stdlib.h>
#include<stdio.h>

struct qnode
{
  int key;
  struct qnode *next;
};

// The queue, front stores the front node of LL and rear stores ths  last node of LL
struct queue
{
    struct qnode *front,*rear;
};

struct qnode *new_node(int k)
{
  struct qnode *temp = (struct qnode*)malloc(sizeof(struct qnode));
  temp->key = k;
  temp->next = NULL;
  return temp;
}

struct queue *createQueue()
{
  struct queue *q = (struct queue*)malloc(sizeof(struct queue));
  q->front = q->rear = NULL;
  return q;
}

void enqueue(struct queue *q,int k)
{
  struct qnode *temp = new_node(k);

  if(q->rear==NULL)
  {
      q->rear = q->front = temp;
      return ;
  }
  q->rear->next = temp;
  q->rear = temp;
}
struct qnode *dequeue(struct queue *q)
{
  if(q->front ==NULL)
  return NULL;

  struct qnode *temp = q->front;
  q->front = q->front->next;

// // If front becomes NULL, then change rear also as NULL
  if(q->front == NULL)
  q->rear = NULL;
  return temp;
}

int main()
{
    struct queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    struct qnode *n = dequeue(q);
    if (n != NULL)
      printf("Dequeued item is %d ", n->key);
    return 0;
}
