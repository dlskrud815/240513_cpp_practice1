#include "Function.h"
#include "Character.h"
#include "Monster.h"

int Random(int range)
{
	srand(time(NULL));
	return rand() % range + 1;
}

bool CheckEvenOdd(int choice)
{
	int randNum = Random(100);
	int result;

	if (randNum % 2 == 0) //Â¦¼ö
	{
		result = 2;
	}
	else //È¦¼ö
	{
		result = 1;
	}

	if (choice == result)
	{
		return true; //¸ÂÈû
	}
	else
	{
		return false; //Æ²¸²
	}
}