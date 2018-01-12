#include <stdio.h>
#include <stdlib.h>

#define MAX_Q_SIZE 100 // 큐의 초기 사이즈 설정

//큐의 구조체 선언
typedef int element;
typedef int point;

typedef struct {
	element queue[MAX_Q_SIZE];
	point front, end;
} QueueType;

//에러출력
void err(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}
void prt(QueueType *q)
{
	printf("front=%d , end=%d \n", q->front, q->end);
}
//큐를 생성한다.
QueueType create()
{
	printf("큐를 생성\n");
	QueueType q;
	prt(&q);
	return q;
}

//큐를 초기화한다.
void init(QueueType *q)
{
	q->front = q->end = 0;
}

// 큐가 비어있는지를 검사한다.
int is_empty(QueueType *q)
{
	return (q->end == q->front);
}

// 큐가 가득 찼는가를 검사한다.
int is_full(QueueType *q)
{
	return ( (q->end+1)%MAX_Q_SIZE == q->front );
}
// 규의 뒤의 요소를 추가한다.
void enqueue(QueueType *q, element item)
{
	if(is_full(q))
		err("큐가 포화상태");
	q->end = (q->end+1) % MAX_Q_SIZE;
	q->queue[q->end] = item;
}
// 큐의 앞에 있는 요소를 반환한 다음 삭제한다.
element dequeue(QueueType *q)
{
	if(is_empty(q))
		err("큐가 비어 있음");
	q->front = (q->front+1)%MAX_Q_SIZE;
	return q->queue[q->front];
}
// 큐에서 삭제하지 않고 앞에 있는 요소를 반환한다.
element peek(QueueType *q)
{
	if( is_empty(q) )
		err("큐가 비어 있음");
	return q->queue[(q->front+1)%MAX_Q_SIZE];
} 

int main()
{
	//구현한 큐를 테스트한다.
	QueueType q = create();
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	printf("end=%d\n", q.queue[q.end]);

	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));

	prt(&q);
	return 0;
}
