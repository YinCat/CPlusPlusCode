#include <iostream>

using namespace std;

//class Car{
//public:
//
//};
//class Person{
//public:
//	//�ϰ�˳�
//	void GoToWork(Car& car){ }
//
//	//����
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