#include <iostream>
#include "crocodile.h"
using namespace std;

Crocodile::Crocodile(string name, int age, double weight, double jawLenght, int toothCount, string color) : Animal(name, age, weight)
{
	this->jawLenght = jawLenght;
	this->toothCount = toothCount;
	this->color = color;
}
Crocodile::~Crocodile()
{
	cout << "Crocodile " << name << " was destroyed." << endl;
}

void Crocodile::move()
{
	cout << "Crocodile " << name << " swims in the water." << endl;
}
void Crocodile::makeSound()
{
	cout << "Crocodile " << name << " hisses." << endl;
}

bool Crocodile::operator<(const Crocodile& croc) const
{
	return (this->jawLenght < croc.jawLenght);
}
bool Crocodile::operator>(const Crocodile& croc) const
{
	return (this->jawLenght > croc.jawLenght);
}