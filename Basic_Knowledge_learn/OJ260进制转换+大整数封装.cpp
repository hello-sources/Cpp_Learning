/*************************************************************************
	> File Name: OJ260进制转换+大整数封装.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 08 Jan 2021 12:53:24 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

auto in_range = [](int b, int e) {
	return [=](int x) {
		return (x <= e && x >= b);
	};
};

auto is_digit = in_range('0', '9');
auto is_upper = in_range('A', 'Z');
auto is_lower = in_range('a', 'z');

class BigInt {
public :
	BigInt(int base, int x) {
		this->base = base;
		this->data.push_back(x);
		this->process_digit();
	}
	BigInt() : BigInt(10, 0) {}
	BigInt(int base, const string &num_str) {
		this->base = base;
		for (int i = num_str.size() - 1; i >= 0; --i) {
			this->data.push_back(BigInt::decode(num_str[i]));
		}
	}
	BigInt &operator*=(int x) {
		vector<int> &vec = this->data;
		for (int i = 0; i < vec.size(); i++) {
			vec[i] *= x;
		}
		this->process_digit();
		return *this;
	}
	BigInt &operator+=(int x) {
		vector<int> &vec = this->data;
		vec[0] += x;
		this->process_digit();
		return *this;
	}
	BigInt &operator+=(const BigInt &x) {
		vector<int> &vec = this->data;
		for (int i = 0; i < x.data.size(); i++) {
			if (i + 1 >= vec.size()) vec.push_back(x.data[i]);
			vec[i] += x.data[i];
		}
		this->process_digit();
		return *this;
	}
	BigInt &operator/=(int x) {
		vector<int> &vec = this->data;
		int i = vec.size() - 1, temp = 0;
		while (i >= 0 && temp * base + vec[i] < x) {
			temp = temp * base + vec[i];
			vec.erase(vec.begin() + (i--));
		}
		if (i == -1) {
			vec.push_back(0);
			return *this;
		}
		while (i >= 0) {
			temp = temp * base + vec[i];
			vec[i--] = temp / x;
			temp %= x;
		}
		return *this;
	}
	int operator%(int x) {
		vector<int> &vec = this->data;
		int temp = 0;
		for (int i = vec.size() - 1; i >= 0; i--) {
			temp = temp * base + vec[i];
			temp %= x;
		}
		return temp;
	}
	BigInt &convert_to(int to_base) {
		if (to_base == this->base) return *this;
		vector<int> result;
		BigInt &num = *this;
		do {
			result.push_back(num % to_base);
			num /= to_base;
		} while (num != 0);
		num.data[0] = result[0];
		for (int i = 1; i < result.size(); i++) {
			num.data.push_back(result[i]);
		}
		return num;
	}
	bool operator!=(int x) {
		return !(this->operator==(x));
	}
	bool operator!=(const BigInt &x) {
		return !(this->operator==(x));
	}
	bool operator==(int x) {
		BigInt a(this->base, x);
		return ((*this) == a);
	}
	bool operator==(const BigInt &a) {
		int now_base = this->base;
		if (a.base - this->base) this->convert_to(a.base);
		int flag = 1;
		if (a.data.size() - this->data.size()) flag = 0;
		for (int i = 0; i < a.data.size() && flag; i++) {
			if (a.data[i] - this->data[i]) flag = 0;
		} 
		this->convert_to(now_base);
		return flag;
	}
	
private :
	vector<int> data;
	int base;
	void process_digit() {
		vector<int> &vec = this->data;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] < base) continue;
			if (i + 1 == vec.size()) vec.push_back(vec[i] / base);
			else vec[i + 1] += vec[i] / base;
			vec[i] %= base;
		}
		return ;
	}
	static int decode(char ch) {
		if (is_digit(ch)) return ch - '0';
		if (is_upper(ch)) return ch - 'A' + 10;
		return ch - 'a' + 36;
	}
	static char encode(int x) {
		if (x < 10) return x + '0';
		if (x < 36) return x - 10 + 'A';
		return x - 36 + 'a';
	}

friend ostream &operator<<(ostream &, const BigInt &);
};

ostream &operator<<(ostream &out, const BigInt &a) {
	for (int i = a.data.size() - 1; i >= 0; i--) {
		out << BigInt::encode(a.data[i]);
	} 
	return out;
}

int main() {
	int base_a, base_b;
	string str;
	cin >> base_a >> base_b >> str;
	BigInt num(base_a, str);
	cout << base_a << " " << num << endl;
	num.convert_to(base_b);
	cout << base_b << " " << num << endl;
	return 0;
} 
