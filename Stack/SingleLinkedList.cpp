#include<iostream>
#include"SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int HP)
{
	Monster* IsMonster = new Monster;

	// 문자열을 복사
	// ( 선언한 구조체에 있는 name이라는 배열과 NAME_LENGTH라는 상수, 매개변수 name을 받을 것 )
	strcpy_s(IsMonster->name, NAME_LENGTH, name);

	// 구조체 Monster에 있는 HP에 매개변수 HP의 값을 배정함.
	IsMonster->HP = HP;

	// 가장 처음에 pTail은 nullptr로 초기화해준 상태이므로 
	// pTail로 다음 구조체들을 연결해줄껀데, 만약 pTail이 nullptr이면 pHead를 구조체와 연결해줌.( 처음 한번만 작동하게 됨. )
	if (list.pTail == nullptr)
	{
		list.pHead = IsMonster;
	}
	else
	{
		list.pTail->pNext = IsMonster;
	}

	// MonsterList에 있는 pTail에 구조체를 배정해줌.
	// 여기서 pTail과 구조체가 연결 됨.
	list.pTail = IsMonster;
	return IsMonster;
}

int GetMonsterCount(const MonsterList& list)
{
	// 구조체에 pHead를 배정하고
	Monster* IsMonster = list.pHead;
	int count{};

	// pHead가 nullptr이 될 때까지 반복해서 count변수의 값을 더해준다.
	// 동시에 pHead를 계속해서 연결된 원소들로 이동시켜준다.( 언젠간 끝(nullptr)에 닿을 테니 )
	// Travers( 순회 )의 개념
	while (IsMonster)
	{
		count++;
		IsMonster = IsMonster->pNext;
	}
	return count;
}

void PrintMonsters(const MonsterList& list)
{
	Monster* IsMonster = list.pHead;
	while (IsMonster)
	{
		std::cout << IsMonster->name << "," << IsMonster->HP << std::endl;
		IsMonster = IsMonster->pNext;
	}
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* IsMonster = list.pHead;
	while(IsMonster)
	{
		if (strcmp(IsMonster->name, name) == 0)
		{
			return IsMonster;
		}
		IsMonster = IsMonster->pNext;
	}
	return nullptr;
}

void DeleteAll(MonsterList& list)
{
	Monster* IsMonster = list.pHead;

	// 백업용
	Monster* pNext{};
	
	// pHead가 nullptr이 아니면
	// 반복하며 지워 준다.
	while (IsMonster)
	{
		pNext = IsMonster->pNext;
		delete IsMonster;
		IsMonster = pNext;
	}

	// 둘 다 다시 초기화
	list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
	Monster* IsMonster = list.pHead;
	Monster* Previous = nullptr;
	
	while (IsMonster)
	{
		if (strcmp(IsMonster->name, name) == 0)
		{
			break;
		}

		Previous = IsMonster;
		IsMonster = IsMonster->pNext;
	}

	if (!IsMonster)
	{
		return false;
	}

	if (list.pHead == list.pTail)
	{
		list.pHead = list.pTail = nullptr;
	}
	else if (Previous == nullptr)
	{
		list.pHead = IsMonster->pNext;
	}
	else if (IsMonster == list.pTail)
	{
		list.pTail = Previous;
		Previous->pNext = nullptr;
	}
	else
	{
		Previous->pNext = IsMonster->pNext;
	}
	return true;
}
