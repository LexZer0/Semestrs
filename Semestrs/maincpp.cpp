#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "animal.h"
#include "crocodile.h"
#include "bird.h"
using namespace std;

int main()
{
	// Создание крокодила, птицы с помощью раннего связывания
	Crocodile crocodile("Gena", 35, 150, 2.2, 75, "Evergreen");
	cout << crocodile << endl;
	Bird bird("Kesha", 3, 10, 0.1, 100, "Red");
	cout << bird << endl << endl;

	Animal* animal;
	// Создание крокодила или птицы с помощью позднего связывания
	int choice;
	cout << "Choose animal:" << endl << "1. Crocodile" << endl << "2. Bird" << endl;
	cin >> choice;
	if (choice == 1)
	{
		animal = new Crocodile("Henry", 10, 300, 2.5, 80, "Green");
	}
	else if (choice == 2)
	{
		animal = new Bird("Agar", 5, 20, 0.3, 150, "Gradio blue");
	}
	else
	{
		return 1;
	}
	cout << *animal << endl;
	animal->move();
	animal->makeSound();	

	// Создание вектора и добавление объектов
	vector <Animal*> animals;
	animals.push_back(&crocodile);
	animals.push_back(&bird);
	animals.push_back(animal);

	// Сохранение вектора в файл 
	ofstream fout("animals.txt");
	if (fout.is_open())
	{
		for (Animal* a : animals)
		{
			fout << *a << endl;
		}
		fout.close();
	}

	// Очистка вектора 
	animals.clear();

	// Загрузка вектора из файла
	ifstream fin("animals.txt");
	if (fin.is_open())
	{
		string line;
		while (getline(fin, line))
		{
			stringstream ss(line);
			int type;
			ss >> type;
			if (type == 1)
			{
				Crocodile* c = new Crocodile("name", 1, 1.0, 1.0, 1, "color");
				ss >> *c;
				animals.push_back(c);
			}
			else if (type == 2)
			{
				Bird* b = new Bird("name", 1, 1.0, 1.0, 1, "color");
				ss >> *b;
				animals.push_back(b);
			}
		}
		fin.close();
	}
	//Вывод количества созданных объектов
	cout << "Objects created: " << Animal::getCount() << endl;
	return 0;
}