/*************************************************************************
	> File Name: succeed_2.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 04 Nov 2020 05:59:53 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public :
	Data() {}
	Data(const string &data) {
		cout << data << endl;
	} 
};

class Animal {
public :
	Animal(const string &name, int x = 0) : d2("I'm d2"), d1("I'm d1"),_name(name), _x(x) {
		cout << "Animal Constructor" << endl;
	}
	Animal(const Animal &a) : _x(a._x + 1), _name(a._name) {}
	int x() { return this->_x; }
	string name() { return this->_name; }
    void run() {
        cout << "I can Run" << endl;
    }
	~Animal() {
		cout << "Animal Destructor" << endl;
	}

private :
	Data d1, d2;
	string _name;
	int _x;
};

class Cat : public Animal {
public :
	Cat() : Animal("cat-1") {
		cout << "Cat constructor" << endl;
	}
	Cat(const Cat &obj) : Animal(obj), _y(obj._y) {}
	void run() {
        cout << "I can run, like a Cat" << endl;
    }
    Cat(string name, int x, int y) : Animal(name, x), _y(y) {}
	int y() { return this->_y; }
	~Cat() {
		cout << "Cat Destructor" << endl;
	}
private :
	int _y;
};

class Dog : public Animal {
    public :
        Dog() : Animal("Dog-1") {}
        void run() {
            cout << "T can run, like a dog" << endl;
        }
};

ostream &operator<<(ostream &out, Cat &a) {
	out << "<Class Cat>";
	out << a.name() << " " << a.x() << " " << a.y();
	return out; 
}

int main() {
	Cat c1("hello kitty", 0, 54);
	Cat c2(c1);
    Dog d1;
	cout << c1 << endl;
	cout << c2 << endl;
    Animal *p[2] = {&c1, &d1};
    //Animal *p1 = &c1, *p2 = &d1;
    p[0]->run();
    p[1]->run();
	return 0;
}
