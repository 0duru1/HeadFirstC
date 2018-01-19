#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("입력된 수의 범의 안에서 가장 많은 약수의 갯수를 가지는 수를 구하여라.\n");
	int input_number;
	puts("약수의 범위를 입력하세요");
	scanf("%d", &input_number);

	int max_number=0;
	int max_cnt=0;

	printf("계산중입니다....\n");
	for(int i = 1; i <= input_number; i++)
	{
		int cnt = 0;
		printf("%d 의 약수의 갯수를 구하는 ", i);
		for(int x = 1; x * x <= i; x++)
		{
			if(i%x==0)
			{
				cnt++;
				if(x*x < i)
				{
					cnt++;
				}		
			}
		}

		printf("... 약수의 갯수 %d \n", cnt);

		if(cnt>=max_cnt) {
			max_number = i;
			max_cnt = cnt;
		}
	}

	printf("최대의 약수를  가진 수는 %d 이다\n", max_number);

	return 0;
}
