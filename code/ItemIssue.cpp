#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"

using namespace std;

bool ItemIssue::open(Student student) {

    system("clear");
    vector<string>ItemCategory;
    if(!this->checkDue(student) || !this->canIssue(student)) {
        if(!this->checkDue(student)){
            this->showMessage("Please Clear Previous Dues\n\n");
        }
        else{
            this->showMessage("You have already issued Five Items\n\n");
        }
        this->showItemList(ItemCategory);
        int type = this->getValidInput(2);
        switch(type){
            case 1:{
                return this->backToHomepage();
            }
            case 2:{
                return this->logout();
            }
        }
    }
    else{
        this->getAvailableItems(ItemCategory,student);
        int n = ItemCategory.size();
        if(n==0){
            this->showMessage("No Items are Available to Issue\n\n");
        }
        this->showItemList(ItemCategory);
        int type = this->getValidInput(n+2);
        if(type==n+1){
            return this->backToHomepage();
        }
        else if(type==n+2){
            return this->logout();
        }
        else{

            if(this->watchmanVerification()) {

                vector<string> ItemRequested, ItemId, issueDate;
                ItemRequested.push_back(ItemCategory[type - 1]);
                this->getItemData(ItemRequested, ItemId, issueDate);
                this->changeItemData(ItemRequested, ItemId, student, issueDate);
                this->showMessage("Items issued successfully !!\n\nPress 1 to Continue..");
                this->getValidInput(1);
                return this->open(student);
            }
            else{
                this->showMessage("Watchman is not Verified, Try Again\n\nPress 1 to continue..");
                this->getValidInput(1);
                return this->open(student);
            }
        }
    }

}

bool ItemIssue::checkDue(Student student) {

    double dues = student.getDues();
    if(dues ==0 )
        return true;
    return false;

}

void ItemIssue::showMessage(string show) {

    cout<<show;

}

int ItemIssue::getValidInput(int n) {
    
    
    
    string x;
    cin>>ws;
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
        cout<<"Please enter valid input: ";
        return getValidInput(n);
    }
    
}



void ItemIssue::showItemList(vector<string> ItemCategory) {

    for(int i=1;i<=ItemCategory.size();i++){
        cout<<"Enter "<<i<<" to issue "<<ItemCategory[i-1]<<"\n\n";
    }
    int n = ItemCategory.size();
    cout<<"Enter "<<n+1<<" to go back to Homepage\n\n";
    cout<<"Enter "<<n+2<<" to logout\n\n";

}

void ItemIssue::showFinalItemsList(vector<string> ItemCategory) {



}

void ItemIssue::getAvailableItems(vector<string> &ItemCategory, Student student) {
    
    cout<<"Please wait fetching available list for you.\n\n";
    TotalItems myTotalItems;
    OutstandingItems myOutstandingItems;
    AvailableItems myAvailableItems;
    myTotalItems.getItemList(ItemCategory);
    for(int i=0;i<ItemCategory.size();i++){
        if(myAvailableItems.itemAvailable(ItemCategory[i]) && !myOutstandingItems.removeOutStanding(ItemCategory[i],student)){}
        else{
            ItemCategory.erase(ItemCategory.begin()+i);
            i--;
        }
    }
    system("clear");

}

void ItemIssue::getItemData(vector<string> &ItemCategory, vector<string> &ItemId, vector<string> &issueDate) {

    AvailableItems myAvailableItems;
    OutstandingItems myOutstandingItems;
    for(int i=0;i<ItemCategory.size();i++){
        string id = myAvailableItems.getId(ItemCategory[i]);
        string Date = myOutstandingItems.getTodayDate();
        ItemId.push_back(id);
        issueDate.push_back(Date);
    }

}

bool ItemIssue::watchmanVerification() {
    
    cout<<"Enter Password to verify watchman : ";
    
    Watchman watchman;
    string password;
    cin>>ws;
    getline(cin,password);
    int x= watchman.verifyWatchman(password);
    
    return x;
}


void ItemIssue::changeItemData(vector<string> ItemCategory, vector<string> ItemId, Student student, vector<string> Date) {

    AvailableItems myAvailableItems;
    OutstandingItems myOutstandingItems;
    myOutstandingItems.addToOutStandingData(ItemCategory, ItemId, student, Date);
    myAvailableItems.removeFromData(ItemId);

}

bool ItemIssue::logout() {

    return false;

}

bool ItemIssue::backToHomepage() {

    return true;

}

bool ItemIssue::canIssue(Student student) {

    OutstandingItems myOutstandingItems;
    int alreadyIssued = myOutstandingItems.issuedByStudent(student);
    if(alreadyIssued<5)
        return true;
    return false;

}



