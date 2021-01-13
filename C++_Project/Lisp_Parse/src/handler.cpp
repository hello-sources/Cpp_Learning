#include "handler.h"
#include <cstdlib>
#include <functional>

auto is = [](int b) {
    return [=](int x) -> bool{
        return x == b;
    };
};
auto in_range = [](int b, int e = -1) {
    if (e == -1) e = b;
    return [=](int x) -> bool {
        return x >= b && x <= e;
    };
};
auto OR = [](std::function<bool(int)> u, std::function<bool(int)> v) {
    return [=](int x) -> bool {
        return u(x) || v(x);
    };
};

auto is_little = in_range('a', 'z');
auto is_upper = in_range('A', 'Z');
auto is_digit = in_range('0', '9');
auto is_alpha = OR(is_little, is_upper);
auto is_id_c = OR(is_alpha, is_digit);
auto is_binary = OR(is('+'), OR(is('-'), OR(is('*'), is('/'))));

bool IdHandler::Test(string token, bool forInvoke) {
	if (!is_alpha(token[0])) return false;
    if (forInvoke) return false;
    for (int i = 0; i < token.size(); i++) {
        if (is_id_c(token[i])) continue;
        return false;
    }
    return true;
}
shared_ptr<Expr> IdHandler::IdFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	IdExpr *node = new IdExpr();
    node->name = token;
    return shared_ptr<Expr>(node);
}

shared_ptr<Expr> NumberHandler::NumberFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	NumberExpr *node = new NumberExpr();
    int val = 0;
    for (int i = 0; i < token.size(); i++) {
        val = val * 10 + token[i] - '0';
    }
    node->number = val;
    return shared_ptr<Expr>(node);
}
bool NumberHandler::Test(string token, bool forInvoke)
{
    if (forInvoke) return false;
    for (int i = 0; i < token.size(); i++) {
        if (!is_digit(token[i])) return false;
    }
    return true;
}

bool BinaryHandler::Test(string token, bool forInvoke)
{
	if (token.size() != 1) return false;
    if (forInvoke) return false;
    return is_binary(token[0]);
}
shared_ptr<Expr>BinaryHandler::BinaryFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
    BinaryExpr *node = new BinaryExpr();
    switch (token[0]) {
        case '+': node->op = BinaryOperator::Plus; break;
        case '-': node->op = BinaryOperator::Minus; break;
        case '*': node->op = BinaryOperator::Multiply; break;
        case '/': node->op = BinaryOperator::Divide; break;
    }
    node->first = arguments[0];
    node->second = arguments[1];
    arguments.erase(arguments.begin());
    if (arguments.size() == 1) return shared_ptr<Expr>(node);
    arguments[0] = shared_ptr<Expr>(node);
    return CreateExpr(token, arguments);
}

shared_ptr<Expr> InvokeHandler::InvokeFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	InvokeExpr *node = new InvokeExpr();
    node->name = token;
    for (int i = 0; i < arguments.size(); i++) {
        node->arguments.push_back(arguments[i]);
    }
    return shared_ptr<Expr>(node);
}
bool InvokeHandler::Test(string token, bool forInvoke)
{
	if (!forInvoke) return false;
	if (!is_alpha(token[0])) return false;
    for (int i = 0; i < token.size(); i++) {
        if (is_id_c(token[i])) continue;
        return false;
    }
    return true;
}

