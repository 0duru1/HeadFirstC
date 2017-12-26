#include "decrypt.h"

void decrypt (char *msg)
{
	char c;
	while (*msg) {
		*msg = *msg ^ 31;
		msg++;
	}
}
