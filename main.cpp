#include <iostream>
#include <vector>
#include "classes.h"

using namespace std;

int main (){
    TrainMap graph;
    //testing the features
    
    vector<string> target = {"CityL"};
    vector<int> dist = {40};
    graph.changeDistance("CityA", target, dist);

    dist[0] = 12;
    graph.changeValue("CityA", target, dist);
    
    return 0;
};