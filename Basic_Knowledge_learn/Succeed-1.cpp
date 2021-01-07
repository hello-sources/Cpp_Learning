/*************************************************************************
	> File Name: Succeed-1.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 07 Jan 2021 08:13:44 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define P_ADD(obj, a) cout << #obj"." #a " = " << &(obj.a)

class Animal {
public :
	Animal(string name) : __name(name) {}
	string name() { return this->__name; }
	
	int x, y;
	string __name;
}; 

class Cat : public Animal {
public :
	Cat(): Animal("hello kitty") {}
	void say() {
		cout << "My name is " << this->name() << endl;
	} 	
	int z;
};

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
	return 0;
} 
