/*************************************************************************
	> File Name: Template_Turing-1.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 10:47:50 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<int x>
struct IsOdd {
    constexpr static int r = x % 2;
};

template<int i, int x>
struct getNextK {
    constexpr static int r = (i * i > x ? 0 : (x % i == 0 ? 1 : 2));
};

template<int i, int x, int k>
struct Test {
    constexpr static int r = Test<i + 1, x, getNextK<i, x>::r >::r;
};

template<int i, int x>
struct Test<i, x, 0> {
    constexpr static int r = 1;
};

template<int i, int x>
struct Test<i, x, 1> {
    constexpr static int r = 0;
};

template<int x>
struct is_prime {
    constexpr static int r = Test<2, x, 2>::r;
};

template<int i, int x>
struct getNextK2 {
    constexpr static int r = (i > x ? 0 : 1);
};

template<int i, int x, int k>
struct __calc_count_prime {
    constexpr static int r = i * is_prime<i>::r + __calc_count_prime<i + 1, x, getNextK2<i + 1, x>::r >::r;
};

template<int i, int x>
struct __calc_count_prime<i, x, 0> {
    constexpr static int r = 0;
};

template<int x>
struct count_prime {
    constexpr static int r = __calc_count_prime<2, x, 1>::r;
};

template<int i, int x, int k>
struct __calc_count_odd {
    constexpr static int r = i * IsOdd<i>::r + __calc_count_odd<i + 1, x, getNextK2<i + 1, x>::r >::r;
};

template<int i, int x>
struct __calc_count_odd<i, x, 0> {
    constexpr static int r = 0;
};

template<int x>
struct count_odd {
    constexpr static int r = __calc_count_odd<1, x, 1>::r;
};

template<int x>
struct print_prime {
    template<int i, int k>
    struct __output {
        static void run() {
            if (is_prime<i>::r) {
                cout << i << endl;
            }
            print_prime<x>::__output<i + 1, getNextK2<i + 1, x>::r >::run();
        }
    };
    template<int i>
    struct __output<i, 0> {
        static void run() {
            return ;
        }
    };
    static void output() {
        print_prime<x>::__output<2, 1>::run();
        return ;
    }
};

template<int x, int k>
struct __get_next_prime {
    constexpr static int r = __get_next_prime<x + 1, is_prime<x + 1>::r >::r;
};

template<int x>
struct __get_next_prime<x, 1> {
    constexpr static int r = x;
};

template<int x>
struct get_next_prime {
    constexpr static int r = __get_next_prime<x + 1, is_prime<x + 1>::r >::r;
};

template<int n>
struct print_trangle {
    template<int i, int m, int k>
    struct __output_line {
        static void run() {
            cout << "-";
            __output_line<i + 1, m, getNextK2<i + 1, m>::r >::run();
        }
    };
    template<int i, int m>
    struct __output_line<i, m, 0> {
        static void run() {
            cout << endl;
        }
    };
    template<int i, int k>
    struct __output {
        static void run() {
            __output_line<1, i, 1>::run();
            __output<i + 1, getNextK2<i + 1, n>::r >::run();
        }
    };
    template<int i>
    struct __output<i, 0> {
        static void run() {
            return ;
        }
    };
    
    static void output() {
        __output<1, 1>::run();
    }
};

int main() {
    cout << IsOdd<5>::r << endl;
    cout << IsOdd<6>::r << endl;
    cout << is_prime<9973>::r << endl;
    cout << is_prime<10000>::r << endl;
    cout << count_prime<100>::r << endl;
    cout << count_prime<10>::r << endl;
    cout << count_odd<10>::r << endl;
    print_prime<100>::output();
    cout << get_next_prime<5>::r << endl; 
    cout << get_next_prime<12>::r << endl;
    print_trangle<4>::output(); 
    print_trangle<6>::output(); 
    return 0;
}
