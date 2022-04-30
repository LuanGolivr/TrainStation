#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "TrainStation.h"

#ifndef COSTUMER_H
#define COSTUMER_H

using namespace std;

class Costumer : public TrainMap {

public:
    void getCities();

    void getPossiblesRoutes( string );

    void getAllConnections();

    bool getCheaperRoute( string , string);

    bool getQuicklerRoute(string, string);
};

#endif
