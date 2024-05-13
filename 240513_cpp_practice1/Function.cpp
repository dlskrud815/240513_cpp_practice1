#include "Function.h"

int Random(int range)
{
	srand(time(NULL));
	return rand() % range + 1;
}