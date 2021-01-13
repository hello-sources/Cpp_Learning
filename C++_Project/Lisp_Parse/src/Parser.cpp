#include "Parser.h"
shared_ptr<Expr> Parse(const char*& expression, ExprHandler* handler)
{
	const char* Read = expression;
	while (*Read == ' ')Read++;
	if (Is(Read, "("))
	{
		string token;
		vector<shared_ptr<Expr>> arguments;
		bool token_get = false;
		while (!Is(Read, ")"))
		{
			if (*Read != ' ' && !token_get&& !Is(Read, ")"))
			{
				token += *Read;
				Read++;
			}
			else
			{
				token_get = true;
				Read++;
				auto args = Parse(Read, handler);
				arguments.push_back(args);
			}
		}
		bool forInvoke = true;
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			forInvoke = false;
		}
		while (true)
		{
			if (handler->Test(token, forInvoke))
			{
				expression = Read;
				if (arguments.size()==0&&!forInvoke)
				{
					throw Exception{ Read, "Syntax Error" };
				}
				return handler->factory->CreateExpr(token, arguments);
			}
			else
			{
				handler = handler->next;
			}
			if (handler == nullptr)
			{
				throw Exception{ Read, "Syntax Error" };
			}
		}
	}
	else
	{
		string token;
		while (*Read != ' '&&*Read != '\0'&&*Read != ')')
		{
			token += *Read;
			Read++;
		}
		while (true)
		{
			if (handler->Test(token, false))
			{
				expression = Read;
				return handler->factory->CreateExpr(token, {});
			}
			else
			{
				handler = handler->next;
			}
			if (handler == nullptr)
			{
				throw Exception{ Read, "Syntax Error" };
			}
		}
	}
}
