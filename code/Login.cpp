#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;

bool Login::open(Student student) {
    
    system("clear");
    string studentUserName;
    string studentPassword;
    
    this->showStudentLogin("Username");
    cin>>ws;
    getline(cin,studentUserName);
    
    this->showStudentLogin("Password");
    cin>>ws;
    getline(cin,studentPassword);
    
    bool matchdetails= student.matchDetailsStudent(studentUserName,studentPassword);
    if(matchdetails){
        return this->loginSuccess(student);
    }
    else{
        return this->loginFail(student);
    }
    
}


void Login::showStudentLogin(string show) {

    cout<<"Please Enter "<<show<<" : ";

}

bool Login::loginSuccess(Student student) {

    HomepageStudent myHomepageStudent;
    return myHomepageStudent.open(student);

}

bool Login::loginFail(Student student) {

    system("clear");
    cout<<"Your Details didn't match with our Database\n";
    for(int i=0;i<1000000000;i++){}
    return 1;

}
