#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TrainMap {

public:
    TrainMap ();

    bool addCity( string );

    bool addCityConnections( string, vector<string>, vector<int> );

    bool removeCity( string );

    bool changeDistance(string, vector<string>, vector<int> );

    bool changeValue(string , vector<string>, vector<int> );

    void getCities();



private:
    unordered_map<string, int> vertices;
    unordered_map<int, string> cities;
    vector<vector<int>> edges;
    vector<vector<int>> edgesTicketsValues;

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

bool TrainMap::addCity( string cityName ){
    if(vertices.count(cityName) > 0){
        cout << "The city already exist" << endl;
        return false;
    }
    
    try
    {   
        int position = vertices.size();
        vertices.insert({cityName, position});
        cities.insert({position, cityName});

        for(int i = 0; i < 1; i++){
            vector<int> v1;
            for ( int j = 0; j < 1; j ++){
                v1.push_back(0);
            }
            edges.push_back(v1);
        }
        cout << "The city was inserted successfully " << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    
    return true;

}

bool TrainMap::addCityConnections( string citySource, vector<string>cityTarget, vector<int>cityDist){
    if (vertices.count(citySource) && cityTarget.size() && cityDist.size() && cityTarget.size() == cityDist.size()){

        for( int i = 0; i < cityTarget.size(); i++){
            edges[vertices[citySource]][vertices[cityTarget[i]]] = cityDist[i];
            edges[vertices[cityTarget[i]]][vertices[citySource]] = cityDist[i];
        }

        cout << "All the changes were made it" << endl;
        return true;
    }

    cout << "The source's city does not exist in our sistem" << endl;
    return false;

}

bool TrainMap::removeCity( string cityName ){
    if( vertices.count(cityName)){

        int position = vertices[cityName];

        if(position < vertices.size() - 1 ){

            for(int k = vertices.size()-1; k > position; k--){
                vertices[cities[ k ]] = vertices[cities[k - 1]];
            }

            for(int i = position; i < cities.size() - 1; i++){
                cities[i] = cities[i + 1];
            }
        }
        
        vertices.extract(cityName);
        cities.extract(position);

        for(int i = position; i < edges.size(); i++){
            for(int j = 0; j < edges.size() -1; j++){
                edges[i][j] = edges[i + 1][j];
            }
        }

        int graphSize = edges.size();
        edges.resize(graphSize - 1);

        cout << "The city " << cityName << " was remove of the TrainStation Map" << endl;
        return true;
    }

    cout << "The city " << cityName << " does not exist in our the system" << endl;
    return false;

}

bool TrainMap::changeDistance( string citySource, vector<string> cityTarget, vector<int> newDist ){
    if ( vertices.count(citySource) && cityTarget.size() && newDist.size() && cityTarget.size() == newDist.size()){
        for(int i = 0; i < cityTarget.size(); i++){
            try
            {
                edges[vertices[citySource]][vertices[cityTarget[i]]] = newDist[i];
                edges[vertices[cityTarget[i]]][vertices[citySource]] = newDist[i];
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

                
        }

        cout << "All the changes were made it !!" << endl;
        return true;
    }

    return false;
}

bool TrainMap::changeValue( string citySource, vector<string>citytargets, vector<int>newValues){

    if( vertices.count(citySource) && citytargets.size() && newValues.size() && citytargets.size() == newValues.size()){
        for(int i = 0; i < citytargets.size(); i++){
            try
            {
                edgesTicketsValues[vertices[citySource]][vertices[citytargets[i]]] = newValues[i];
                edgesTicketsValues[vertices[citytargets[i]]][vertices[citySource]] = newValues[i];
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }  
        }

        cout << "All the changes were made it !!" << endl;
        return true;
    }

    cout << "It was not possible make the changes" << endl;
    return false;
}




void TrainMap::getCities(){

    cout << "The list of cities: " << endl;
    for(int i = 0; i < edges.size(); i++){
        cout <<"- " << cities[i] << endl;
    }
}
