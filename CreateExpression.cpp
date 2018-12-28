#include "CreateExpression.h"

// shunting yard
Expression *CreateExpression::convertToExpression(string string1) {

    string operatorString = "";
    stack<string> operators;
    stack<Expression *> expressions;

    int stringLength = 0;
    int resultLength = 0;
    int str1Len = string1.length();

    while (stringLength < str1Len) {
        if (string1[stringLength] == '(') {
            operators.push("(");
        } else if (string1[stringLength] == ')') {
            string temp;
            operatorString += ",";
            while (operators.top() != "(") {
                temp = operators.top();
                operatorString += temp;
                operators.pop();
            }
            operators.pop();
        } else if (string1[stringLength] != '+' && string1[stringLength] != '-' &&
                   string1[stringLength] != '*' && string1[stringLength] != '/') {

            operatorString += string1[stringLength];
        } else {
            string operatorPush = "";
            if ((stringLength == 0) && (string1[stringLength] == '-')) {
                operatorPush = "^";
            } else {
                char previousChar = string1[stringLength - 1];
                char currentChar = string1[stringLength];
                if ((currentChar == '-') &&
                    ((previousChar == '*') || (previousChar == '+') ||
                     (previousChar == '/') || (previousChar == '-'))) {
                    operatorPush = "^";
                } else {
                    operatorPush = string(1, string1[stringLength]);
                    operatorString +=",";

                }
            }
            operators.push(operatorPush);
        }
        stringLength++;
    }

    while (!operators.empty()) {
        operatorString += operators.top();
        operators.pop();
    }
    int operLen = operatorString.length();
    while (resultLength < operLen) {
        Expression* newExpression;
        Expression* rightExpression;
        Expression* leftExpression;
        if (operatorString[resultLength] != ' ') {
            if (operatorString[resultLength] == '+') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Plus(leftExpression, rightExpression);
                this->toDelete.push_back(newExpression);
            } else if (operatorString[resultLength] == '*') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Mul(leftExpression, rightExpression);
                this->toDelete.push_back(newExpression);
            } else if (operatorString[resultLength] == '/') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Div(leftExpression, rightExpression);
                this->toDelete.push_back(newExpression);
            } else if (operatorString[resultLength] == '-') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                newExpression = new Minus(leftExpression, rightExpression);
                this->toDelete.push_back(newExpression);
                resultLength++;
            } else if (operatorString[resultLength] == '^') {
                newExpression = new Neg(expressions.top());
                this->toDelete.push_back(newExpression);
                expressions.pop();
                resultLength++;
            } else if (isdigit(operatorString[resultLength])) {
                string num = "";
                while (((operatorString[resultLength]) != ',') && (isdigit(operatorString[resultLength]))) {
                    string s = string(1, operatorString[resultLength]);
                    num = num + s;
                    resultLength++;
                }
                double d = atof(num.c_str());
                newExpression = new Num(d);
                this->toDelete.push_back(newExpression);
            } else if (operatorString[resultLength] != ' ') {
                string tempVar = "";
                while (((operatorString[resultLength] != ',') || (isdigit(operatorString[resultLength])) ||
                       (isalpha(operatorString[resultLength]))) && (resultLength < operLen)){
                    string s = string(1, operatorString[resultLength]);
                    tempVar = tempVar + s;
                    resultLength++;
                }
                newExpression = new Var(tempVar, this->symbols);
                this->toDelete.push_back(newExpression);
            }
            expressions.push(newExpression);
            if(operatorString[resultLength] == ',') {
                resultLength++;
            }
        } else {
            resultLength++;
        }
    }
    return expressions.top();
}