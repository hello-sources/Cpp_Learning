/*************************************************************************
	> File Name: hash_table模板.h
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 11 Nov 2020 11:12:04 PM CST
 ************************************************************************/

#ifndef _9_HASH_TABLE_H
#define _9_HASH_TABLE_H

namespace haizei {
    template<typename T, typename U>
    struct pair {
        pair() : first(), second() {}
        pair(const T &a) : first(a), second() {}
        pair(const T &a, const U &b) : first(a), second(b) {}
        T first;
        U second;
    };
    template<typename K> struct hash;
    template<>
    struct hash<int> {
        size_t operator()(int x) {
            return x;
        }
    };
    
    template<>
    struct hash<double> {
        size_t operator()(double x) {
            return *((size_t *)(&x));
        }
    };

    template<typename K, typename T, typename HashT = haizei::hash<K>>
    class unordered_map {
    public:
        unordered_map(size_t size = 100) : size(size) {
            this->data = new pair<K, T> *[size];
            this->map = new bool[size];
            for (int i = 0; i < size; i++) {
                this->data[i] = nullptr;
                this->map[i] = false;
            }
        }
        T &operator[](const K &a) {
            size_t ind;
            T *value = this->find(a, ind);
            if (ind == -1) return *this->end();
            if (value == this->end()) {
                this->data[ind] = new pair<K, T>(a);
                this->map[ind] = true;
            }
            return this->data[ind]->second;
        }
        T *end() { return (T *)(0); }
        T *find(const K &a, size_t &ind) {
            ind = hash_func(a);
            ind %= this->size;
            size_t times = 1;
            while (this->map[ind] && !(this->data[ind]->first == a)) {
                ind += times * times;
                ind %= this->size;
                times += 1;
                if (times == this->size) {
                    ind = -1;
                    return this->end();
                }
            }
            if (this->map[ind]) return &(this->data[ind]->second);
            return this->end();
        }
    private:
        size_t size;
        pair<K, T> **data;
        bool *map;
        HashT hash_func;
    };
}

#endif
