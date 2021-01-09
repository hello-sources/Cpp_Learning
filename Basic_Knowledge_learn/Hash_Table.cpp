/*************************************************************************
	> File Name: Hash_Table.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 10:47:52 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

class Node {
public :
	Node() : flag(false), str(nullptr) {}
	void clear() {
		this->flag = false;
		if (this->str) free(this->str);
		this->str = nullptr;
		return ;
	}
	void insert(const char *str) {
		this->clear();
		this->flag = true;
		this->str = strdup(str);
		return ;
	}
	bool empty() { return this->flag == false; }
	bool operator!=(const char *str) {
		if (this->str == nullptr) return true;
		return strcmp(this->str, str) != 0;
	}
	bool operator==(const char *str) {
		return !((*this) != str);
	}
	~Node() {
		if (this->str) free(this->str);
		this->str = nullptr;
	}
private : 
	bool flag;
	char *str;
};

class HashFunc {
public :
	virtual int operator()(const char *str) const = 0;
	
};

class HashTable {
public :
	HashTable(const HashFunc &func);
	bool insert(const char *str);
	bool find(const char *str);
	~HashTable();
private :
	Node &find_position(const char *str);
	int _size;
	Node *data;
	const HashFunc *p_func;	
};

//哈希函数，如果想声明其他类型的哈希函数，再增加HashFunc派生类 
class BKDRHash : public HashFunc {
public :
	int operator()(const char *str) const {
		int seed = 31;
		int hash_value = 0;
		for (int i = 0; str[i]; i++) {
			hash_value = hash_value * seed + str[i];
		}
		return hash_value & 0x7fffffff;
	}
};

int main() {
	BKDRHash bkdr_func;
	HashTable h1(bkdr_func);
	int op;
	char str[100];
	while (cin >> op >> str) {
		switch (op) {
			case 0 : {
				cout << "insert " << str << " to hash table = ";
				cout << h1.insert(str) << endl;
				break;
			}
			case 1 : {
				cout << "search " << str << " from hash table = ";
				cout << h1.find(str) << endl;
				break;
			}
		}
	}
	return 0;
} 

HashTable::HashTable(const HashFunc &func) : p_func(&func) {
	this->_size = 100;
	this->data = new Node[this->_size];
}

bool HashTable::insert(const char *str) {
	Node &d = find_position(str);
	if (!d.empty()) return false;
	d.insert(str);
	return true;
}

bool HashTable::find(const char *str) {
	Node &d = find_position(str);
	return !d.empty();
}

Node &HashTable::find_position(const char *str) {
	int ind = (*p_func)(str) % this->_size;
	int times = 1;
	while (!data[ind].empty() && data[ind] != str) {
		ind += times * times;
		ind %= this->_size;
	}
	return data[ind];
}

HashTable::~HashTable() {
	delete[] this->data;
}
