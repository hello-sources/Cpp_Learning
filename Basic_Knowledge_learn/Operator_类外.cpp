/*************************************************************************
	> File Name: Operator_类外.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 08 Jan 2021 02:17:06 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public :
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	Point(const Point &obj) : x(obj.x), y(obj.y) {
		cout << "Copy Constructor" << endl;
	}
	friend Point operator+(const Point &, const Point &);
private :
	int x, y;
};

Point operator+(const Point &a, const Point &b) {
	Point ret;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return ret;
}

int main() {
	Point a(2, 4), b(5, 3);
	Point c = a + b;
	Point d = a + b + c;
	return 0;
} 
