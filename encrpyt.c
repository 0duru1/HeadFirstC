#include "encrypt.h"

void encrypt(char *message)
{
	int key = 31;
	while (*message) {
		*message = *message ^ key;
		message++;
	}
}
