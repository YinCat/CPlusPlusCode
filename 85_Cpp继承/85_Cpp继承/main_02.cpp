#include <iostream>

using namespace std;

//class Car{
//public:
//
//};
//class Person{
//public:
//	//ÉÏ°à³Ë³µ
//	void GoToWork(Car& car){ }
//
//	//Âô³µ
//	Car& SellCar(){ }
//};


class Car{
public:
	void run(){ };
};
class Person{
public:
	void GoWork(){ 
		myCar.run();
	};
private:
	Car myCar;
};


int main()
{
	return 0;
}