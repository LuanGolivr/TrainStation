#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#ifndef TRAINSTATION_H
#define TRAINSTATION_H

using namespace std;

class TrainMap {

public:
    TrainMap ();

protected:
    unordered_map<string, int> vertices;
    unordered_map<int, string> cities;
    vector<vector<int>> edges;
    vector<vector<int>> edgesTicketsValues;

};

#endif


