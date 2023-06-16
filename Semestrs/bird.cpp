#include <iostream>
#include "bird.h"
using namespace std;

Bird::Bird(string name, int age, double weight, double tailLenght, int speed, string featherColor) : Animal(name, age, weight)
{
	this->tailLenght = tailLenght;
	this->speed = speed;
	this->featherColor = featherColor;
}
Bird::~Bird()
{
	cout << "Bird " << name << " was destroyed." << endl;
}

void Bird::move()
{
	cout << "Bird " << name << " fly in the sky." << endl;
}
void Bird::makeSound()
{
	cout << "Bird " << name << " tweet." << endl;
}

bool Bird::operator<=(const Bird& bird) const
{
	return (this->featherColor < bird.featherColor);
}
bool Bird::operator>=(const Bird& bird) const
{
	return (this->featherColor > bird.featherColor);
}