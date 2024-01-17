#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;

bool SecretaryController::open() {

    SecretaryLoginController mySecretaryLoginController;
    return mySecretaryLoginController.open(this->secretary);

}

bool SecretaryHomePageController::open(Student secretary) {

    system("clear");
    this->showSecretaryHomePage();
    int type = this->getValidInput();
    switch(type){
        case 1:{
            if(this->issueitem(secretary)){
                return this->open(secretary);
            }
            else{
                return true;
            }
        }
        case 2:{
            if(this->returnItem(secretary)){
                return this->open(secretary);
            }
            else{
                return true;
            }
        }
        case 3:{
            if(this->checkDues(secretary)){
                return this->open(secretary);
            }
            else {
                return true;
            }
        }
        case 4:{
            if(this->viewDuesOfStudent()){
                return this->open(secretary);
            }
            else {
                return true;
            }
        }
        case 5:{
            if(this->addItem()){
                return this->open(secretary);
            }
            else {
                return true;
            }
        }
        case 6:{
            if(this->viewDetails()){
                return this->open(secretary);
            }
            else {
                return true;
            }
        }
        case 7:{
            return this->logout();
        }
        case 8:{
            return this->exit();
        }
    }

}

void SecretaryHomePageController::showSecretaryHomePage() {

    cout<<"Enter 1 to issue Items\n\n";
    cout<<"Enter 2 to return Items\n\n";
    cout<<"Enter 3 to check dues \n\n";
    cout<<"Enter 4 to check dues of any student\n\n";
    cout<<"Enter 5 to add Items\n\n";
    cout<<"Enter 6 to view details of Items\n\n";
    cout<<"Enter 7 to logout \n\n";
    cout<<"Enter 8 to exit\n\n";

}

int SecretaryHomePageController::getValidInput() {
    
    
    
    string x;
    cin>>ws;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getVaildInput();
    }
    else if(x[0]<='8' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        cout<<"Please enter valid input: ";
        return getVaildInput();
    }
    
    
}


bool SecretaryHomePageController::viewDetails() {

    ViewDetailsController myViewDetailsController;
    return myViewDetailsController.open();

}

bool SecretaryHomePageController::viewDuesOfStudent() {

    ViewControlDuesOfStudent myViewControlDuesOfStudent;
    return myViewControlDuesOfStudent.open();

}

bool SecretaryHomePageController::addItem() {

    ItemAdding myItemAdding;
    return myItemAdding.open();

}


bool SecretaryController::open() {

    SecretaryLoginController mySecretaryLoginController;
    return mySecretaryLoginController.open(this->secretary);

}

bool SecretaryLoginController::open(Student secretary) {
    
    system("clear");
    string secretaryUserName;
    string secretaryPassword;
    
    this->showSecretaryLogin("Username");
    getline(cin,secretaryUserName);
    
    this->showSecretaryLogin("Password");
    getline(cin,secretaryPassword);
    
    bool matchdetails = secretary.matchDetailsSecretary(secretaryUserName,secretaryPassword);
    if(matchdetails){
        return this->loginSuccess(secretary);
    }
    else{
        return this->loginFail(secretary);
    }
    
}


void SecretaryLoginController::showSecretaryLogin(string show) {

    cout<<"Please Enter "<<show<<" : ";

}

bool SecretaryLoginController::loginSuccess(Student secretary) {

    SecretaryHomePageController mySecretaryHomePageController;
    return mySecretaryHomePageController.open(secretary);

}

bool SecretaryLoginController::loginFail(Student secretary) {

    system("clear");
    cout<<"Your Details didn't match with our Database\n";
    for(int i=0;i<1000000000;i++){}
    return true;

}
