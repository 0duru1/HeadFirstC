#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEM 10


typedef struct Queue {
        int element[MAX_ELEM];
        int qry;
        int q_init;
        int *front;
        int *rear;
} Queue;

void init(Queue *q, int item)
{
  printf("init queue \n");
  
  q->front = q->element;
  q->rear = &q->element[1];
  *q->front = item;
  q->qry = 1;
  q->q_init = 1;
  
}


void error(char *msg)
{
 fprintf(stderr, "%s\n", msg);
 exit(1);
}



int is_full(Queue *q)
{
  return ( (q->rear == q->front) && ((q->qry == MAX_ELEM)));  
}


void enque(Queue *q, int item)
{
  
  if(q->q_init == 0) {
    init(q, item);
  } else {
    if(is_full(q))
          error("queue full");
    if(q->rear == q->front)
      q->rear = &q->element[(((q->rear)-(q->element)))%MAX_ELEM];
    *q->rear = item;
    int pos = ((q->rear)-(q->element));
    q->rear = &q->element[(pos+1)%MAX_ELEM];
    q->qry = q->qry + 1;
    
  }
}

int is_empty(Queue *q)
{
  return (q->front == q->rear);  
}


int deque(Queue *q)
{
  if(q->front > q->rear)
    error("queue empty");
    
    int pos = (q->front)-(q->element);
    int pop = q->element[(pos)%MAX_ELEM];
    q->front = &q->element[(pos+1)%MAX_ELEM]; 
    q->qry = q->qry - 1;
    return pop; 
}


int main() {
        printf("implement simple queue\n");
        Queue q;
        q.q_init = 0; //itial
       
         
         enque(&q, 1);
         printf("delete que : %d \n", deque(&q));
       
         enque(&q, 2);
       
         enque(&q, 3);
       printf("delete que : %d \n", deque(&q));
       printf("delete que : %d \n", deque(&q));
      
         enque(&q, 4);
         enque(&q, 5);
         enque(&q, 6);
         enque(&q, 7);
         enque(&q, 8);
         enque(&q, 9);
         enque(&q, 10);
         enque(&q, 11);
         enque(&q, 12);
         enque(&q, 13);
         enque(&q, 14);
         enque(&q, 15);
        
         printf("delete que : %d \n", deque(&q));
         enque(&q, 10);
         printf("delete que : %d \n", deque(&q));
         printf("delete que : %d \n", deque(&q));
         printf("delete que : %d \n", deque(&q));
         enque(&q, 11);
         enque(&q, 12);
        
          printf("delete que : %d \n", deque(&q));
          printf("delete que : %d \n", deque(&q));
          printf("delete que : %d \n", deque(&q));
          
        
        return 0;
}
