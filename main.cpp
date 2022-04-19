#include <iostream>
#include <vector>
#include "classes.h"

using namespace std;

int main (){
    TrainMap graph;
    //testing the features
    graph.addCity("CityO");
    graph.addCity("CityO");


    vector<string> neighboor = {"CityO"};
    vector<int> neighboorDist = {40};
    graph.addCityConnections("CityI", neighboor, neighboorDist);
    
    return 0;
};