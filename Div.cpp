#include "Div.h"

double Div::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;

    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);

    if(rightValue != 0) {
        return leftValue / rightValue;
    }
    throw "unable to div by 0!";
}

double Div::calculate() {
    map<string, double> assignment;
    return calculate(assignment);
}