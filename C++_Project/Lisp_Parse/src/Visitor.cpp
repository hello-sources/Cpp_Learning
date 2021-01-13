
#include "../include/Visitor.h"
#include <cstdlib>
#include <cstring>
void ExprPointer::Visit(NumberExpr* node)
{
    char str[100];
    sprintf(str, "%d", node->number);
	this->result = str;
    return ;
}
void ExprPointer::Visit(IdExpr* node)
{
	this->result = node->name;
    return ;
}
void ExprPointer::Visit(BinaryExpr* node)
{
	ExprPointer v1, v2;
    node->first->Accept(&v1);
    node->second->Accept(&v2);
    this->result = "(";
    switch (node->op) {
        case BinaryOperator::Plus: this->result += "+ "; break;
        case BinaryOperator::Minus: this->result += "- "; break;
        case BinaryOperator::Multiply: this->result += "* "; break;
        case BinaryOperator::Divide: this->result += "/ "; break;
    }
    this->result += v1.result + " " + v2.result;
    this->result += ')';
    return ;
}
void ExprPointer::Visit(InvokeExpr* node)
{
    this->result = "(";
    this->result += node->name;
    ExprPointer vis;
    for (auto x : node->arguments) {
        x->Accept(&vis);
        this->result += " ";
        this->result += vis.result;
    }
    this->result += ")";
    return ;
}
