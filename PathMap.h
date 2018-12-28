#ifndef PROJECT1_BINDMAP_H
#define PROJECT1_BINDMAP_H

#include <string>
#include<map>

using namespace std;

class PathMap {
    map<string,string> pathMap;
public:
    PathMap(){}
    void addToPathMap(string key, string value) {
        this->pathMap.insert(pair<string,string> (key,value));
    }

    map<string,string> getBindMap(){
        return this->pathMap;
    }
    ~PathMap(){};
};

#endif //PROJECT1_BINDMAP_H
