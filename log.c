#include<stdio.h>
#include<stdlib.h>

int main()
{
	char file_name[] = "log.txt";
	char *msg;

	FILE *fp;

	fp = fopen(file_name, "w+");
	fprintf(fp, "this is testing for fprintf\n");
	fputs("this is testing for fputs...\n", fp);
	fclose(fp);

	return 0;
}
