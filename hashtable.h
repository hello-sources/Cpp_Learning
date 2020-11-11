/*************************************************************************
	> File Name: hashtable.h
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 11 Nov 2020 11:05:35 PM CST
 ************************************************************************/

#ifndef _27_HASHTABLE_H
#define _27_HASHTABLE_H

typedef int (*HashFuncRaw)(const void *value);

class HashFunc {
public :
    virtual int operator()(const void *value) = 0;
    virtual ~HashFunc() {}
};

class HashTable {
public :
    HashTable(HashFunc &hc) : __hc(&hc), __hcr(nullptr) {}
    HashTable(HashFuncRaw hc) : __hcr(hc), __hc(nullptr) {}
    int get_hash(const void *data) {
        if (this->__hc) {
            return (*(this->__hc))(data);
        } else {
            return this->__hcr(data);
        }
    }
private :
    HashFunc *__hc;
    HashFuncRaw __hcr;
};

#endif
