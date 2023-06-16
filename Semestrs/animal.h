#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;

class Animal
{
protected:
	string name;
	int age;
	double weight;
	static int count;
public:
	Animal(string name, int age, double weight);
	~Animal();
	virtual void move() = 0;
	virtual void makeSound() = 0;
	friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
	friend std::istream& operator>>(std::istream& is, Animal& animal);
	bool operator==(const Animal& animal) const;
	bool operator!=(const Animal& animal) const;
	static int getCount();
};
#endif