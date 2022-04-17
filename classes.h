#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class TrainMap {

public:
    TrainMap () {

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



        //Here we're just setting all the edges spaces as 0
        for(int i = 0; i < 14; i++){
            for ( int j = 0; j < 14; j ++){
                edges[i][j] = 0;
            }
        }

        // Here we're gonna set some standard distancies between the cities
        edges[vertices["CityA"]][vertices["CityL"]] = 75;


    };

    unordered_map<string, int> vertices;
    int edges[14][14];

    void addCity( string cityName ) {

    }

    void addCityConnections( string cityName );

    void removeCity( string cityName );

    void changeDistance(string citySource, string cityTarget );

    void changeValue(string citySource, string cityTarget );





};



