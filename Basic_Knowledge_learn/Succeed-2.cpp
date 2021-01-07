/*************************************************************************
	> File Name: Succeed-2.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 07 Jan 2021 08:41:13 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define P_ADD(obj, a) cout << #obj"." #a " = " << &(obj.a)

class Animal {
public :
	Animal(string name) : __name(name) {
		cout << "Animal Constructor " << this << endl;
	}
	string name() { return this->__name; }
	
	int x, y;
	string __name;
	~Animal() {
		cout << "Animal Destructor " << this << endl;
	}
}; 

class Cat : public Animal {
public :
	Cat(): Animal("hello kitty") {
		arr = new int[100];
		cout << "Cat Constructor " << this << endl;
	}
	void say() {
		cout << "My name is " << this->name() << endl;
	} 	
	int z;
	int *arr;
	~Cat() {
		delete arr;
		cout << "Cat Destructor " << this << endl;
	}
};

ostream &operator<<(ostream &out, const Animal &a) {
	out << "<class Animal> " << &a << endl;
	P_ADD(a, x) << endl;
	P_ADD(a, y) << endl;
	P_ADD(a, __name) << endl;
	return out;
}

ostream &operator<<(ostream &out, const Cat &a) {
	out << "<class Cat> " << &a << endl;
	P_ADD(a, x) << endl;
	P_ADD(a, y) << endl;
	P_ADD(a, z) << endl;
	P_ADD(a, __name) << endl;
	return out;
}

int main() {
	Animal a("any");
	Cat c;
	c.say();
	cout << sizeof(a) << " " << sizeof(c) << endl;
	cout << c << endl;
	Animal *p = new Cat();
	cout << "Animal * : " << p->name() << endl;
	delete p;
	Animal &q = c;
	cout << q << endl;
	return 0;
} 
