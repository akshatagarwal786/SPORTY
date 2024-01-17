#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;

void AvailableItems::removeFromData(vector<string> itemsId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
         if(conn){
                for(int i=0;i<itemsId.size();i++){
                    query="DELETE FROM availableitems WHERE ITEM_ID= '"+itemsId[i]+"'";
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

int AvailableItems::itemAvailable(string item) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
        if(conn){
                query="SELECT * FROM availableitems WHERE ITEM_CATEGORY='"+item+"'";
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

void AvailableItems::addToAvailableData(vector<string> items, vector<string> itemId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
        if(conn){
                for(int i=0;i<itemId.size();i++){
                    query="INSERT INTO availableitems (ITEM_CATEGORY,ITEM_ID) VALUES ( '"+items[i]+"','"+itemId[i]+"')";
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

void AvailableItems::addItem(string item, vector<string> itemId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
        if(conn){
                for(int i=0;i<itemId.size();i++){
                    query="INSERT INTO availableitems (ITEM_CATEGORY,ITEM_ID) VALUES ( '"+item+"','"+itemId[i]+"')";
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

void AvailableItems::getCompleteList(vector<string> &itemCategory, vector<int> &itemCount) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
            if(conn){
                    query="SELECT * FROM availableitems";

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
                                    itemCategory.push_back(it->first);
                                    itemCount.push_back(it->second);
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

string AvailableItems::getId(string item) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
        if(conn){
                query="SELECT * FROM availableitems WHERE ITEM_CATEGORY='"+item+"'";
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
