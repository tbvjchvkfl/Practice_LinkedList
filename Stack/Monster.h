#pragma once
#include"SingleLinkedList.h"

const int NAME_LENGTH{ 10 };

struct Monster
{
	char name[NAME_LENGTH]{};

	int HP{};

	// �ڱ� ���� ����ü
	// �� ģ���� �����ϴ� ��
	Monster* pNext{};
};