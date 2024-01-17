#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"

using namespace std;

bool ViewControlDuesOfStudent::open() {

    system("clear");
    this->showViewControlDuesOfStudent();
    int type = this->getValidInput(3);
    switch(type){
        case 1:{
            system("clear");
            this->showMessage("Please Enter Student Roll Number : ");
            string roll = this->getRollNumber();
            Student temp;
            if(temp.getDetailsByRoll(roll)){
                double dues = this->getDues(temp);
                string name = this->getName(temp);
                cout<<"Dues of "<<name<<" : "<<dues<<"\n\n";
            }
            else{
                this->showMessage("Entered Roll Number Doesn't Exist\n\n");
            }
            this->showMessage("Press 1 to Continue..");
            this->getValidInput(1);
            return this->open();
        }
        case 2:{
            return this->goBackToHomePage();
        }
        case 3:{
            return this->logout();
        }
    }

}

string ViewControlDuesOfStudent::getRollNumber() {
    
    string roll;
    cin>>ws;
    getline(cin,roll);
    for(int i=0;i<roll.size();i++){
        roll[i]=toupper(roll[i]);
    }
    return roll;
    
}



double ViewControlDuesOfStudent::getDues(Student student) {

    double dues = student.getDues();
    return dues;

}

string ViewControlDuesOfStudent::getName(Student student) {

    string name = student.getName();
    return name;
}

void ViewControlDuesOfStudent::showMessage(string message) {

    cout<<message;

}

bool ViewControlDuesOfStudent::goBackToHomePage() {

    return true;

}

bool ViewControlDuesOfStudent::logout() {

    return false;

}

void ViewControlDuesOfStudent::showViewControlDuesOfStudent() {

    cout<<"Enter 1 to find dues of any student by entering roll number\n\n";
    cout<<"Enter 2 to go back to homepage\n\n";
    cout<<"Enter 3 to logout\n\n";

}

int ViewControlDuesOfStudent::getValidInput(int n) {



    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput(n);
    }
    else if(x[0]<=n+'0' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        return getValidInput(n);
    }
}
