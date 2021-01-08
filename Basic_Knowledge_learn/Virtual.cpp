/*************************************************************************
	> File Name: Virtual.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 08 Jan 2021 06:13:15 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

string rand_name(int n) {
	string name = "";
	for (int i = 0; i < n; i++) {
		name = name + (char)(rand() % 26 + 'A');
	}
	return name;
}

class Animal {
public :
	Animal(string name) : name(name) {}
	string tell_me_your_name() { return this->name; }
	virtual void run() {
		cout << "I don't know how to run" << endl;
	}
//	virtual void say() {
//		cout << "I don't know how to say" << endl;
//	} 
	virtual void func0() {}
	virtual void say() = 0;
	virtual ~Animal() {
		cout << "Animal Destructor" << endl;
	}
private :
	string name;
}; 

class Cat : public Animal {
public :
	Cat() : Animal(rand_name(5) + " Cat") {}
	void run() override {
		cout << "I can run with four legs" << endl;
	}
	void func0() override {
		cout << "This is funco" << endl;
	}
	void say() override {
		cout << "miao~ miao~ miao~" << endl;
	}
	~Cat() {
		cout << "Cat Destructor" << endl;
	}
};

class Bat : public Animal {
public :
	Bat() : Animal(rand_name(5) + " Bat") {}
	void run() override {
		cout << "I can fly" << endl;
	}
	void say() override {
		cout << "zzz~ zzz~ zzz~" << endl;
	}
	~Bat() {
		cout << "Bat Destructor" << endl;
	}
};

int main() {
	Cat a;
	Bat b;
	cout << a.tell_me_your_name() << endl;
	a.run();
	cout << b.tell_me_your_name() << endl;
	b.run();
	Animal ** arr = new Animal*[10];
	for (int i = 0; i < 10; i++) {
		if (rand() % 2) {
			arr[i] = new Cat();
		} else {
			arr[i] = new Bat();
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i]->tell_me_your_name() << endl;
		arr[i]->run();
		arr[i]->say();
	}
	for (int i = 0; i < 10; i++) {
		delete arr[i];
	}
	delete[] arr;
	return 0;
} 
