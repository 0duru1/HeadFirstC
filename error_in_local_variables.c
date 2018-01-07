#include <stdio.h>

void go(int lat, int lon)
{
	lat = lat - 1;
	lon = lon + 2;
}
int main()
{
	int lat = 32;
	int lon = -64;

	go(lat, lon);

	printf("current position : [ %i , %i]", lat, lon);
	return 0;
}
