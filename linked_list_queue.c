#include <stdio.h>
#include <stdlib.h>


typedef int element;

typedef struct {
	element item;
	struct QueueNode *link;
} QueueNode;

typedef struct {
	//front, rear
	//queue
	QueueNode *front, *rear;
} Queue;

void err(char *msg)
{
	fprintf(stderr, "%s \n", msg);
	exit(1);
}

void init(Queue *q)
{
	q->front = q->rear = 0;
}

int is_empty(Queue *q)
{
	return (q->front==NULL);
}

int is_full(Queue *q)
{
	return 0;
}

void enqueue(Queue *q, element item)
{
	QueueNode *tmp = (QueueNode*)malloc(sizeof(QueueNode));
	if(tmp == NULL){
		err("err");
	} else {
		tmp->item = item;
		tmp->link = NULL;
		if(is_empty(q)) {
			q->rear = tmp;
			q->front = tmp;
		} else {
			q->rear->link = tmp;
			q->rear = tmp;
		}
	}
/*
	//동적메모리를 할당을 통해 새로운 노드를 만든다.
	//새로운 노드에 데이타를 저장한다.
	//큐의 끝노드의 링크를 새로운 노드를 가리키게 한다.
	//큐의 마지막포인트를 새로운 노드를 가리키게 한다.

	QueueNode *tmp = (QueueNode *)malloc(sizeof(QueueNode));
	if(tmp == NULL){
		err("not allocation memory");
	} else {
		tmp->item = item;
		tmp->link = NULL;
		if(is_empty(q)) {
			q->front = tmp;
			q->rear = tmp;
		} else {
			q->rear->link = tmp;
			q->rear = tmp;
		}
	}
*/
}

element  dequeue(Queue *q)
{
	//먼저 큐가 공백인지 검사
	//공백이면->에러표시
	//공백이 아니면
		//프론트가 가리키는 노드를 임시 노드가 가리키도록 한다
		//프론터가 가리키는 노드의 링크를 프롵너가 가리키도록 한다.
		//템프노드가 가리키는 곳을 메모리에서 해제한다.
	QueueNode *tmp = q->front;
	element item;

	if(is_empty(q)) 
		err("queue empty");
	
		item = tmp->item;
		q->front = q->front->link;
		if(q->front == NULL) 
			q->rear = NULL;

		free(tmp);
		return item;
	
}

int main()
{
	printf("queue create\n");
	Queue q;
	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);

	printf("dequeue = %d\n", dequeue(&q));
	printf("dequeue = %d\n", dequeue(&q));
	printf("dequeue = %d\n", dequeue(&q));
	return 0;
}
