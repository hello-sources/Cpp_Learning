/*************************************************************************
	> File Name: Factory.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 11 Jan 2021 03:04:38 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

class ICar {
public :
	class IFactory {
	public :
		virtual ICar *create() = 0;
	};
	virtual void run() = 0;
protected :
	ICar() {}
	~ICar() {}
};

class BenzCar : public ICar {
	BenzCar() {}
public :
	class Factory : public ICar::IFactory {
	public :
		virtual ICar *create() {
			return new BenzCar();
		}
	}; 
	virtual void run() {
		cout << "Benz run" << endl;
	}
};

class BmwCar : public ICar {
	BmwCar() {}
public :
	class Factory : public ICar::IFactory {
	public :
		virtual ICar *create() {
			return new BmwCar();
		}
	}; 
	virtual void run() {
		cout << "Bmw run" << endl;
	}
};

class AudiCar : public ICar {
	AudiCar() {}
public :
	class Factory : public ICar::IFactory {
	public :
		virtual ICar *create() {
			return new AudiCar();
		}
	}; 
	virtual void run() {
		cout << "Audi run" << endl;
	}
};

ICar::IFactory *fac[3] = {new BenzCar::Factory(), new AudiCar::Factory(), new BmwCar::Factory()};

int main() {
	ICar *cars[10];
	for (int i = 0; i < 10; i++) {
		cars[i] = fac[rand() % 3]->create();
	}	
	for (int i = 0; i < 10; i++) {
		cars[i]->run();
	}
	return 0;
}
