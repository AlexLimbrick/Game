#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Cat
{
public:
	Cat(int _age = 5, string _name = "Fluffy");
	Cat(const Cat& _copyCat);
	Cat& operator=(const Cat& _copyCat);
	~Cat();
	void DisplayCat();
	static void ShowCount();
private:
	static int count;
	int age;
	string* name;
};

