#pragma once
#include "Expr.h"
#include "handler.h"
#include "utility.h"
#include <memory>
using std::shared_ptr;
struct Exception
{
	const char* Start;
	const char* Error;
};
shared_ptr<Expr> Parse(const char*& expression, ExprHandler* handler);