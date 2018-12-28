#include "Command.h"
#include <list>
#include "BoolExpression.h"
#include <map>
#include "SymbolTable.h"
#include "CommandExpression.h"
#include "CommandMap.h"
#ifndef PROJECTNUM1_CONDITIONPARSER_H
#define PROJECTNUM1_CONDITIONPARSER_H


class ConditionParser : public Command {
    list<CommandExpression*> expressionCommandList;
    CommandMap* commandMap;
    BoolExpression* boolExpression;
    SymbolTable* symbolTable;
    list<Command*> toDelete;
    list<CommandExpression*> toDeleteCommExp;

public:

    ConditionParser(CommandMap* commandMap,SymbolTable* symbolMap);

    virtual int execute(vector<string>::iterator &vectorIt);
    void createCommand(vector<string>::iterator &vectorIt);

    virtual ~ConditionParser(){

        list<Command*>::iterator itr;
        for(itr = toDelete.begin(); itr != toDelete.end(); itr++){
            delete (*itr);
        }

        list<CommandExpression*>::iterator itCom;
        for(itCom = toDeleteCommExp.begin(); itCom != toDeleteCommExp.end(); itCom++){
            delete (*itCom);
        }
       // delete this->boolExpression;
    };
};


#endif //PROJECTNUM1_CONDITIONPARSER_H