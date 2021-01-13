#pragma once

#include "Expr.h"

using std::unique_ptr;
using std::make_shared;
struct IExprFactory
{
	virtual shared_ptr<Expr> CreateExpr(string token, vector<shared_ptr<Expr>>arguments) = 0;
};
struct ExprHandler
{
	ExprHandler* next = nullptr;
	unique_ptr<IExprFactory> factory;
	virtual bool Test(string token, bool forInvoke) = 0;
};
struct IdHandler :ExprHandler
{
	struct IdFactory :IExprFactory
	{
		shared_ptr<Expr>CreateExpr(string token, vector<shared_ptr<Expr>>arguments);
	};
	bool Test(string token, bool forInvoke);

};
struct NumberHandler :ExprHandler
{
	struct NumberFactory :IExprFactory
	{
		shared_ptr<Expr>CreateExpr(string token, vector<shared_ptr<Expr>>arguments);
	};
	bool Test(string token, bool forInvoke);
};
struct BinaryHandler :ExprHandler
{
	struct BinaryFactory :IExprFactory
	{
		shared_ptr<Expr>CreateExpr(string token, vector<shared_ptr<Expr>>arguments);
	};
	bool Test(string token, bool forInvoke);
};
struct InvokeHandler :ExprHandler
{
	struct InvokeFactory :IExprFactory
	{
		shared_ptr<Expr>CreateExpr(string token, vector<shared_ptr<Expr>>arguments);
	};
	bool Test(string token, bool forInvoke);
};
