#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"

using namespace std;

void Application::open() {

    system("clear");
    this->showApplicationHome();
    int type;
    type = getValidInput();
    switch(type){
        case 1:{
            ControlStudent myControlStudent;
            if(myControlStudent.open()){
                this->open();
            }
            break;
        }
        case 2:{
            SecretaryController mySecretaryController;
            if(mySecretaryController.open()){
                this->open();
            }
            break;
        }
        case 3:{

            break;
        }
    }

}

void Application::showApplicationHome() {

    cout<<"Press 1 for student Login\n\n";
    cout<<"Press 2 for secretary Login\n\n";
    cout<<"Press 3 to exit\n\n";

}

int Application::getValidInput() {



    string x;
    cin >> ws ;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput();
    }
    else if(x[0]<='3' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
            cout<<"Please enter valid input : ";
        return getValidInput();
    }

}
