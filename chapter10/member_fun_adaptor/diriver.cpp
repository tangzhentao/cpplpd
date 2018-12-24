/*
 * 例10-19
 * 熟悉成员函数适配器
 */
#include <iostream>
#include <vector>

using namespace std;

struct Car
{
	Car(int num): id(num) {};
	void display() const 
	{
		cout << "car: " << id << endl;
	}

	~Car() 
	{
		cout << "car: " << id << endl;
	}

	int id;
};

int main()
{
	vector<Car *> pCars;
	for(int i = 0; i < 5; i++)
	{
		pCars.push_back(new Car(i));
	}

	vector<Car> cars;
	for(int i = 5; i < 15; i++)
	{
		cars.push_back(Car(i));
	}

	cout << "elements in pCars:" << endl;
	for_each(pCars.begin(), pCars.end(), mem_fun(&Car::display) );
	cout << endl;


	cout << "elements in cars:" << endl;
	for_each(cars.begin(), cars.end(), mem_fun_ref(&Car::display) );
	cout << endl;

	cout << "delete pointer type element in pCars" << endl;
	for(size_t i = 0; i < pCars.size(); i++)
		delete pCars[i];

	return 0;
}
