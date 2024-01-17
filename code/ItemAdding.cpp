#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;

class ItemAdding {
public:
    bool open();
    void getItemList(vector<string> &itemCategory);
    void showItemList(vector<string> itemCategory);
    void showMesage(string message, int pause);
    int getValidInput(int n);
    int getQuantity();
    string getId();
    void addItem(string item,vector<string> itemId);
    bool logout();
    bool backToHomePage();
};

using namespace std;

class AvailableItems {
public:
    void removeFromData(vector<string> itemsId);
    int itemAvailable(string item);
    void addToAvailableData(vector<string> items,vector<string> itemId);
    void addItem(string item,vector<string> itemId);
    void getCompleteList(vector<string> &itemCategory,vector<int> &itemCount);
    string getId(string item);
};

class TotalItems {
public:
    void totalItems();
    void getItemList(vector<string> &items);
    double getPrice(string item);
    string validId();
    void updateId(string itemcategory);
};
class Student {
    string  name;
    string roll;
    string userName;
    double dues;
public:
    bool matchDetailsStudent(string,string);
    string getName();
    string getRoll();
    string getUserName();
    double getDues();
    void clearDues(double val);
    bool matchDetailsSecretary(string userName,string password);
    void addDues(double due);
    bool getDetailsByRoll(string roll);
};


void AvailableItems::removeFromData(vector<string> ItemsId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
         if(conn){
                for(int i=0;i<ItemsId.size();i++){
                    query="DELETE FROM availableItems WHERE Item_ID= '"+ItemsId[i]+"'";
                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                    if(qstate){
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                        break;
                    }
                }
                mysql_close(conn);
         }
         else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
         }
}

int AvailableItems::itemAvailable(string Item) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
        if(conn){
                query="SELECT * FROM availableItems WHERE Item_CATEGORY='"+Item+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q );
                     if(!qstate){
                            res=mysql_store_result(conn);

                            int x=mysql_num_rows(res);
                            mysql_close(conn);
                            return x;
                     }
                     else{
                         cout<<"\n"<<mysql_error(conn)<<"\n";
                         mysql_close(conn);
                        return 0;
                     }
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
            return 0;
        }
}

void AvailableItems::addToAvailableData(vector<string> Items, vector<string> ItemId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
        if(conn){
                for(int i=0;i<ItemId.size();i++){
                    query="INSERT INTO availableItems (Item_CATEGORY,Item_ID) VALUES ( '"+Items[i]+"','"+ItemId[i]+"')";
                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                    if(qstate){
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                        break;
                    }
                }

                mysql_close(conn);
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
        }
}

void AvailableItems::addItem(string Item, vector<string> ItemId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
        if(conn){
                for(int i=0;i<ItemId.size();i++){
                    query="INSERT INTO availableItems (Item_CATEGORY,Item_ID) VALUES ( '"+Item+"','"+ItemId[i]+"')";
                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                    if(qstate){
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                        break;
                    }
                }

                mysql_close(conn);
            }
            else{
                cout<<"\n"<<mysql_error(conn)<<"\n";
            }
    }

void AvailableItems::getCompleteList(vector<string> &ItemCategory, vector<int> &ItemCount) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
            if(conn){
                    query="SELECT * FROM availableItems";

                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                       if(!qstate){
                                res=mysql_store_result(conn);

                                map<string,int> mp;
                                map<string,int> :: iterator it;
                                int x=mysql_num_rows(res);
                                while(x>0){
                                    row=mysql_fetch_row(res);
                                    mp[row[0]]++;
                                    x--;
                                }

                                it=mp.begin();

                                for(it=mp.begin();it!=mp.end();it++){
                                    ItemCategory.push_back(it->first);
                                    ItemCount.push_back(it->second);
                                }
                       }
                       else{
                            cout<<"\n"<<mysql_error(conn)<<"\n";
                       }
                    mysql_close(conn);
            }
            else{
                cout<<"\n"<<mysql_error(conn)<<"\n";
            }
}

string AvailableItems::getId(string Item) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
        if(conn){
                query="SELECT * FROM availableItems WHERE Item_CATEGORY='"+Item+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q );
                    if(!qstate){
                            res=mysql_store_result(conn);
                            if(mysql_num_rows(res)>0){
                                row=mysql_fetch_row(res);
                                string x=row[1];
                                mysql_close(conn);
                                return x;
                            }
                    }
                    else{
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                        return NULL;
                    }
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
            return NULL;
        }
}

bool ItemAdding::open() {

    system("clear");
    vector<string> ItemCategory;
    this->getItemList(ItemCategory);
    this->showItemList(ItemCategory);
    int n = ItemCategory.size();
    int type = this->getValidInput(n);
    if(type==n+1){
        return this->backToHomePage();
    }
    else if(type==n+2){
        return this->logout();
    }
    else{
        system("clear");
        this->showMesage("Please Enter Quantity to be added : ",0);
        int quantity = this->getQuantity();
        vector<string>ItemId;

        TotalItems myTotalItems;
  
        for(int i=0;i<quantity;i++){
            string id = this->getId();
            ItemId.push_back(id);
            myTotalItems.updateId(ItemCategory[type-1]);

        }
        this->addItem(ItemCategory[type-1], ItemId);
        this->showMesage("Items Added Successfully !!\n\n",1000000000);
        return this->open();
    }

}

void ItemAdding::getItemList(vector<string> &ItemCategory) {

    TotalItems myTotalItems;
    myTotalItems.getItemList(ItemCategory);

}

void ItemAdding::showItemList(vector<string> ItemCategory) {

    for(int i=1;i<=ItemCategory.size();i++){
        cout<<"Press "<<i<<" to add "<<ItemCategory[i-1]<<"\n\n";
    }
    int n = ItemCategory.size();
    cout<<"Press "<<n+1<<" to go back to Homepage\n\n";
    cout<<"Press "<<n+2<<" to logout\n\n";

}

void ItemAdding::showMesage(string message, int pause) {

    cout<<message;
    for(int i=0;i<=pause;i++){

    }

}

int ItemAdding::getValidInput(int n) {



    n+=2;
    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return this->getValidInput(n-2);
    }
    else if(x[0]<=n+'0' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        cout<<"Please enter valid input : ";
        return getValidInput(n-2);
    }

}

int ItemAdding::getQuantity() {
    string ip;
    int quantity=0;
    cin>>ws;
    getline(cin,ip);
    for(int i=0;i<ip.size();i++){
        if(ip[i]>='0' && ip[i]<='9'){
            quantity*=10;
            quantity+=(ip[i]-'0');
        }
        else{
            cout<<"Please enter valid input : \n";
            return getQuantity();
        }
    }
    while(quantity<0){
        cout<<"Please Enter Valid Quantity : ";
        cin>>quantity;
        cout<<"\n";
    }
    return quantity;
    
}


string ItemAdding::getId() {

    TotalItems myTotalItems;
    string id = myTotalItems.validId();
    return id;

}

void ItemAdding::addItem(string ItemCategory, vector<string> ItemId) {

    AvailableItems myAvailableItems;
    myAvailableItems.addItem(ItemCategory, ItemId);

}

bool ItemAdding::logout() {

    return false;

}

bool ItemAdding::backToHomePage() {

    return true;

}
