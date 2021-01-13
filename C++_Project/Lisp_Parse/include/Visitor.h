#pragma once
#include "Expr.h"
#include <string>
#include "utility.h"
using std::string;
using std::to_string;

struct ExprPointer :Expr::IVisitor
{
	string result="";
	void Visit(NumberExpr* node);
	void Visit(IdExpr* node);
	void Visit(BinaryExpr* node);
	void Visit(InvokeExpr* node);;
};
