#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"

using namespace std;

bool ReturnItem::open(Student student) {

    system("clear");
    vector<string>ItemCategory;
    this->getItemList(ItemCategory, student);
    int n = ItemCategory.size();
    if(n==0){
        this->showMessage("No Items are issued by you\n\n");
    }
    this->showItemList(ItemCategory);
    int type = this->getValidInput(n+2);
    if(type==n+1){
        return this->backToHomePage();
    }
    else if(type==n+2){
        return this->logout();
    }
    else{
        string ItemId = this->getItemDetails(ItemCategory[type-1],student);
        if(this->watchmanVerificatiion()){
            this->showMessage("Enter 1 if Item is damaged\n\nEnter 2 if Item is not damaged\n\n");
            int damaged = this->getValidInput(2);
            this->addDues(student,damaged,ItemId,ItemCategory[type-1]);
            this->removeFromOutstanding(ItemId);
            if(damaged==2){
                this->addToAvailable(ItemCategory[type-1],ItemId);
            }
            this->showMessage("Return was Successfull\n\nPress 1 to Continue..");
            this->getValidInput(2);
            return this->open(student);
        }
        else{
            this->showMessage("Watchman is not Verified, PLease Try Again\n\nPress 1 to continue..");
            this->getValidInput(1);
            return this->open(student);
        }
    }

}

void ReturnItem::showMessage(string show) {

    cout<<show;

}

void ReturnItem::showItemList(vector<string> ItemCategory) {

    for(int i=1;i<=ItemCategory.size();i++){
        cout<<"Enter "<<i<<" to return "<<ItemCategory[i-1]<<"\n\n";
    }
    int n = ItemCategory.size();
    cout<<"Enter "<<n+1<<" to go back to homepage\n\n";
    cout<<"Enter "<<n+2<<" to logout\n\n";

}

void ReturnItem::getItemList(vector<string> &ItemCatgeory, Student student) {
    
    cout<<"Please wait fetching list.\n\n";
    
    TotalItems myTotalItems;
    OutstandingItems myOutstandingItems;
    myTotalItems.getItemList(ItemCatgeory);
    for(int i=0;i<ItemCatgeory.size();i++){
        if(!myOutstandingItems.removeOutStanding(ItemCatgeory[i],student)){
            ItemCatgeory.erase(ItemCatgeory.begin()+i);
            i--;
        }
    }
    system("clear");
}

string ReturnItem::getItemDetails(string ItemsCategory, Student student) {

    OutstandingItems myOutstandingItems;
    return myOutstandingItems.getId(ItemsCategory,student);

}

void ReturnItem::removeFromOutstanding(string ItemId) {

    vector<string>ItemIds;
    ItemIds.push_back(ItemId);
    OutstandingItems myOutstandingItems;
    myOutstandingItems.removeFromOutStanding(ItemIds);

}

void ReturnItem::addToAvailable(string ItemCatgeory, string ItemId) {

    vector<string>ItemCategories, ItemIds;
    ItemCategories.push_back(ItemCatgeory);
    ItemIds.push_back(ItemId);
    AvailableItems myAvailableItems;
    myAvailableItems.addToAvailableData(ItemCategories, ItemIds);

}

void ReturnItem::addDues(Student student, int damaged, string ItemId, string ItemCategory) {

    double dues = 0;
    OutstandingItems myOutstandingItems;
    TotalItems myTotalItems;
    int extra = myOutstandingItems.additionalDays(ItemId);
    if(damaged==1){
       


        dues+=myTotalItems.getPrice(ItemCategory);
        
        student.addDues(dues);
    }
    else{
        dues+= extra*10;
        student.addDues(dues);
    }

}

bool ReturnItem::watchmanVerificatiion() {
    
    Watchman watchman;
    string password;
    cout<<"Enter password to verify watchman : ";
    cin>>ws;
    getline(cin,password);
    return watchman.verifyWatchman(password);
    
}


bool ReturnItem::logout() {

    return false;

}

bool ReturnItem::backToHomePage() {

    return true;

}

int ReturnItem::getValidInput(int n) {


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
