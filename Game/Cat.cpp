#include "Cat.h"


int Cat::count = 0;
Cat::Cat(int _age , string _name )
{
	age = _age;
	name = new string(_name);
	cout << "A Cat Has Been Born!!!" << endl;
	count++;
}

Cat::Cat(const Cat & _copyCat)
{
	age = _copyCat.age;
	name = new string (*_copyCat.name);
	cout << "A Copy Cat Has Been Born!!!" << endl;
	count++;
}

Cat & Cat::operator=(const Cat & _copyCat)
{
	if (this != &_copyCat)
	{ 
	delete name;
	age = _copyCat.age;
	name = new string(*_copyCat.name);
	cout << "A Cat Has Been assined!!!" << endl;
	
	}
	return *this;
}

Cat::~Cat()
{
	delete name;
	cout << "Oh No A Cat Died" << endl;
	count--;
}

void Cat::DisplayCat()
{
	cout << *name << endl;
	cout << "age: " << age << endl;
}

void Cat::ShowCount()
{
	cout << "Cat Count: " << count << endl;
}
