
#include "FlightValueMap.h"

void FlightValueMap::initalize() {
    this->mapOfFlightValue.insert(pair<string, double>( "/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    this->indexOfBind.insert(pair<int, string>(0, "/instrumentation/airspeed-indicator/indicated-speed-kt"));

    this->mapOfFlightValue.insert(pair<string, double>( "/instrumentation/altimeter/indicated-altitude-ft", 0));
    this->indexOfBind.insert(pair<int, string>(1, "/instrumentation/altimeter/indicated-altitude-ft"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/altimeter/pressure-alt-ft", 0));
    this->indexOfBind.insert(pair<int, string>(2, "/instrumentation/altimeter/pressure-alt-ft"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    this->indexOfBind.insert(pair<int, string>(3, "/instrumentation/attitude-indicator/indicated-pitch-deg"));

    this->mapOfFlightValue.insert(pair<string, double>( "/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    this->indexOfBind.insert(pair<int, string>(4, "/instrumentation/attitude-indicator/indicated-roll-deg"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    this->indexOfBind.insert(pair<int, string>(5, "/instrumentation/attitude-indicator/internal-pitch-deg"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/attitude-indicator/internal-roll-deg", 0));
    this->indexOfBind.insert(pair<int, string>(6, "/instrumentation/attitude-indicator/internal-roll-deg"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/encoder/indicated-altitude-ft", 0));
    this->indexOfBind.insert(pair<int, string>(7, "/instrumentation/encoder/indicated-altitude-ft"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/encoder/pressure-alt-ft", 0));
    this->indexOfBind.insert(pair<int, string>(8, "/instrumentation/encoder/pressure-alt-ft"));

    this->mapOfFlightValue.insert(pair<string, double>("instrumentation/gps/indicated-altitude-ft",0));
    this->indexOfBind.insert(pair<int, string>(9, "instrumentation/gps/indicated-altitude-ft"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/gps/indicated-ground-speed-kt", 0));
    this->indexOfBind.insert(pair<int, string>(10, "/instrumentation/gps/indicated-ground-speed-kt"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/gps/indicated-vertical-speed", 0));
    this->indexOfBind.insert(pair<int, string>(11, "/instrumentation/gps/indicated-vertical-speed"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/heading-indicator/indicated-heading-deg", 0));
    this->indexOfBind.insert(pair<int, string>(12, "/instrumentation/heading-indicator/indicated-heading-deg"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/magnetic-compass/indicated-heading-deg", 0));
    this->indexOfBind.insert(pair<int, string>(13, "/instrumentation/magnetic-compass/indicated-heading-deg"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    this->indexOfBind.insert(pair<int, string>(14, "/instrumentation/slip-skid-ball/indicated-slip-skid"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/turn-indicator/indicated-turn-rate", 0));
    this->indexOfBind.insert(pair<int, string>(15, "/instrumentation/turn-indicator/indicated-turn-rate"));

    this->mapOfFlightValue.insert(pair<string, double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",0));
    this->indexOfBind.insert(pair<int, string>(16, "/instrumentation/vertical-speed-indicator/indicated-speed-fpm"));

    this->mapOfFlightValue.insert(pair<string, double>("/controls/flight/aileron", 0));
    this->indexOfBind.insert(pair<int, string>(17, "/controls/flight/aileron"));

    this->mapOfFlightValue.insert(pair<string, double>("/controls/flight/elevator", 0));
    this->indexOfBind.insert(pair<int, string>(18, "/controls/flight/elevator"));

    this->mapOfFlightValue.insert(pair<string, double>("/controls/flight/rudder", 0));
    this->indexOfBind.insert(pair<int, string>(19, "/controls/flight/rudder"));

    this->mapOfFlightValue.insert(pair<string, double>("/controls/flight/flaps", 0));
    this->indexOfBind.insert(pair<int, string>(20, "/controls/flight/flaps"));

    this->mapOfFlightValue.insert(pair<string, double>("/controls/engines/current-engine/throttle", 0));
    this->indexOfBind.insert(pair<int, string>(21, "/controls/engines/current-engine/throttle"));

    this->mapOfFlightValue.insert(pair<string, double>("/engines/engine/rpm", 0));
    this->indexOfBind.insert(pair<int, string>(22, "/engines/engine/rpm"));
    this->save = "";
}

void FlightValueMap::updateMap(string values) {
    char* charLine = const_cast<char *>(values.c_str());
    char* splitValues = strtok(charLine, ",");
    for (int i = 0; i < 23; i++){
        if (this->indexOfBind.count(i)){
            string path = this->indexOfBind.find(i)->second;
            if (this->mapOfFlightValue.count(path)){
                this->mapOfFlightValue.find(path)->second = atof(splitValues);
            }
        }
        splitValues = strtok(NULL, ",");
    }
}


map<string,double> FlightValueMap::getFlightVauleMap(){
    return this->mapOfFlightValue;
}