#pragma once
#include"DoubleLinkedList.h"

const int NAME_LENGTH{ 10 };

struct DMonster
{
	char name[NAME_LENGTH]{};

	int HP{};

	// �ڱ� ���� ����ü
	// �� ģ���� �����ϴ� ��
	// ��� nullptr�� ����Ű�� ����.
	DMonster* pNext{};
	DMonster* pPrevious{};
};