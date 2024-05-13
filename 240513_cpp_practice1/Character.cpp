#include "Character.h"

int Character::ManipulateCharacter(int option)
{
	string name;

	switch (option)
	{
	case 1:
		cout << "- 변경할 이름 입력: ";
		cin >> name;
		setName(name);
		cout << "이름이 변경되었습니다." << endl;
		break;
	case 2:
		cout << "Level Up! ";
		setLevelUp(getLevel());
		cout << "lv." << getLevel() << endl;
		break;
	case 3:
		cout << "아이템을 얻었습니다." << endl;
		setGetItem(getItem_num());
		break;
	case 4:
		if (getItem_num() > 0)
		{
			cout << "아이템을 사용했습니다." << endl;
			setUseItem(getItem_num()); //어떤 아이템 버릴 지 확인 필요!!
		}
		else
		{
			cout << "경고: 사용할 아이템이 없습니다." << endl;
		}
		break;
	case 5:
		cout << endl << "------------------" << endl
			<< "이름: " << getName() << endl
			<< "레벨: " << getLevel() << endl
			<< "아이템 수: " << getItem_num() << endl
			<< "------------------" << endl;
		break;
	}
	return option;
}