#include "zoo.h"

std::string enterString()
{
	std::string line;
	std::cin.ignore();
	getline(std::cin, line);
	return line;
}
int enterAge()
{
	int age;
	std::cout << "Enter the age: ";
	std::cin >> age;
	return age;
}

void Zoo::addCanines()
{
	std::cout << "\nEnter the name: ";
	std::string name = enterString();
	int age = enterAge();
	std::cout << "Enter the food: ";
	std::string food = enterString();
	std::cout << "Enter the level of danger (1-10): ";
	int dangerLevel;
	std::cin >> dangerLevel;
	std::string check;
	if (dangerLevel < 5)
		check = "pet";
	else
		check = "wild";
	std::cout << "Check: " << check;

	Canines* can = new Canines(name, age, food, dangerLevel, check);
	zoo.push_back(can);
}
void Zoo::addEquine()
{
	std::cout << "\nEnter the name: ";
	std::string name = enterString();
	int age = enterAge();
	double height;
	std::cout << "Enter the species: ";
	std::string species = enterString();
	std::cout << "Enter the height (in metres): ";
	std::cin >> height;
	std::cout << "Enter the colour: ";
	std::string colour = enterString();

	Equine* eq = new Equine(name, age, species, colour, height);
	zoo.push_back(eq);
}
void Zoo::addCetacea()
{
	std::cout << "\nEnter the name: ";
	std::string name = enterString();
	int age = enterAge();
	double size = 0;
	std::cout << "Enter the habitat: ";
	std::string cetaplace = enterString();
	std::cout << "Enter the size (in metres): ";
	std::cin >> size;

	Cetacea* ceta = new Cetacea(name, age, cetaplace, size);
	zoo.push_back(ceta);
}
void Zoo::addAnimal()
{
	int ch;
	while (true)
	{
		std::cout << "\nAdd: \n\t1 - to Canines\n\t2 - to Equines\n\t3 - to Cetacea\n\t0 - exit\n\nEnter: ";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
			addCanines();
			std::cout << "\n\nData was added.\n\n";
			break;
		case 2:
			addEquine();
			std::cout << "\nData was added.\n\n";
			break;
		case 3:
			addCetacea();
			std::cout << "\nData was added.\n\n";
			break;
		case 0:
			return;
		default:
			std::cout << "\nThe action was not chosen!\n\n";
		}
	}
}

void Zoo::deleteZoo()
{
	for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end(); ++animal)
		delete* animal;
	zoo.clear();
	std::cout << "\nData was deleted.\n\n";
}
void Zoo::deleteAnimal(std::string family)
{
	for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end();)
	{
		if ((*animal)->getFamily() == family)
		{
			delete* animal;
			animal = zoo.erase(animal);
		}
		else ++animal;
	}
	std::cout << "\nData was deleted.\n\n";
}
void Zoo::delAnimal()
{
	int id;
	std::cout << "Enter the ID of the animal you want to delete: ";
	std::cin >> id;
	/*for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end();)
	{
		if ((*animal) == zoo[id-1])
		{
			delete *animal;
			animal = zoo.erase(animal);
			break;
		}
		else ++animal;
	}*/
	delete zoo[id - 1];
	zoo.erase(zoo.begin() + id - 1);
	std::cout << "\nData was deleted.\n\n";
}
void Zoo::del()
{
	int ch;
	int i = 0;
	while (true) {
		std::cout << "\nChoose:\n\t1 - delete all animals\n\t2 - delete canines\n\t3 - delete equines";
		std::cout << "\n\t4 - delete cetaceas\n\t5 - delete by ID\n\t0 - exit\n\nEnter: ";
		std::cin >> ch;
		if (zoo.empty())
		{
			std::cout << "\nNo animals in list!\n" << std::endl;
			return;
		}
		else
			switch (ch)
			{
			case 1:
				deleteZoo();
				break;
			case 2:
				deleteAnimal("canines");
				break;
			case 3:
				deleteAnimal("equine");
				break;
			case 4:
				deleteAnimal("cetacea");
				break;
			case 5:
				delAnimal();
				break;
			case 0:
				return;
			default:
				std::cout << "\nThe action was not chosen!\n";
			}
	}
}

void Zoo::editByFamily(std::string family, int id)
{
	if (zoo[id - 1]->getFamily() == family)
		zoo[id - 1]->edit();
}
void Zoo::edit()
{
	if (zoo.empty())
	{
		std::cout << "\nNo animals in list!\n" << std::endl;
		return;
	}
	else {
		int id;
		std::cout << "Enter the ID of the animal you want to edit: ";
		std::cin >> id;
		if (id == -1)
		{
			std::cout << "Error! " << std::endl;
			return;
		}
		int ch;
		std::cout << "\n\t1 - main info\n\t2 - edit in Canines\n\t3 - edit in Equine\n\t4 - edit in Cetacea\n\t0 - exit\nEnter: ";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
			zoo[id - 1]->editAnimal();
			break;
		case 2:
			editByFamily("canines", id);
			break;
		case 3:
			editByFamily("equine", id);
			break;
		case 4:
			editByFamily("cetacea", id);
			break;
		case 0:
			return;
		default:
			"\nThe action was not chosen!\n";
		}
	}
	std::cout << "\nData was edited\n" << std::endl;
}

void Zoo::printAnimals(std::string family)
{
	int id = 1;
	for (const auto& animal : zoo)
	{
		if (animal->getFamily() == family)
		{
			std::cout << id;
			animal->print();
			id++;
		}
	}
}
void Zoo::printZoo()
{
	int id = 1;
	for (const auto& animal : zoo)
	{
		std::cout << id;
		animal->print();
		id++;
	}
}
void Zoo::print()
{
	int ch;
	int i = 0;
	while (true) {
		std::cout << "\nChoose:\n\t1 - print all animals\n\t2 - print canines\n\t3 - print equines\n\t4 - print cetaceas\n\t0 - exit\n\nEnter: ";
		std::cin >> ch;
		if (zoo.empty())
		{
			std::cout << "\nNo animals in list!\n" << std::endl;
			return;
		}
		else
			switch (ch)
			{
			case 1:
				printZoo();
				break;
			case 2:
				printAnimals("canines");
				break;
			case 3:
				printAnimals("equine");
				break;
			case 4:
				printAnimals("cetacea");
				break;
			case 0:
				return;
			default:
				std::cout << "\nThe action was not chosen!\n";
			}
	}
}

void Zoo::load()
{
	std::ifstream file("fileZoo.txt");
	if (file.is_open())
	{
		std::cout << "\nThe file is open!" << std::endl;

		int age;
		std::string line, name, family;
		while (file >> line)
		{
			std::getline(file, line, ':');
			file >> family;
			std::getline(file, line, ':');
			file >> name;
			std::getline(file, line, ':');
			file >> age;
			Animals* an = new Animals(name, age);
			if (family == "canines")
			{
				std::string food, check;
				int danger;
				std::getline(file, line, ':');
				file >> food;
				std::getline(file, line, ':');
				file >> danger;
				std::getline(file, line, ':');
				file >> check;
				Canines* can = new Canines(name, age, food, danger, check);
				zoo.push_back(can);
			}
			if (family == "equine")
			{
				std::string species, colour;
				double height;
				std::getline(file, line, ':');
				file >> species;
				std::getline(file, line, ':');
				file >> colour;
				std::getline(file, line, ':');
				file >> height;
				Equine* eq = new Equine(name, age, species, colour, height);
				zoo.push_back(eq);
			}
			if (family == "cetacea")
			{
				std::string place;
				double size;
				std::getline(file, line, ':');
				file >> place;
				std::getline(file, line, ':');
				file >> size;
				Cetacea* ceta = new Cetacea(name, age, place, size);
				zoo.push_back(ceta);
			}
		}
		file.close();
		std::cout << "\nData was successfully loaded from file.\n" << std::endl;
	}
	else
	{
		std::cout << "\nThe file isn't open!\n" << std::endl;
		return;
	}
}

void Zoo::save()
{
	std::ofstream file("fileZoo.txt");
	if (file.is_open())
	{
		std::cout << "\nThe file is open!" << std::endl;
		int id = 1;
		for (const auto& animal : zoo)
		{
			file << id;
			animal->save(file);
			id++;
		}
		std::cout << "\n\nData was successfully saved to file!\n" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "\nThe file isn't open!\n" << std::endl;
		return;
	}
}

void Zoo::sort(std::vector <Animals*>& anim, int ch)
{
	int size = anim.size();
	for (auto start = 0; start < size; start++)
	{
		auto smallest = start;
		{
			for (auto cur = start + 1; cur < size; ++cur)
			{
				switch (ch)
				{
				case 1:
					if (anim[cur]->getName() < anim[smallest]->getName())
						smallest = cur;
					break;
				case 2:
					if (anim[cur]->getAge() > anim[smallest]->getAge())
						smallest = cur;
					break;
				case 0:
					return;
				default:
					std::cout << "\nThe action wasn't chosen\n";
				}
			}
			std::swap(anim[start], anim[smallest]);
		}
	}
}

void Zoo::sortBy()
{
	int ch;
	std::cout << "\nSort by:\n\t1 - name\n\t2 - age\n\t0 - exit\n\nEnter: ";
	std::cin >> ch;
	sort(zoo, ch);
}

void Zoo::sortInCan()
{
	std::vector <Canines*> arr_can;
	for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end();)
	{
		if ((*animal)->getFamily() == "canines")
			arr_can.push_back(static_cast<Canines*>(*animal));
		++animal;
	}
	std::cout << "\nSort by danger:\n\n";

	int size = arr_can.size();
	for (auto start = 0; start < size; start++)
	{
		auto smallest = start;
		{
			for (auto cur = start + 1; cur < size; ++cur)
			{
				if (arr_can[cur]->getDanger() > arr_can[smallest]->getDanger())
					smallest = cur;
			}
			std::swap(arr_can[start], arr_can[smallest]);
		}
	}

	int id = 1;
	for (const auto& cans : arr_can)
	{
		std::cout << id;
		cans->print();
		id++;
	}
}

void Zoo::sortInEqu()
{
	std::vector <Equine*> arr_eq;
	for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end();)
	{
		if ((*animal)->getFamily() == "equine")
			arr_eq.push_back(static_cast<Equine*>(*animal));
		++animal;
	}
	std::cout << "\nSort by height: \n\n";
	
	int size = arr_eq.size();
	for (auto start = 0; start < size; start++)
	{
		auto smallest = start;
		{
			for (auto cur = start + 1; cur < size; ++cur)
			{
				if (arr_eq[cur]->getHeight() < arr_eq[smallest]->getHeight())
					smallest = cur;
			}
			std::swap(arr_eq[start], arr_eq[smallest]);
		}
	}

	int id = 1;
	for (const auto & eqs : arr_eq)
	{
		std::cout << id;
		eqs->print();
		id++;
	}
}

void Zoo::sortInCeta()
{
	std::vector <Cetacea*> arr_ceta;
	for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end();)
	{
		if ((*animal)->getFamily() == "cetacea")
			arr_ceta.push_back(static_cast<Cetacea*>(*animal));
		++animal;
	}
	std::cout << "\nSort by size: \n\n";

	int size = arr_ceta.size();
	for (auto start = 0; start < size; start++)
	{
		auto smallest = start;
		{
			for (auto cur = start + 1; cur < size; ++cur)
			{
				if (arr_ceta[cur]->getSize() < arr_ceta[smallest]->getSize())
					smallest = cur;
			}
			std::swap(arr_ceta[start], arr_ceta[smallest]);
		}
	}

	int id = 1;
	for (const auto& cetas : arr_ceta)
	{
		std::cout << id;
		cetas->print();
		id++;
	}
}

void Zoo::menu()
{
	int ch;
	while (true) {
		std::cout << "\nChoose the function:\n\t1 - print\n\t2 - add animal\n\t3 - delete\n\t4 - edit\n\t";
		std::cout << "5 - load file\n\t6 - save to file\n\t7 - sort main class\n\t8 - sort canines (danger)\n\t";
		std::cout << "9 - sort equines (height)\n\t10 - sort cetaceas (size)\n\t0 - end program\n\nEnter: ";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
			print();
			break;
		case 2:
			addAnimal();
			break;
		case 3:
			del();
			break;
		case 4:
			edit();
			break;
		case 5:
			load();
			break;
		case 6:
			save();
			break;
		case 7:
			sortBy();
			break;
		case 8:
			sortInCan();
			break;
		case 9:
			sortInEqu();
			break;
		case 10:
			sortInCeta();
			break;
		case 0:
			return;
		default:
			"\nThe action was not chosen!\n";
		}
	}
}