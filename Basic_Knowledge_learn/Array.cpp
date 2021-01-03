/*************************************************************************
	> File Name: Array.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 31 Oct 2020 09:47:33 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//C++实现一个存储任意类型的数组
template<typename T>
class Array {
    public :
        Array() {
            this->__size = 0;
            this->__cnt  = 0;
            this->data = new T[this->__size];
        }
        Array(int n) {
            this->__size = 2 * n;
            this->__cnt  = n;
            this->data = new T[this->__size];
        }
        void push_back(const T &a) {
            this->data[(this->__cnt)++] = a;    
        }
        int size() {
            return this->__cnt;
        }
        T &operator[](int ind) {
            return this->data[ind]; 
        }

    private :
        T *data;
        int  __size, __cnt;
}; 

int main() {
    vector<int> arr(10);
    Array<int> arr2(10);
    Array<double> arr3(10);
    cout << arr.size() << endl;
    arr.push_back(123);
    cout << arr[0] << endl;
    cout << arr.size() << endl;

    cout << arr2.size() << endl;
    arr2.push_back(123);
    cout << arr2[0] << endl;
    cout << arr2.size() << endl;
    return 0;
}
