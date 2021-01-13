CC = g++
CXX = g++
CPPFLAGS = -I../include -std=c++14 -Wextra -g
LDFLAGS = -std=c++14

EXENAME = main
.PHONY : clean TAGS all
all : $(EXENAME)
	mv $(EXENAME) ../
main : Parser.o utility.o Visitor.o Expr.o handler.o

main.o : main.cpp

Parser.o : Parser.cpp ../include/Parser.h

utility.o : utility.cpp ../include/utility.h

Visitor.o : Visitor.cpp ../include/Visitor.h

Expr.o : Expr.cpp ../include/Expr.h

clean :
	-rm -rf *.o *.dSYM
TAGS : clean all
