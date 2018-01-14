#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int factor = 1800;
	int cnt = 0;
	printf("%d의  약수의 갯수를 구하여라\n", factor);

	clock_t start, finish;
	double duration;

	//알고리즘 수행 시간 측정
	start = clock();
	for(int i = 1; i * i <= factor; i++)
	{
		if(factor%i == 0) {
		 	cnt=cnt+1;
			if(i*i < factor) {
				cnt++;
			}
		}
	}
	finish = clock();
	//-----------------------

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%d의 약수의 갯수는 : %d\n", factor, cnt);
	printf("%f의 초 걸림 \n", duration);

	
	return 0;
}
