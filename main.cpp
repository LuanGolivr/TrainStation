#include <iostream>
#include <vector>
#include "classes.h"

using namespace std;

int main (){
    TrainMap graph;
    //testing the features

    while(true){
        int decision;
        cout << "Welcome to TrainStation's system !" << endl;
        cout << "What do you want to do ?\n " << endl;
        cout << "1 - Check all the cities in the system\n2 - Check out the possibles routes I can get from my current city\n3 - Check out all the possibles routes in the system\n4 - Check out some ADM functions\n5 - Exit" << endl;
        cout << "Pick up your option: " << endl;
        cin >> decision;

        while ( decision < 1 || decision > 5){
                cout << "There isn't this option" << endl;
                cout << "Choose again: " << endl;
                cin >> decision;
                cout << endl;
        }

        system("CLS");
        if(decision == 1){
            graph.getCities();
            cout << "\n";
        }
        else if (decision == 2){
            string city;
            cout << "Insert the city where you are: " << endl;
            cin >> city;
            graph.getPossiblesRoutes(city);
            cout << "\n";
        }
        else if(decision == 3){
            graph.getAllConnections();
            cout << "\n";
        }
        else if (decision == 4){
            cout << "1 - Add a new city in the system\n2 - Remove a city from the system\n3 - Add new connections between cities\n4 - Remove connections between cities\n5 - Change distance between cities\n6 - Change the ticket's values\n7 - Exit" << endl;
            cout << "Pick up your option: " << endl;
            cin >> decision;

            while (decision < 1 || decision > 7)
            {
                cout << "There isn't this option" << endl;
                cout << "Choose again: " << endl;
                cin >> decision;
                cout << "\n";
            }

            system("CLS");
            if ( decision == 1){
                string city;
                cout << "Insert the name of the city that you want add in the system: " << endl;
                cin >> city;
                graph.addCity(city);
                cout << "\n";
            }
            else if( decision == 2){
                string city;
                cout << "Insert the name of the city that you want remove from the system: " << endl;
                cin >> city;
                graph.removeCity(city);
                cout << "\n";
            }
            else if( decision == 3){
                string sourceCity;
                cout << "Insert the name of the city which you want add connections:  " << endl;
                cin >> sourceCity;
                cout << "\n";

                vector<string>neighboorCities;
                int nCities;
                string city;
                cout << "Insert the number of connections you want add: " << endl;
                cin >> nCities;

                for(int i = 0; i < nCities; i++){
                    cout << "Insert the city's name: " << endl;
                    cin >> city;
                    neighboorCities.push_back(city);
                }

                vector<int>neighboorDist;
                int distValue;
                cout << "\n";

                for(int i = 0; i < nCities; i++){
                    cout << "Insert the distances between " << sourceCity << " and the cities you just added before: " << endl;
                    cin >> distValue;
                    neighboorDist.push_back(distValue);
                }

                vector<int>neighboorTickets;
                int ticketsValues;
                cout << "\n";

                for(int i = 0; i < nCities; i++){
                    cout << "Insert the values of the Tickets from " << sourceCity << " and the cities you just added before: " << endl;
                    cin >> ticketsValues;
                    neighboorTickets.push_back(ticketsValues);
                }

                graph.addCityConnections(sourceCity, neighboorCities, neighboorDist, neighboorTickets);
                
            }
            else if( decision == 4){
                string sourceCity;
                cout << "Insert the name of the city which one you want remove connections:  " << endl;
                cin >> sourceCity;
                cout << "\n";

                vector<string>neighboorCities;
                int nCities;
                string city;
                cout << "Insert the number of connections you want remove: " << endl;
                cin >> nCities;

                for(int i = 0; i < nCities; i++){
                    cout << "Insert the city's name: " << endl;
                    cin >> city;
                    neighboorCities.push_back(city);
                }
                graph.removeCityConnections(sourceCity, neighboorCities);
            }
            else if( decision == 5){

                string sourceCity;
                cout << "Insert the name of the city which one you want change its neighbor's distance :  " << endl;
                cin >> sourceCity;
                cout << "\n";

                vector<string>neighboorCities;
                int nCities;
                string city;
                cout << "Insert the number of connections distance you want to change: " << endl;
                cin >> nCities;

                for(int i = 0; i < nCities; i++){
                    cout << "Insert the city's name: " << endl;
                    cin >> city;
                    neighboorCities.push_back(city);
                }

                vector<int>newDist;
                int dist;

                for(int i = 0; i < nCities; i++){
                    cout << "insert the new distance: " << endl;
                    cin >> dist;
                    newDist.push_back(dist);
                }

                graph.changeDistance(sourceCity, neighboorCities, newDist);
            }


            
        }

    }
    
    return 0;
};