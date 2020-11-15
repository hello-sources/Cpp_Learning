/*************************************************************************
	> File Name: move_constructor.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 11 Nov 2020 11:15:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Point {
public :
    Point(int x, int y) : x(x), y(y) {}
private :
    int x, y;
};

template<typename T>
class Array {
public :
    Array(size_t n = 100) : size(n) {
        cout << "constructor" << endl;
        this->data = (T *)calloc(sizeof(T), size);
    }
    Array(const Array<T> &obj) : size(obj.size) {
        cout << "copy constructor" << endl;
        this->data = (T *)calloc(sizeof(T), size);
        for (int i = 0; i < size; i++) {
            new(this->data + i) T(obj.data[i]);
        }
    }
    Array(Array<T> &&obj) : size(obj.size) {
        cout << "move constructor" << endl;
        this->data = obj.data;
        obj.data = nullptr;
        obj.size = 0;
    }
    Array<T> operator+(const Array<T> &obj) {
        Array<T> ret(this->size + obj.size);
        for (int i = 0; i < this->size; i++) {
            ret.data[i] = this->data[i];
        }
        for (int i = this->size; i < this->size + obj.size; i++) {
            ret.data[i] = obj.data[i - this->size];
        }
        return ret;
    }
    T &operator[](size_t ind) {
        return this->data[ind];
    }
    void output() {
        cout << "Array(" << size << ") = [";
        for (int i = 0; i < size; i++) {
            cout << " " << this->data[i];
        }
        cout << "]" << endl;
        return ;
    }
    ~Array() {
        cout << "destructor" << endl;
        delete[] this->data;
    }
    
private:
    T *data;
    size_t size;
};

int main() {
    Array<int> a(20), b(20);
    for (int i = 0; i < 20; i++) a[i] = i, b[i] = i;
    Array<int> c(a + b);
    return 0;
}
