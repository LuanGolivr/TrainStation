#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "Headers\TrainStation.h"

using namespace std;


TrainMap::TrainMap(){
    
    vertices.insert({"CityA",0});
    vertices.insert({"CityB",1});
    vertices.insert({"CityC",2});
    vertices.insert({"CityD",3});
    vertices.insert({"CityE",4});
    vertices.insert({"CityF",5});
    vertices.insert({"CityG",6});
    vertices.insert({"CityH",7});
    vertices.insert({"CityI",8});
    vertices.insert({"CityJ",9});
    vertices.insert({"CityK",10});
    vertices.insert({"CityL",11});
    vertices.insert({"CityM",12});
    vertices.insert({"CityN",13});

    cities.insert({0, "CityA"});
    cities.insert({1, "CityB"});
    cities.insert({2, "CityC"});
    cities.insert({3, "CityD"});
    cities.insert({4, "CityE"});
    cities.insert({5, "CityF"});
    cities.insert({6, "CityG"});
    cities.insert({7, "CityH"});
    cities.insert({8, "CityI"});
    cities.insert({9, "CityJ"});
    cities.insert({10, "CityK"});
    cities.insert({11, "CityL"});
    cities.insert({12, "CityM"});
    cities.insert({13, "CityN"});




    //Here we're just setting all the edges spaces and ticket's values as 0
    for(int i = 0; i < 14; i++){
        vector<int> v1;
        for ( int j = 0; j < 14; j ++){
            v1.push_back(0);
        }

        edges.push_back(v1);
    }

    for(int l = 0; l < 14; l++){
        vector<int> v2;
        for(int m = 0; m < 14; m++){
            v2.push_back(0);
        }

        edgesTicketsValues.push_back(v2);
    }

    

    // Here we're gonna set some standard distancies between the cities
    edges[vertices["CityA"]][vertices["CityL"]] = 75;
    edges[vertices["CityA"]][vertices["CityH"]] = 60;
    edges[vertices["CityA"]][vertices["CityB"]] = 100;
    edges[vertices["CityA"]][vertices["CityD"]] = 65;
    edges[vertices["CityA"]][vertices["CityC"]] = 80;

    edges[vertices["CityB"]][vertices["CityA"]] = 100;
    edges[vertices["CityB"]][vertices["CityG"]] = 180;
    edges[vertices["CityB"]][vertices["CityE"]] = 120;
    edges[vertices["CityB"]][vertices["CityF"]] = 120;

    edges[vertices["CityC"]][vertices["CityA"]] = 80;
    edges[vertices["CityC"]][vertices["CityD"]] = 32;

    edges[vertices["CityD"]][vertices["CityA"]] = 65;
    edges[vertices["CityD"]][vertices["CityC"]] = 32;
    edges[vertices["CityD"]][vertices["CityH"]] = 125;
    edges[vertices["CityD"]][vertices["CityF"]] = 170;
    edges[vertices["CityD"]][vertices["CityE"]] = 110;

    edges[vertices["CityE"]][vertices["CityI"]] = 80;
    edges[vertices["CityE"]][vertices["CityB"]] = 120;
    edges[vertices["CityE"]][vertices["CityD"]] = 110;

    edges[vertices["CityF"]][vertices["CityH"]] = 200;
    edges[vertices["CityF"]][vertices["CityB"]] = 120;
    edges[vertices["CityF"]][vertices["CityD"]] = 170;
    edges[vertices["CityF"]][vertices["CityI"]] = 60;
    edges[vertices["CityF"]][vertices["CityJ"]] = 130;

    edges[vertices["CityG"]][vertices["CityB"]] = 180;

    edges[vertices["CityH"]][vertices["CityA"]] = 60;
    edges[vertices["CityH"]][vertices["CityL"]] = 20;
    edges[vertices["CityH"]][vertices["CityD"]] = 125;
    edges[vertices["CityH"]][vertices["CityF"]] = 200;

    edges[vertices["CityI"]][vertices["CityK"]] = 70;
    edges[vertices["CityI"]][vertices["CityN"]] = 60;
    edges[vertices["CityI"]][vertices["CityF"]] = 60;
    edges[vertices["CityI"]][vertices["CityE"]] = 80;

    edges[vertices["CityJ"]][vertices["CityF"]] = 130;

    edges[vertices["CityK"]][vertices["CityI"]] = 70; 
    edges[vertices["CityK"]][vertices["CityM"]] = 50;

    edges[vertices["CityL"]][vertices["CityA"]] = 75;
    edges[vertices["CityL"]][vertices["CityH"]] = 20;

    edges[vertices["CityM"]][vertices["CityK"]] = 50;

    edges[vertices["CityN"]][vertices["CityI"]] = 60;


    //Here we're gonna set up the standard values of the tickets of each city to every single one.

    edgesTicketsValues[vertices["CityA"]][vertices["CityL"]] = 37;
    edgesTicketsValues[vertices["CityA"]][vertices["CityH"]] = 30;
    edgesTicketsValues[vertices["CityA"]][vertices["CityB"]] = 50;
    edgesTicketsValues[vertices["CityA"]][vertices["CityD"]] = 32;
    edgesTicketsValues[vertices["CityA"]][vertices["CityC"]] = 40;

    edgesTicketsValues[vertices["CityB"]][vertices["CityA"]] = 50;
    edgesTicketsValues[vertices["CityB"]][vertices["CityG"]] = 90;
    edgesTicketsValues[vertices["CityB"]][vertices["CityE"]] = 60;
    edgesTicketsValues[vertices["CityB"]][vertices["CityF"]] = 60;

    edgesTicketsValues[vertices["CityC"]][vertices["CityA"]] = 40;
    edgesTicketsValues[vertices["CityC"]][vertices["CityD"]] = 16;

    edgesTicketsValues[vertices["CityD"]][vertices["CityA"]] = 32;
    edgesTicketsValues[vertices["CityD"]][vertices["CityC"]] = 16;
    edgesTicketsValues[vertices["CityD"]][vertices["CityH"]] = 62;
    edgesTicketsValues[vertices["CityD"]][vertices["CityF"]] = 85;
    edgesTicketsValues[vertices["CityD"]][vertices["CityE"]] = 55;

    edgesTicketsValues[vertices["CityE"]][vertices["CityI"]] = 40;
    edgesTicketsValues[vertices["CityE"]][vertices["CityB"]] = 60;
    edgesTicketsValues[vertices["CityE"]][vertices["CityD"]] = 55;

    edgesTicketsValues[vertices["CityF"]][vertices["CityH"]] = 100;
    edgesTicketsValues[vertices["CityF"]][vertices["CityB"]] = 60;
    edgesTicketsValues[vertices["CityF"]][vertices["CityD"]] = 85;
    edgesTicketsValues[vertices["CityF"]][vertices["CityI"]] = 30;
    edgesTicketsValues[vertices["CityF"]][vertices["CityJ"]] = 65;

    edgesTicketsValues[vertices["CityG"]][vertices["CityB"]] = 90;

    edgesTicketsValues[vertices["CityH"]][vertices["CityA"]] = 30;
    edgesTicketsValues[vertices["CityH"]][vertices["CityL"]] = 10;
    edgesTicketsValues[vertices["CityH"]][vertices["CityD"]] = 62;
    edgesTicketsValues[vertices["CityH"]][vertices["CityF"]] = 100;

    edgesTicketsValues[vertices["CityI"]][vertices["CityK"]] = 35;
    edgesTicketsValues[vertices["CityI"]][vertices["CityN"]] = 30;
    edgesTicketsValues[vertices["CityI"]][vertices["CityF"]] = 30;
    edgesTicketsValues[vertices["CityI"]][vertices["CityE"]] = 40;

    edgesTicketsValues[vertices["CityJ"]][vertices["CityF"]] = 65;

    edgesTicketsValues[vertices["CityK"]][vertices["CityI"]] = 30; 
    edgesTicketsValues[vertices["CityK"]][vertices["CityM"]] = 25;

    edgesTicketsValues[vertices["CityL"]][vertices["CityA"]] = 32;
    edgesTicketsValues[vertices["CityL"]][vertices["CityH"]] = 10;

    edgesTicketsValues[vertices["CityM"]][vertices["CityK"]] = 25;

    edgesTicketsValues[vertices["CityN"]][vertices["CityI"]] = 30;

}
