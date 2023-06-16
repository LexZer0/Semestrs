#include <iostream>
#include "animal.h"
using namespace std;

int Animal::count = 0;
Animal::Animal(string name, int age, double weight)
{
	this->name = name;
	this->age = age;
	this->weight = weight;
	count++;
}
Animal::~Animal()
{
	count--;
};

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
	os << "Name: " << animal.name << ", Age: " << animal.age << ", Weight: " << animal.weight;
	return os;
}
std::istream& operator>>(std::istream& is, Animal& animal)
{
	cout << "Enter name: ";
	is >> animal.name;
	cout << "Enter age: ";
	is >> animal.age;
	cout << "Enter weight: ";
	is >> animal.weight;
	return is;
}
bool Animal::operator==(const Animal& animal) const
{
	return (this->name == animal.name && this->age == animal.age && this->weight == animal.weight);
}
bool Animal::operator!=(const Animal& animal) const
{
	return (this->name != animal.name && this->age != animal.age && this->weight != animal.weight);
}
int Animal::getCount()
{
	return count;
}