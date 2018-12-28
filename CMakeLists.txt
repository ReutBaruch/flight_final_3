cmake_minimum_required(VERSION 3.13)
project(project1)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")

add_executable(project1 main.cpp BineryExpression.h Command.h ConnectCommand.cpp ConnectCommand.h
        CreateExpression.cpp CreateExpression.h Div.cpp Div.h Expression.h Minus.cpp Minus.h
        Mul.cpp Mul.h Num.cpp Num.h OpenServerCommand.h Plus.cpp Plus.h lexer.cpp lexer.h VarCommand.cpp VarCommand.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h LoopCommand.cpp LoopCommand.h OpenServerCommand.cpp SymbolTable.h CommandExpression.cpp CommandExpression.h SymbolTable.cpp PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h CheckConnection.h PathMap.h FlightValueMap.cpp FlightValueMap.h StringFlightControls.h SetControlCommand.cpp SetControlCommand.h parser.cpp parser.h BoolExpression.cpp BoolExpression.h Neg.cpp Neg.h Var.cpp Var.h CommandMap.h CommandMap.cpp ExitServer.h)