#include <iostream>
#include <vector>

#include "Headers\TrainStation.h"
#include "Headers\Admin.h"
#include "Headers\Costumer.h"

using namespace std;

int main (){
    TrainMap graph;
    Admin userAdmin;
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
            string user;
            string password;

            cout << "User: ";
            cin >> user;
            cout << "\nPassword: ";
            cin >> password;

            system("CLS");
            bool result;
            result = userAdmin.verification(&user, &password);
            
            if (result){
                string citySource;
                int cont;
                string cityTargetName;
                int distVal;
                int ticketVal;
                vector<string> cityTarget;
                vector<int> dist;
                vector<int> ticketValue;

                while(true){
                    cout << "Select your option: " << endl;
                    cout << "1 - Add a new city in the Train Station system\n2 - Remove a city from the Train Station system\n3 - Add a new connection between cities\n4 - Remove a connection between cities\n5 - Change distance between some cities\n6 - Change the ticket value of some cities\n7 - Exit" << endl;
                    cout << "Select: ";
                    cin >> decision;

                    while( decision < 1 && decision > 7){
                        system("CLS");
                        cout << "Invalid option selected !!!" << endl;
                        cout << "1 - Add a new city in the Train Station system\n2 - Remove a city from the Train Station system\n3 - Add a new connection between cities\n4 - Remove a connection between cities\n5 - Change distance between some cities\n6 - Change the ticket value of some cities\n7 - Exit" << endl;
                        cout << "Select: ";
                        cin >> decision;
                    }

                    system("CLS");

                    switch (decision)
                    {
                    case 1:
                        cout << "Insert the name of the city you want to add in the system:" << endl;
                        cout << "Type: ";
                        cin >> citySource;
                        userAdmin.addCity(citySource);
                        break;
                    
                    case 2:
                        cout << "Insert the name of the city you want to remove from the system:" << endl;
                        cout << "Type: ";
                        cin >> citySource;
                        userAdmin.removeCity(citySource);
                        break;
                    
                    case 3:
                        cout << "Insert the name of the city you want to add a new connection:" << endl;
                        cout << "Type: ";
                        cin >> citySource;
                        cout << "\nInsert the number of the connections you want to add:"<< endl;
                        cout << "Type: ";
                        cin >> cont;

                        for(int i = 0; i < cont; i++){
                            cout << "\nInsert the name of the city which is the new connection: " << endl;
                            cout << "Type: ";
                            cin >> cityTargetName;
                            cout <<"\nInsert the distance between "<< citySource << " and " << cityTargetName << ":" << endl;
                            cout << "Type: ";
                            cin >> distVal;
                            cout <<"\nInsert the value of the ticket between "<< citySource << " and " << cityTargetName << ":" << endl;
                            cout << "Type: ";
                            cin >> ticketVal;

                            cityTarget.push_back(cityTargetName);
                            dist.push_back(distVal);
                            ticketValue.push_back(ticketVal);
                            
                        }

                        userAdmin.addCityConnections(citySource, cityTarget, dist, ticketValue);
                    
                    case 4:
                        cout << "Insert the name of the city you want to remove a connection:" << endl;
                        cout << "Type: ";
                        cin >> citySource;
                        cout << "\nInsert the number of the connections you want to remove:"<< endl;
                        cout << "Type: ";
                        cin >> cont;

                        for(int i = 0; i < cont; i++){
                            cout << "\nInsert the name of the city which one you want remove the connection: " << endl;
                            cout << "Type: ";
                            cin >> cityTargetName;

                            cityTarget.push_back(cityTargetName);
                        }

                        userAdmin.removeCityConnections(citySource, cityTarget);
                        break;
                    
                    case 5:
                        cout << "Insert the name of the city you want to change the distances:" << endl;
                        cout << "Type: ";
                        cin >> citySource;
                        cout << "\nInsert the number of distances you want to change:"<< endl;
                        cout << "Type: ";
                        cin >> cont;

                        for( int i = 0; i < cont; i++){
                            cout << "\nInsert the name of the city which one you want to change the distance to " << citySource << ":" << endl;
                            cout << "Type: ";
                            cin >> cityTargetName;
                            cout <<"\nInsert the new  distance between "<< citySource << " and " << cityTargetName << ":" << endl;
                            cout << "Type: ";
                            cin >> distVal;

                            cityTarget.push_back(cityTargetName);
                            dist.push_back(distVal);
                        }

                        userAdmin.changeDistance(citySource, cityTarget, dist);
                        break;
                    
                    case 6:
                        cout << "\nInsert the name of the city that you want to change its tickets values:" << endl;
                        cout << "Type: ";
                        cin >> citySource;
                        cout << "\nInsert the number of tickets you want to change the value:"<< endl;
                        cout << "Type: ";
                        cin >> cont;

                        for(int i = 0; i < cont; i++){
                            cout << "\nInsert the name of the city which one you want to change the ticket value to " << citySource << ":" << endl;
                            cout << "Type: ";
                            cin >> cityTargetName;
                            cout <<"\nInsert the new  value of the ticket between "<< citySource << " and " << cityTargetName << ":" << endl;
                            cout << "Type: ";
                            cin >> ticketVal;

                            cityTarget.push_back(cityTargetName);
                            ticketValue.push_back(ticketVal);
                        }

                        userAdmin.changeValue(citySource, cityTarget, ticketValue);
                        break;

                    default:
                        break;
                    }

                    if ( decision == 7){
                        break;
                    }
                }
                
            }

            



        }
        else if (decision == 2){
            cout << "Select your option: " << endl;
            cout << "1 - Get the list of all Enabled cities\n2 - Get all the possibles connections from each city\n3 - Get the Possibles routes from some specific city\n4 - Get the cheaper route to a city\n5 - Get the quickler route to a city\n6 - Exit" << endl;
            cout <<"Select: ";
            cin >> decision;

            while( decision < 1 && decision > 6){
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

            switch (decision)
            {
            case 1:
                costumerUser.getCities();
                break;
            
            case 2:
                costumerUser.getAllConnections();
                break;
            
            case 3:
                cout << "Insert the city you want the connections: " << endl;
                cout << "Type: ";
                cin >> citySource;
                costumerUser.getPossiblesRoutes(citySource);
                break;
            
            case 4:
                cout << "Insert the city you wanna go from:" << endl;
                cout << "Type: ";
                cin >> citySource;
                cout << "\nInsert the city you wanna go to:" << endl;
                cout << "Type: ";
                cin >> cityTarget;
                costumerUser.getCheaperRoute(citySource, cityTarget);
                break;

            case 5:
                cout << "Insert the city you wanna go from:" << endl;
                cout << "Type: ";
                cin >> citySource;
                cout << "\nInsert the city you wanna go to:" << endl;
                cout << "Type: ";
                cin >> cityTarget;
                costumerUser.getQuicklerRoute(citySource, cityTarget);
                break;

            default:
                break;
            }
        }
        else{
            break;
        }

    }
    
    return 0;
};