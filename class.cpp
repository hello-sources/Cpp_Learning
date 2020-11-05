/*************************************************************************
	> File Name: class.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 01 Nov 2020 10:12:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public : 
    Point() : _x(0), _y(0), _cnt(0) {
        this->total += 1;
        cout << "Point constructor : " << this <<  endl;
    }
    Point(int x, int y) : Point() {
        this->_x = x;
        this->_y = y;
        cout << "Point constructor with parameters : " << this << endl;
    }
    Point(const Point &b) : Point() {//拷贝构造函数，既可以传常数也可以传变量
        this->total += 1;
        cout << "Point copy constructot : " << this << endl;
        this->_x = b._x;
        this->_y = b._y;
        this->_cnt = b._cnt;
    }
    int getX() const { 
        this->_cnt += 1;
        return this->_x; 
    }
    int getY() const { return this->_y; }
    
    static int getTotal() { return Point::total; }
    
    ~Point() {
        this->total -= 1;
        cout << "Point deconstrucor" << endl;
    }
    
private :
    int _x, _y;
    mutable int _cnt;//表示可以随意变化类型

    static int total;
};

int Point::total = 0;

void func(Point &b) {
    cout << "b : " << (&b) << endl;
    return ;
}

ostream& operator<<(ostream &out, const Point &p) {
    out << "(" << p.getX() << ", " << p.getY() << ")";
    return out;
}

void func2() {
    Point a, b, c;
    return ;
}

int main() {
    const Point p(4, 5);
    Point p1(2, 3), p2(p1);
    func(p1);
    func2();
    cout << p1 <<  " " << p2 << endl;
    cout << p1.getX() << endl;
    cout << Point::getTotal() << endl;
    return 0;
}
