#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class TrainMap {

public:
    TrainMap ();

    void addCity( string );

    void addCityConnections( string, vector<string>, vector<int> );

    void removeCity( string cityName );

    void changeDistance(string citySource, string cityTarget , int newDist);

    void changeValue(string citySource, string cityTarget, int newValue);


private:
    unordered_map<string, int> vertices;
    vector<vector<int>> edges;

};


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



    //Here we're just setting all the edges spaces as 0
    for(int i = 0; i < 14; i++){
        vector<int> v1;
        for ( int j = 0; j < 14; j ++){
            v1.push_back(0);
        }

        edges.push_back(v1);
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
}

void TrainMap::addCity( string cityName ){
    try
    {
        int postion = vertices.size();
        vertices.insert({cityName, postion});

        for(int i = 0; i < 1; i++){
            vector<int> v1;
            for ( int j = 0; j < 1; j ++){
                v1.push_back(0);
            }
            edges.push_back(v1);
        }
        cout << "Cidade inserida com sucesso" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}

void TrainMap::addCityConnections( string citySource, vector<string>cityTarget, vector<int>cityDist){

    for( int i = 0; i < cityTarget.size(); i++){
        edges[vertices[citySource]][vertices[cityTarget[i]]] = cityDist[i];
    }

    
}





