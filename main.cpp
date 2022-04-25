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
            getline(cin, city);
            graph.getPossiblesRoutes(city);
        }
        else if(decision == 3){
            graph.getAllConnections();
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
            }

            system("CLS");
            if ( decision == 1){
                string city;
                cout << "Insert the name of the city that you want add in the system: " << endl;
                getline(cin, city);
                graph.addCity(city);
            }
            else if( decision == 2){
                string city;
                cout << "Insert the name of the city that you want remove from the system: " << endl;
                graph.removeCity(city);
            }
            else if( decision == 3){
                string city;
                cout << "Insert the name of the city which you want add connections:  " << endl;
                getline(cin, city);
                
                vector<string>neighboorCities;
            }

            
        }

    }
    
    return 0;
};