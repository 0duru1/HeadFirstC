#include <stdio.h>
#include "encrypt.h"
#include "decrypt.h"

int main()
{
	char msg[80];
	while (fgets(msg, 80, stdin)) {
		encrypt(msg);
		printf(" 암호화된 문장 : %s", msg);

		decrypt(msg);
		printf(" 복음화된 문장 : %s", msg);
	}
	printf("암호화");
	return 0;
}
