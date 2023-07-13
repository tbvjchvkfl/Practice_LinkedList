#include<iostream>
#include"SingleLinkedList.h"
int main()
{
	MonsterList myList;
	CreateMonster(myList, "´Á´ë", 30);
	CreateMonster(myList, "¿ë", 20);
	CreateMonster(myList, "°õ", 10);

	PrintMonsters(myList);

}