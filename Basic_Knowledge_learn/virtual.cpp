/*************************************************************************
	> File Name: virtual.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 04 Nov 2020 09:36:51 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

class Animal {
public :
    Animal() {}
    Animal(string name) : _name(name), _age(3) {}
    virtual void run() {
        cout << _name << "I don't know how to run" << endl;
    }
    string name() { return this->_name; }
    int &age() { return this->_age; }
    virtual ~Animal() {
        cout << "Animal deconstrutor" << endl;
    }

private :
    string _name;
    int _age;
};

class Cat : public Animal {
public :
    Cat () : Animal("Cat-1") {}
    void run() {
        cout << name() << " : I can run with four legs" << endl;
    }
    ~Cat() {
        cout << "Cat deconstrutor" << endl;
    }
};

class Dog : virtual public Animal {
public :
    Dog() : Animal("Dog-1") {}
    void run() {
        cout << name() << " : I can wang wang wang run" << endl;
    }
    int seek_age() { 
        cout << "Dog seek age : " <<  &age() << endl;
        return age(); 
    }
    ~Dog() {
        cout << "Dog deconstrutor" << endl;
    }
};

class Bat : virtual public Animal {
public :
    Bat() : Animal("Bat-1") {}
    void run() {
        cout << name() << " : I can flying" << endl;
    }
    void change_age() {
        age() += 1;
        cout << "Bat change age : " << age() << &age() << endl;
    }
    ~Bat() {
        cout << "Bat deconstrutor" << endl;
    }
};

Animal *getAnimal() {
    int val = rand() % 3;
    switch (val) {
        case 0 : return new Cat();
        case 1 : return new Dog();
        case 2 : return new Bat();
    }
    return nullptr;
}

void func(Animal *p) {
    cout << "func *p" << p << endl;
}

void func(int x) {
    cout << "func x(int)" << x << endl;
}

class SkyDog : public Dog, public Bat {
public :
    void run() {
        cout << "SkyDog : I can suibian run" << endl;
    }
};

int main() {
    srand(time(0));
    func(nullptr);
    //func(NULL);
    Animal **arr = new Animal*[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = getAnimal();
    }
    for (int i = 0; i < 20; i++) {
        arr[i]->run();
    }
    for (int i = 0; i < 20; i++) {
        delete arr[i];
    }
    SkyDog sd;
    sd.change_age();
    sd.change_age();
    sd.change_age();
    sd.change_age();
    sd.change_age();
    sd.change_age();
    cout << sd.seek_age() << endl;

    return 0;
}
