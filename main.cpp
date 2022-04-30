#include <iostream>
#include <vector>

#include "Headers\TrainStation.h"
#include "Headers\Admin.h"
#include "Headers\Costumer.h"

using namespace std;

int main (){
    TrainMap graph;
    Admin user;
    Costumer costumerUser;

    //testing the features

    while (true){
        int decision;

        cout << "Welcome to the Train Station !!!" << endl;
        cout << "Select how you want to access our system: " << endl;
        cout << "1 - Admin\n2 - Costumer\n3 - Exit" << endl;
        cout << "Select: ";
        cin >> decision;

        while (decision < 1 || decision > 3){
            system("CLS");
            cout << "Invalid option selected !!" << endl;
            cout << "1 - Admin\n2 - Costumer\n3 - Exit" << endl;
            cout << "Select: ";
            cin >> decision;
        }

        if (decision == 1){


        }
        else if (decision == 2){
            cout << "Select your option: " << endl;
            cout << "1 - Get the list of all Enabled cities\n2 - Get all the possibles connections from each city\n3 - Get the Possibles routes from some specific city\n4 - Get the cheaper route to a city\n5 - Get the quickler route to a city\n6 - Exit" << endl;
            cout <<"Select: ";
            cin >> decision;

            while( decision < 1 && decision > 5){
                system("CLS");
                cout << "Invalid option selected !!" << endl;
                cout << "1 - Get the list of all Enabled cities\n2 - Get all the possibles connections from each city\n3 - Get the Possibles routes from some specific city\n4 - Get the cheaper route to a city\n5 - Get the quickler route to a city\n6 - Exit" << endl;
                cout <<"Select: ";
                cin >> decision;
            }

            string citySource;
            string cityTarget;
            string cont;

            system("CLS");

            if(decision == 1){
                costumerUser.getCities();
            }
            else if (decision == 2){
                costumerUser.getAllConnections();
            }
            else if (decision == 3){
                cout << "Insert the city you want the connections: " << endl;
                cout << "Type: ";
                cin >> citySource;
                costumerUser.getPossiblesRoutes(citySource);
            }
            else if (decision == 4){
                cout << "Insert the city you wanna go from:" << endl;
                cout << "Type: ";
                cin >> citySource;
                cout << "\nInsert the city you wanna go to:" << endl;
                cout << "Type: ";
                cin >> cityTarget;
                costumerUser.getCheaperRoute(citySource, cityTarget);
            }
            else if (decision == 5) {
                cout << "Insert the city you wanna go from:" << endl;
                cout << "Type: ";
                cin >> citySource;
                cout << "\nInsert the city you wanna go to:" << endl;
                cout << "Type: ";
                cin >> cityTarget;
                costumerUser.getQuicklerRoute(citySource, cityTarget);
            }
            else {
                break;
            }
        }
        else{
            break;
        }

    }
    
    return 0;
};