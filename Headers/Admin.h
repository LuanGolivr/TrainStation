#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "TrainStation.h"

#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin : public TrainMap {

public:

    Admin();

    bool addCity( string );

    bool removeCity( string );

    bool addCityConnections( string, vector<string>&, vector<int>&, vector<int>& );

    bool removeCityConnections( string, vector<string>& );

    bool changeDistance(string, vector<string>&, vector<int>& );

    bool changeValue(string , vector<string>&, vector<int>& );

protected:

    unordered_map<string, string> adminUsers;
};

#endif
