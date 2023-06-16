#pragma once
#ifndef CROCODILE_H
#define CROCODILE_H
#include "animal.h"
#include <iostream>
using namespace std;

class Crocodile : public Animal
{
private:
	double jawLenght;
	int toothCount;
	string color;
public:
	Crocodile(string name, int age, double weight, double jawLenght, int toothCount, string color);
	~Crocodile();
	void move() override;
	void makeSound() override;
	bool operator<(const Crocodile& croc) const;
	bool operator>(const Crocodile& croc) const;
};
#endif