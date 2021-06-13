#pragma once
#include "classAnimals.h"

class Canines : public Animals
{
	std::string _food;
	int _dangerLevel;
	const std::string _family = "canines";
	std::string _check;
public:
	Canines() {
		_food = "unknown"; _dangerLevel = 0; _check = "unknown";
	}
	Canines(std::string name, int age, std::string place, int danger, std::string check);
	const std::string getFood();
	void setFood(std::string food) { _food = food; }
	const std::string getCheck();
	void setCheck(std::string check) { _check = check; }
	const int getDanger();
	void setDanger(int danger) { _dangerLevel = danger; }
	std::string getFamily() { return _family; }
	void setFamily() { _familyAnimal = _family; }
	void print();
	void edit();
	void save(std::ofstream& F);
};