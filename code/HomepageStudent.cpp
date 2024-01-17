#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;

bool HomepageStudent::open(Student student) {

    system("clear");
    this->showStudentHomePage();
    int type=this->getVaildInput();
    if(type==1){
        if(this->issueitem(student)){
            return this->open(student);
        }
        else{
            return true;
        }
    }
    else if(type==2){
        if(this->returnItem(student)){
            return this->open(student);
        }
        else{
            return true;
        }
    }
    else if(type==3){
        if(this->checkDues(student)){
            return this->open(student);
        }
        else{
            return true;
        }
    }
    else if(type==4){
       return this->logout();
    }
    else{
        return this->exit();
    }

}

void HomepageStudent::showStudentHomePage() {

    cout<<"Enter 1 to issue Items\n\n";
    cout<<"Enter 2 to return Items\n\n";
    cout<<"Enter 3 to  check dues \n\n";
    cout<<"Enter 4 to logout \n\n";
    cout<<"Enter 5 to exit\n\n";

}

int HomepageStudent::getVaildInput() {
    
    
    string x;
    cin>>ws;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input within range : ";
        return getVaildInput();
    }
    else if(x[0]<='5' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        cout<<"Please enter valid integral input within  range";
        return getVaildInput();
    }
    
}



bool HomepageStudent::issueitem(Student student) {

    ItemIssue myItemIssue;
    return myItemIssue.open(student);

}


bool HomepageStudent::returnItem(Student student) {

    ReturnItem myReturnItem;
    return myReturnItem.open(student);

}


bool HomepageStudent::checkDues(Student student) {

    ControlDuesOfStudent myControlDuesOfStudent;
    return myControlDuesOfStudent.open(student);

}


bool HomepageStudent::logout() {

    return 1;

}

bool HomepageStudent::exit() {

    return 0;

}
