/*************************************************************************
	> File Name: ASL_visitor.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 11 Nov 2020 11:16:53 PM CST
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

class NumberNode;
class OperatorNode;

class BaseNode {
public :
    class IVisitor {
    public:
        virtual void visit(NumberNode *) = 0;
        virtual void visit(OperatorNode *) = 0;
    };
    using pNode = BaseNode *;
    BaseNode(pNode lchild = nullptr, pNode rchild = nullptr) : 
        _lchild(lchild), _rchild(rchild) {}
    pNode lchild() { return this->_lchild; }
    pNode rchild() { return this->_rchild; }
    virtual void Accept(IVisitor *) = 0;

private:
    BaseNode *_lchild, *_rchild;
};

class NumberNode : public BaseNode {
public :
    NumberNode(int val) : _val(val) {
        cout << "Created Number Node : " << val << endl; 
    }
    int getVal() { return this->_val; }
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }

private:
    int _val;
};

enum class OperatorType {
    PLUS,
    SUB,
    MULTIPLY,
    DIVISION,
    POW
};

class OperatorNode : public BaseNode {
public :
    using pNode = BaseNode *;
    OperatorNode(pNode lchild, pNode rchild, char ch) : BaseNode(lchild, rchild) {
        switch (ch) {
            case '+': this->_type = OperatorType::PLUS; break;
            case '-': this->_type = OperatorType::SUB; break;
            case '*': this->_type = OperatorType::MULTIPLY; break;
            case '/': this->_type = OperatorType::DIVISION; break;
            case '^': this->_type = OperatorType::POW; break;
        }
        cout << "Created Operator Node : " << ch << endl;
    }
    OperatorType getType() { return this->_type; }
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }

private:
    OperatorType _type;
};

class CalcVisitor : public BaseNode::IVisitor {
public:
    virtual void visit(NumberNode *obj) {
        this->result = obj->getVal();
        return ;
    }
    virtual void visit(OperatorNode *obj) {
        CalcVisitor vis1, vis2;
        obj->lchild()->Accept(&vis1);
        obj->rchild()->Accept(&vis2);
        switch (obj->getType()) {
            case OperatorType::PLUS: 
                this->result = vis1.result + vis2.result; break;
            case OperatorType::SUB: 
                this->result = vis1.result - vis2.result; break;
            case OperatorType::MULTIPLY: 
                this->result = vis1.result * vis2.result; break;
            case OperatorType::DIVISION: 
                this->result = vis1.result / vis2.result; break;
            case OperatorType::POW: 
                this->result = (int)pow(vis1.result, vis2.result); break;
        }
        return ;
    }
    int result;
};

BaseNode *_build(const string &str, int l, int r) {
    #define INF 0x3f3f3f3f
    int pos = -1, pri = INF - 1, temp = 0;
    for (int i = l; i <= r; i++) {
        int cur_pri = INF;
        switch (str[i]) {
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
            case '+':
            case '-': cur_pri = temp + 1; break;
            case '*':
            case '/': cur_pri = temp + 2; break;
            case '^': cur_pri = temp + 3; break;
        }
        if (cur_pri <= pri) {
            pos = i;
            pri = cur_pri;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return new NumberNode(num);
    }
    BaseNode *lchild = _build(str, l, pos - 1);
    BaseNode *rchild = _build(str, pos + 1, r);
    return new OperatorNode(lchild, rchild, str[pos]);
    #undef INF
}

BaseNode *build(const string &str) {
    return _build(str, 0, str.length() - 1);
}

int main() {
    BaseNode *root = build("(1 + 2) * ( 3 + 4 )");
    CalcVisitor vis;
    root->Accept(&vis);
    cout << vis.result << endl;
    return 0;
}
