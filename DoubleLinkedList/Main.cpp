#include<iostream>
#include "DoubleLinkedList.h"


int main()
{
	DMonsterList myList;

	CreateMonster(myList, "����", 20);
	CreateMonster(myList, "��", 40);
	CreateMonster(myList, "�Ź�", 60);
	CreateMonster(myList, "�Ǹ�", 80);
	CreateMonster(myList, "��", 100);
	PrintMonsters(myList);

	FindMonsters(myList, "��");
	DeleteAll(myList);
}