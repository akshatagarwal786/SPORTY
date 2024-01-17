#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"

using namespace std;

bool ViewByAvailabilityController::open() {

    system("clear");
    vector<string> ItemCategory;
    vector<int> ItemCount;
    this->getAvailabilityList(ItemCategory,ItemCount);
    this->showItemList(ItemCategory,ItemCount);
    int type;
    type = this->getValidInput();
    switch(type){
        case 1:{
            return this->goBackToViewDetails();
        }
        case 2:{
            return this->logout();
        }
    }

}

void ViewByAvailabilityController::getAvailabilityList(vector<string> &ItemCategory, vector<int> &ItemCount) {

    AvailableItems a;
    a.getCompleteList(ItemCategory,ItemCount);

}

void ViewByAvailabilityController::showItemList(vector<string> ItemCategory,vector<int> ItemCount) {
    
    cout<<setw(20)<<"Item Category"<<setw(20)<<"Item Count\n\n";
    for(int i=0;i<ItemCategory.size();i++){
        cout<<setw(20)<<ItemCategory[i]<<setw(20)<<ItemCount[i]<<"\n";
    }
    cout<<"\n\n";
    cout<<"Enter 1 to go back\n\n";
    cout<<"Enter 2 to logout\n\n";
    
}


bool ViewByAvailabilityController::logout() {

    return false;

}

bool ViewByAvailabilityController::goBackToViewDetails() {

    return true;

}

int ViewByAvailabilityController::getValidInput(){



    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput();
    }
    else if(x[0]<='2' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        return getValidInput();
    }

}

bool ViewByCategoryController::open() {

    system("clear");
    vector<string>ItemCategory;
    this->getItemCategory(ItemCategory);
    this->showList(ItemCategory);
    int n = ItemCategory.size();
    int input =  this->getValidInput(n+2);
    if(input == n+1){
        return this->goBackToViewDetails();
    }
    else if(input == n+2){
        return this->logout();
    }
    else{
        system("clear");
        int totalavailable = this->getAvailableList(ItemCategory[input-1]);
        this->showAvailableList(totalavailable, ItemCategory[input-1]);
        vector<string> ItemId, roll, issueDate, returnDate;
        this->getOutStandingList(ItemCategory[input-1], ItemId, roll, issueDate, returnDate);
        this->showOutStanding(ItemCategory[input-1], ItemId, roll, issueDate, returnDate);
        cout<<"Press 1 to Continue..";
        this->getValidInput(1);
        return this->open();
    }

}

void ViewByCategoryController::showList(vector<string>ItemCategory) {

    for(int i=1;i<=ItemCategory.size();i++){
        cout<<"Enter "<<i<<" to view details of "<<ItemCategory[i-1]<<"\n\n";
    }
    int i = ItemCategory.size();
    cout<<"Enter "<<i+1<<" to go back\n\n";
    cout<<"Enter "<<i+2<<" to logout\n\n";

}

int ViewByCategoryController::getValidInput(int n) {


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

void ViewByCategoryController::showOutStanding(string ItemCategory, vector<string> ItemId, vector<string> roll, vector<string> issueDate, vector<string>returnDate) {
    
    cout<<"List of Outstanding "<<ItemCategory<<"s is given below : \n\n";
    cout<<setw(20)<<"ItemId"<<setw(20)<<"Roll Number"<<setw(20)<<"Issue Date"<<setw(20)<<"Return Date\n\n";
    for(int i=0;i<ItemId.size();i++){
        cout<<setw(20)<<ItemId[i]<<setw(20)<<roll[i]<<setw(20)<<issueDate[i]<<setw(20)<<returnDate[i]<<"\n\n";
    }
    
}


void ViewByCategoryController::getOutStandingList(string ItemCategory, vector<string> &ItemId, vector<string> &roll, vector<string> &issueDate, vector<string> &returnDate) {

    OutstandingItems myOutstandingItems;
    myOutstandingItems.getListOfOtstanding(ItemCategory, ItemId, roll, issueDate, returnDate);

}

int ViewByCategoryController::getAvailableList(string ItemCategory) {

    AvailableItems myAvailableItems;
    return myAvailableItems.itemAvailable(ItemCategory);

}

void ViewByCategoryController::showAvailableList(int count,string ItemCategory) {

    cout<<count<<" "<<ItemCategory<<"s are Available\n\n";

}

bool ViewByCategoryController::logout() {

    return false;

}

bool ViewByCategoryController::goBackToViewDetails() {

    return true;

}

void ViewByCategoryController::getItemCategory(vector<string> &ItemCategory) {

    TotalItems myTotalItems;
    myTotalItems.getItemList(ItemCategory);

}


bool ViewByOutstandingController::open() {

    system("clear");
    vector<string> ItemCategory, ItemID, roll, issueDate, returnDate;
    this->getOutstandingList(ItemCategory, ItemID, roll, issueDate, returnDate);
    this->showOutStandingList(ItemCategory, ItemID, roll, issueDate, returnDate);
    int type;
    type = this->getValidInput();
    switch(type){
        case 1:{
            return this->goBackToViewDetails();
        }
        case 2:{
            return this->logout();
        }
    }

}

void ViewByOutstandingController::getOutstandingList(vector<string> &ItemCategory, vector<string> &ItemId, vector<string> &roll, vector<string> &issueDate, vector<string> &returnDate) {

    OutstandingItems o;
    o.getCompleteList(ItemCategory, ItemId, roll, issueDate, returnDate);

}

void ViewByOutstandingController::showOutStandingList(vector<string> ItemCategory, vector<string> equimentId, vector<string> roll, vector<string> issueDate, vector<string> returnDate) {
    
    cout<<setw(20)<<"Item Category"<<setw(20)<<"Item Id"<<setw(20)<<"Roll Number"<<setw(20)<<"Issue Date"<<setw(20)<<"Return Date\n\n";
    for(int i=0;i<ItemCategory.size();i++){
        cout<<setw(20)<<ItemCategory[i]<<setw(20)<<equimentId[i]<<setw(20)<<roll[i]<<setw(20)<<issueDate[i]<<setw(20)<<returnDate[i]<<"\n\n";
    }
    cout<<"\n";
    cout<<"Enter 1 to Go back\n\n";
    cout<<"Enter 2 to logout\n\n";
    
}


bool ViewByOutstandingController::logout() {

    return false;

}

bool ViewByOutstandingController::goBackToViewDetails() {

    return true;

}

int ViewByOutstandingController::getValidInput(){



    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput();
    }
    else if(x[0]<='2' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        return getValidInput();
    }
}

bool ViewDetailsController::open() {

    system("clear");
    this->showViewDetails();
    int type = this->getValidInput();
    switch(type){
        case 1:{
            if(this->viewByCategory()){
                return this->open();
            }
            else {
                return 0;
            }
        }
        case 2:{
            if(this->viewByOutstanding()){
                return this->open();
            }
            else {
                return 0;
            }
        }
        case 3:{
            if(this->viewByAvailability()){
                return this->open();
            }
            else {
                return 0;
            }
        }
        case 4:{
            return this->backToHomepage();
        }
        case 5:{
            return this->logout();
        }
    }

}

void ViewDetailsController::showViewDetails() {

    cout<<"Enter 1 to view detail by Item Category\n\n";
    cout<<"Enter 2 to view detail of all Outstanding Items\n\n";
    cout<<"Enter 3 to view detail of all Available Items\n\n";
    cout<<"Enter 4 to go back to Homepage\n\n";
    cout<<"Enter 5 to logout\n\n";

}

int ViewDetailsController::getValidInput() {



    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput();
    }
    else if(x[0]<='5' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        return getValidInput();
    }

}

bool ViewDetailsController::viewByCategory() {

    ViewByCategoryController myViewByCategoryController;
    return myViewByCategoryController.open();

}

bool ViewDetailsController::viewByOutstanding() {

    ViewByOutstandingController myViewByOutstandingController;
    return myViewByOutstandingController.open();

}

bool ViewDetailsController::viewByAvailability() {

    ViewByAvailabilityController myViewByAvailabilityController;
    return myViewByAvailabilityController.open();

}

bool ViewDetailsController::logout() {

    return false;

}

bool ViewDetailsController::backToHomepage() {

    return true;

}
