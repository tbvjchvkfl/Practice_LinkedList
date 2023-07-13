#pragma once
#include"SingleLinkedList.h"

const int NAME_LENGTH{ 10 };

struct Monster
{
	char name[NAME_LENGTH]{};

	int HP{};

	// 자기 참조 구조체
	// 이 친구로 연결하는 거
	// 얘는 nullptr을 가리키고 있음.
	Monster* pNext{};
};