#include<iostream>
#include"SingleLinkedList.h"
int main()
{
	MonsterList myList;
	CreateMonster(myList, "����", 30);
	CreateMonster(myList, "��", 20);
	CreateMonster(myList, "��", 10);

	PrintMonsters(myList);

}