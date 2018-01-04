#include "decrypt.h"

void decrypt (char *msg)
{
	int key = 31;
	char c;
	while (*msg) {
		*msg = *msg ^ key;
		msg++;
	}
}
