#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element; //요소의 타입

typedef struct Node {
	element data;
	struct Node *llink;
	struct Node *rlink;	
} Node;

typedef struct DequeType {
	Node *head;
	Node *tail;
} DequeType;

void err(char *msg)
{
	printf("에러 출력 \n");
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

void init(DequeType *dp)
{
	dp->head=dp->tail=NULL;
	printf("deque 를 초기화 했습니다.\n");
}



int main() 
{
	DequeType deque;
	printf("Deque create \n");

	init(&deque);

	err("에러함수를 테스트합니다.");
	return 0;
}
