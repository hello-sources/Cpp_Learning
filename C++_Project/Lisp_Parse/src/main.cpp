
#include "../include/handler.h"
#include "../include/utility.h"
#include "../include/Visitor.h"
#include "../include/Expr.h"
#include "../include/Parser.h"
#include <string>
#include <cstdlib>
#include <memory>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;


//定义四个责任链节点对象
NumberHandler numhdl;
IdHandler idhdl;
BinaryHandler binhdl;
InvokeHandler invokehdl;
void init()
{
    //相关工厂挂到相关工厂中去，相关工厂生产相关产品
	numhdl.next = &idhdl;
	numhdl.factory = make_unique<NumberHandler::NumberFactory>();
	idhdl.next = &binhdl;
	idhdl.factory = make_unique<IdHandler::IdFactory>();
	binhdl.next = &invokehdl;
	binhdl.factory = make_unique<BinaryHandler::BinaryFactory>();
	invokehdl.next = nullptr;
	invokehdl.factory = make_unique<InvokeHandler::InvokeFactory>();
}
int total_num = 0;
void Assert(const char* test, string check)
{ //assert是系统提供的断言，Assert调用assert
	ExprPointer visitor;
	try
	{	
		auto node = Parse(test, &numhdl);
		node->Accept(&visitor);	
	}
	catch (Exception)
	{
		visitor.result = "angry";
	}
	assert(visitor.result == check);
	cout << "Test " << ++total_num << " Passed!" << endl;
	
}
int main() {
	init();
	Assert("1", "1");
	Assert("301", "301");
	Assert("elder", "elder");
	Assert("Inf1926", "Inf1926");
	Assert("(+ 1 s)", "(+ 1 s)");
	Assert("(extend 1 s)", "(extend 1 s)");
 	Assert("(extend (+ 0 1) s)", "(extend (+ 0 1) s)");
	Assert("(excited (* 8 17 1926))", "(excited (* (* 8 17) 1926))");
	Assert("(the man who changed China)", "(the man who changed China)");
	Assert("(naive)", "(naive)");
	Assert("301yangzhou", "angry");
	Assert("(+)", "angry");
	Assert("O-O", "angry");
	Assert("(% 1 2)", "angry");
 	Assert("(0 1 2)", "angry");
	Assert("(301yangzhou)", "angry");
	Assert("(301yangzhou excited)", "angry");
	Assert("(O-O excited)", "angry");
	Assert("(O-O 1)", "angry");
	Assert("(Inf1926 %)", "angry");

	return 0;
}
