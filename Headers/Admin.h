#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "TrainStation.h"

using namespace std;

class Admin : public TrainMap {

public:

    Admin();

    bool verification( string*, string*);

    bool addCity( string );

    bool removeCity( string );

    bool addCityConnections( string, vector<string>&, vector<int>&, vector<int>& );

    bool removeCityConnections( string, vector<string>& );

    bool changeDistance(string, vector<string>&, vector<int>& );

    bool changeValue(string , vector<string>&, vector<int>& );

protected:

    unordered_map<string, string> adminUsers;
};

Admin::Admin(){

    //Here we're just setting some Standards users
    adminUsers.insert({"User1", "AdminUserPassword1"});
    adminUsers.insert({"User2", "AdminUserPassword2"});
    adminUsers.insert({"User3", "AdminUserPassword3"});
    adminUsers.insert({"User4", "AdminUserPassword4"});
};

bool Admin::verification( string* username, string* password){
    
    if(adminUsers.count(*username)){
        cout << "Successull login !!!" << endl;
        return true;
    }else{
        cout << "Invalid user or password" << endl;
        return false;
    }

}

bool Admin::addCity( string cityName ){
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

bool Admin::removeCity( string cityName ){
    if( vertices.count(cityName)){

        int position = vertices[cityName];

        if(position < vertices.size() - 1 ){

            for(int k = vertices.size()-1; k > position; k--){
                vertices[cities[ k ]] = vertices[cities[k - 1]];
            }

            for(int i = position; i < cities.size()-1; i++){
                cities[i] = cities[i + 1];
            }
        }
        
        vertices.erase(cityName);
        int newPosition = cities.size() - 1;
        cities.erase(newPosition);

        
        for(int i = position; i < edges.size()-1; i++){
            for(int j = 0; j < edges.size(); j++){
                edges[i][j] = edges[i + 1][j];
            }
        }

        for(int i = position; i < edgesTicketsValues.size()-1; i++){
            for(int j = 0; j < edgesTicketsValues.size(); j++){
                edgesTicketsValues[i][j] = edges[i + 1][j];
            }
        }

        int graphSize = edges.size();
        int ticketsGraphSize = edgesTicketsValues.size();
        edges.resize(graphSize - 1);
        edgesTicketsValues.resize(ticketsGraphSize - 1);

        cout << "The city " << cityName << " was remove of the TrainStation Map" << endl;
        return true;
    }

    cout << "The city " << cityName << " does not exist in our the system" << endl;
    return false;

}

bool Admin::addCityConnections( string citySource, vector<string>& cityTarget, vector<int>& cityDist, vector<int>& ticketValue){
    if (vertices.count(citySource) && cityTarget.size() && cityDist.size() && cityTarget.size() == cityDist.size()){

        for( int i = 0; i < cityTarget.size(); i++){

            if(vertices.count(cityTarget[i]) && citySource != cityTarget[i] && edges[vertices[citySource]][vertices[cityTarget[i]]] == 0){

                edges[vertices[citySource]][vertices[cityTarget[i]]] = cityDist[i];
                edges[vertices[cityTarget[i]]][vertices[citySource]] = cityDist[i];

                edgesTicketsValues[vertices[citySource]][vertices[cityTarget[i]]] = ticketValue[i];
                edgesTicketsValues[vertices[cityTarget[i]]][vertices[citySource]] = ticketValue[i];

                cout << "A new connection between " << citySource << " and " << cityTarget[i] << " was created !!" << endl;
                cout << "\n";
            }
            else {
                cout << cityTarget[i] << " does not exist in our system or it was not possible make that change !!" << endl;
                cout << "\n";
            }
            
        }

        
        return true;
    }

    cout << citySource << " does not exist in our system !!!"<< endl;
    cout << "\n";
    return false;

}

bool Admin::removeCityConnections(string citySource, vector<string>& cityTarget){
    
    if(vertices.count(citySource)){
        try
        {
            for(int i = 0; i < cityTarget.size(); i++){

                if(vertices.count(cityTarget[i]) && citySource != cityTarget[i]){

                    edges[vertices[citySource]][vertices[cityTarget[i]]] = 0;
                    edges[vertices[cityTarget[i]]][vertices[citySource]] = 0;

                    edgesTicketsValues[vertices[citySource]][vertices[cityTarget[i]]] = 0;
                    edgesTicketsValues[vertices[cityTarget[i]]][vertices[citySource]] = 0;

                    cout << "The connections between " << citySource << " and " << cityTarget[i] << " was removed !!" << endl;
                    cout << "\n";
                }
                else {
                    cout << cityTarget[i] << " does not exist in our system or it wasn't possible make that change !!!" << endl;
                    cout << "\n";
                } 
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
        
        return true;
    }

    cout << "\n";
    cout << "The city " << citySource << " does not exist in our system !!" << endl;
    cout << "\n";
    return false;
}

bool Admin::changeDistance( string citySource, vector<string>& cityTarget, vector<int>& newDist ){
    if ( vertices.count(citySource) && cityTarget.size() && newDist.size() && cityTarget.size() == newDist.size()){
        for(int i = 0; i < cityTarget.size(); i++){
            try
            {
                if(vertices.count(cityTarget[i]) && citySource != cityTarget[i]){

                    cout << "\n";
                    cout << "The previous distance between  " << citySource << " and " << cityTarget[i] << " is: " << edges[vertices[citySource]][vertices[cityTarget[i]]] << "km"<< endl;
                    edges[vertices[citySource]][vertices[cityTarget[i]]] = newDist[i];
                    edges[vertices[cityTarget[i]]][vertices[citySource]] = newDist[i];
                    cout << "Now the distance is : " << edges[vertices[citySource]][vertices[cityTarget[i]]] << "km" << endl;
                    cout << "\n";
                }
                else {

                    cout << "\n";
                    cout << cityTarget[i] << " does not exist em our system or it was not possible make the change !!!" << endl;
                    cout << "\n";
                }
                
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                
            }

                
        }

        cout << "All the changes were made it !!" << endl;
        cout << "\n";
        return true;
    }

    cout << citySource << " does not exist in our system !!!" << endl;

    return false;
}

bool Admin::changeValue( string citySource, vector<string>& citytargets, vector<int>& newValues){

    if( vertices.count(citySource) && citytargets.size() && newValues.size() && citytargets.size() == newValues.size()){
        for(int i = 0; i < citytargets.size(); i++){
            try
            {

                if(vertices.count(citytargets[i]) && citySource != citytargets[i]){

                    cout << "The Ticket Value between " << citySource << " and  " << citytargets[i] << " is: R$" << edgesTicketsValues[vertices[citySource]][vertices[citytargets[i]]] << endl;;
                    edgesTicketsValues[vertices[citySource]][vertices[citytargets[i]]] = newValues[i];
                    edgesTicketsValues[vertices[citytargets[i]]][vertices[citySource]] = newValues[i];
                    cout << "The new value between the both are: R$" << edgesTicketsValues[vertices[citySource]][vertices[citytargets[i]]] << endl;
                    cout << "\n";
                }
                else {
                    cout << "The city " << citytargets[i] << " does not exist or it wasn't possible made this change !!!" << endl;
                    cout << "\n";
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                
            }  
        }

        return true;
    }

    cout << "It was not possible make the changes" << endl;
    cout << "\n";
    return false;
}

