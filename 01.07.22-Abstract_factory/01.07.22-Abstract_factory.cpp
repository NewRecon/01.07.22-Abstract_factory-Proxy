#include <iostream>
#include <fstream>
#include <string>

#define Prox

#if Factor

class Trucking
{
public:
	virtual void delive() = 0;
};

class Car : public Trucking
{
private:
	int id;
public:
	Car(int id)
	{
		this->id = id;
	}
	void delive() override
	{
		std::cout << id << " " << "Car" << std::endl;
	}
};

class Ship : public Trucking
{
private:
	int id;
public:
	Ship(int id)
	{
		this->id = id;
	}
	void delive() override
	{
		std::cout << id << " " << "Ship" << std::endl;
	}
};

class Factory
{
public:
	virtual Trucking* createTrucking(int id) = 0;
};

class CarFactory : public Factory
{
public:
	Trucking* createTrucking(int id) override
	{
		Car* car = new Car(id);
		return car;
	}
};

class ShipFactory : public Factory
{
public:
	Trucking* createTrucking(int id) override
	{
		Ship* ship = new Ship(id);
		return ship;
	}
};

int main()
{
	CarFactory cf;
	ShipFactory sf;
	Trucking* truck1 = cf.createTrucking(1);
	truck1->delive();
	Trucking* truck2 = sf.createTrucking(2);
	truck2->delive();
}

#else Prox

struct Proxy
{
	std::string id;
	std::string data;
};

class FileManager
{
private:
	std::string path;
	Proxy* proxy = nullptr;
	std::string date;
public:
	std::string getData(std::string id)
	{
		std::ifstream in{path};
		std::string str;
		if (in.is_open())
		{
			getline(in, str);
			if (str == date)
			{
				return proxy->data;
			}
			else
			{
				this->date = str;
				Proxy* prox = new Proxy;
				this->proxy = prox;
				int n;
				while (getline(in, str))
				{
					bool flag = true;
					for (int i = 0; i < size(id); i++)
					{
						if (str[i] != id[i])
						{
							flag = false;
							break;
						}
						else if (str[size(id) + 1] == ' ')
						{
							n = i;
							break;
						}
					}
					if (flag)
					{
						for (int i = n, k=0; str[i] != '\0'; i++)
						{
							prox->data[k++] = str[i];
						}
						return prox->data;
					}
				}
			}
		}
		else std::cout << "ERROR 404 FILE NOT FOUND";
	}
};

int main()
{

}

#endif