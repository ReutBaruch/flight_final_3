#include "BoolExpression.h"

void BoolExpression::createBoolExpression(string conditionToCheck) {

    this->createExpression = new CreateExpression(this->symbols);

    string expression = "";
    this->action = "";
    int strLen = 0;

    int size = conditionToCheck.size();

    while ((conditionToCheck[strLen] != '<') && (conditionToCheck[strLen] != '!') &&
           (conditionToCheck[strLen] != '=') && (conditionToCheck[strLen] != '>')) {
        expression += conditionToCheck[strLen];
        strLen++;

        if(strLen == (size - 1)){
            throw ("ERROR - invalid condition");
        }
    }

    this->leftArgument = this->createExpression->convertToExpression(expression);
    while ((conditionToCheck[strLen] == '<') || (conditionToCheck[strLen] == '>') ||
           (conditionToCheck[strLen] == '=') || (conditionToCheck[strLen] == '!')) {
        action += conditionToCheck[strLen];
        strLen++;
    }
    expression = "";
    int conLen = conditionToCheck.length();
    while ((conditionToCheck[strLen] != '<') && (conditionToCheck[strLen] != '>') &&
           (conditionToCheck[strLen] != '=') && (conditionToCheck[strLen] != '!') &&
           (strLen < conLen)) {
        expression += conditionToCheck[strLen];
        strLen++;
    }
    this->rightArgument = this->createExpression->convertToExpression(expression);
}

bool BoolExpression::calculateBool(map<string, double> symbolMap) {
    if (this->action == "<") {
        return ((leftArgument->calculate(symbolMap)) <
                rightArgument->calculate(symbolMap));
    } else if (this->action == ">") {
        return ((leftArgument->calculate(symbolMap)) >
                rightArgument->calculate(symbolMap));
    } else if (this->action == "<=") {
        return ((leftArgument->calculate(symbolMap)) <=
                rightArgument->calculate(symbolMap));
    } else if (this->action == ">=") {
        return ((leftArgument->calculate(symbolMap)) >=
                rightArgument->calculate(symbolMap));
    } else if (this->action == "==") {
        return ((leftArgument->calculate(symbolMap)) ==
                rightArgument->calculate(symbolMap));
    } else if (this->action == "!=") {
        return ((leftArgument->calculate(symbolMap)) !=
                rightArgument->calculate(symbolMap));
    } else {
        throw "Invald argument";
    }
}
