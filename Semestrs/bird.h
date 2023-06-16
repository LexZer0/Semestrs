#pragma once
#ifndef BIRD_H
#define BIRD_H
#include <iostream>
#include "animal.h"
using namespace std;

class Bird : public Animal
{
private:
	double tailLenght;
	int speed;
	string featherColor;
public:
	Bird(string name, int age, double weight, double tailLenght, int speed, string featherColor);
	~Bird();
	void move() override;
	void makeSound() override;
	bool operator<=(const Bird& bird) const;
	bool operator>=(const Bird& bird) const;
};
#endif