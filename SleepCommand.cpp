#include <unistd.h>
#include <iostream>
#include "SleepCommand.h"



int SleepCommand::execute(vector<string>::iterator &vectorIt){
    int num = atoi((*vectorIt).c_str());
    sleep(num);
    vectorIt += 2;
    return 0;
}
