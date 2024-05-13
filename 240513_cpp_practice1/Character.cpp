#include "Character.h"

int Character::ManipulateCharacter(int option)
{
	string name;

	switch (option)
	{
	case 1:
		cout << "- ������ �̸� �Է�: ";
		cin >> name;
		setName(name);
		cout << "�̸��� ����Ǿ����ϴ�." << endl;
		break;
	case 2:
		cout << "Level Up! ";
		setLevelUp(getLevel());
		cout << "lv." << getLevel() << endl;
		break;
	case 3:
		cout << "�������� ������ϴ�." << endl;
		setGetItem(getItem_num());
		break;
	case 4:
		if (getItem_num() > 0)
		{
			cout << "�������� ����߽��ϴ�." << endl;
			setUseItem(getItem_num()); //� ������ ���� �� Ȯ�� �ʿ�!!
		}
		else
		{
			cout << "���: ����� �������� �����ϴ�." << endl;
		}
		break;
	case 5:
		cout << endl << "------------------" << endl
			<< "�̸�: " << getName() << endl
			<< "����: " << getLevel() << endl
			<< "������ ��: " << getItem_num() << endl
			<< "------------------" << endl;
		break;
	}
	return option;
}