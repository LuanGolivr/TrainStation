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
        system("CLS");
        int decision;

        cout << "Welcome to the Train Station !!!" << endl;
        cout << "Select how you want to access our system: " << endl;
        cout << "1 - Admin\n2 - Costumer" << endl;
        cout << "Select: ";
        cin >> decision;

        while (decision != 1 && decision != 2){
            system("CLS");
            cout << "Invalid option selected !!" << endl;
            cout << "1 - Admin\n2 - Costumer" << endl;
            cout << "Select: ";
            cin >> decision;
        }

        

    }
    
    return 0;
};