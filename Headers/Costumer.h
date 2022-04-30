#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "TrainStation.h"

using namespace std;

class Costumer : public TrainMap {

public:
    void getCities();

    void getPossiblesRoutes( string );

    void getAllConnections();

    bool getCheaperRoute( string , string);

    bool getQuicklerRoute(string, string);
};

void Costumer::getCities(){

    cout << "The list of cities: " << endl;
    for(int i = 0; i < cities.size(); i++){
        cout <<"- " << cities[i] << endl;
    }
}

void Costumer::getPossiblesRoutes( string citySource ){
    if(vertices.count(citySource)){
        try
        {
            int sourcePosition = vertices[citySource];
            cout << "The possibles destinations from " << citySource << ": " << endl;
            cout << "\n";
            for(int i = 0; i < edges.size(); i++){
                if (edges[sourcePosition][i] > 0){
                    cout << citySource << " ----> " << cities[i] << " ---- " << edges[sourcePosition][i] << "Km" << " ---- " << "R$" << edgesTicketsValues[sourcePosition][i] << endl;
                }
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }    
    }
    else {
        cout << "The city " << citySource << " does not exist in our system !!" << endl;
    }

    
}

void Costumer::getAllConnections(){ 
    cout << "All the connections are: " << endl;
    
    for(int i = 0; i < edges.size(); i++){
        for(int j = 0; j < edges.size(); j++){
            if (edges[i][j] > 0){
                cout << cities[i] << " ---> " << cities[j] << " ---- " << edges[i][j] << "Km" << " ---- " << "R$" << edgesTicketsValues[i][j] << endl;
            }
        }
        cout << "\n";
    }
}

bool Costumer::getCheaperRoute( string citySource, string cityTarget ){
    
    if(vertices.count(cityTarget) && vertices.count(cityTarget)){
        try
        {
            unordered_map<int, int> value;

            for( int i = 0; i < cities.size(); i++){
                value.insert({i,10000});
            }

            value[vertices[citySource]] = 0;

            unordered_set<int> visited;
            queue<int> heapValue;
            queue<int> heapIndex;

            heapValue.push(0);
            heapIndex.push(vertices[citySource]);
            int currentValue;
            int currentIndex;
            int target = vertices[cityTarget];

            while(!heapValue.empty()){
                
                currentValue = heapValue.front();
                currentIndex = heapIndex.front();
                heapValue.pop();
                heapIndex.pop();

                if(currentIndex == target){
                    cout << "The cheaper value required to reach " << cityTarget << " coming from " << citySource << " is : " <<value[target] << "km" << endl;
                    return true;
                }

                for(int i = 0; i < edgesTicketsValues.size(); i++){

                    if(edgesTicketsValues[currentIndex][i] > 0 && visited.count(i) <= 0){
                        heapValue.push( currentValue + edgesTicketsValues[currentIndex][i] );
                        heapIndex.push(i);
                        value[i] = min(value[i], currentValue + edgesTicketsValues[currentIndex][i] );
                    }
                }

                visited.insert(currentIndex);
            }

            cout << "There is no way to get to the " << cityTarget << " living from " << citySource << " , try from other city !!" << endl;
            return false;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            cout << "deu um erro aqui" << endl;
            return false;
        }
    }

    cout << "The cities " << citySource << ", " << cityTarget << " may do not exist in our system , please try again !!" << endl;
    return false;
}

bool Costumer::getQuicklerRoute( string citySource, string cityTarget ){

    if(vertices.count(citySource) && vertices.count(cityTarget)){
        try
        {
            unordered_map<int, int>dist;

            for(int i = 0; i < cities.size(); i++){
                dist.insert({i,10000});
            }

            dist[vertices[citySource]] = 0;

            unordered_set<int>visited;
            queue<int>heapDist;
            queue<int>heapIndex;

            heapDist.push(0);
            heapIndex.push(vertices[citySource]);
            int currentDist;
            int currentIndex;
            int target = vertices[cityTarget];

            while(!heapDist.empty()){

                currentDist = heapDist.front();
                currentIndex = heapIndex.front();
                heapDist.pop();
                heapIndex.pop();

                if(currentIndex == target){
                    cout << "The lowest distance required to reach the " << cityTarget << " coming from " << citySource << " is : " << dist[target] << "km" << endl;
                    return true;
                }

                for(int i = 0; i < edges.size(); i++){

                    if(edges[currentIndex][i] > 0 && visited.count(i) <= 0){
                        heapDist.push( currentDist + edges[currentIndex][i] );
                        heapIndex.push(i);
                        dist[i] = min(dist[i], currentDist + edges[currentIndex][i] );
                    }
                }

                visited.insert(currentIndex);
            }

            cout << "There is no way to get to the " << cityTarget << " living from " << citySource << " , try from other city !!" << endl;
            return false;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
        
    }

    cout << "The cities " << citySource << ", " << cityTarget << " may do not exist in our system , please try again !!" << endl;
    return false;

}



