#include "../include/Expr.h"

void IdExpr::Accept(IVisitor* visitor)
{
	visitor->Visit(this);
}
void NumberExpr::Accept(IVisitor* visitor)
{
	visitor->Visit(this);
}
void BinaryExpr::Accept(IVisitor* visitor)
{
	visitor->Visit(this);
}
void InvokeExpr::Accept(IVisitor* visitor)
{
	visitor->Visit(this);
}
