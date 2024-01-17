
#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"


using namespace std;

void TotalItems::totalItems() {



}

void TotalItems::getItemList(vector<string> &Items) {

    map<string,int> mp;
    map<string,int> :: iterator it;
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    string  val;

    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
            if(conn){
                    query="SELECT * FROM totalItems";

                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                        if(!qstate){
                                res=mysql_store_result(conn);
                                int x=mysql_num_rows(res);
                                while(x>0){
                                    row=mysql_fetch_row(res);
                                    mp[row[0]]++;
                                    x--;
                                }
                                for(it=mp.begin();it!=mp.end();it++){
                                    Items.push_back(it->first);

                                }
                                mysql_close(conn);
                        }
                        else{
                            cout<<"\n"<<mysql_error(conn)<<"\n";
                            mysql_close(conn);
                        }
            }
            else{
                cout<<"\n"<<mysql_error(conn)<<"\n";
            }

}

double TotalItems::getPrice(string Item) {

    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    string  val;

    const char* q;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
            if(conn){
                    query="SELECT * FROM totalItems WHERE Item_CATEGORY= '"+Item+"'";

                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                        if(!qstate){
                                res=mysql_store_result(conn);
                                int x=mysql_num_rows(res);

                                row=mysql_fetch_row(res);
                                string xxxx=row[1];
                                int ans=0;
                                for(int i=0;i<xxxx.size();i++){
                                    ans*=10;
                                    ans+=xxxx[i]-'0';

                                }
                                mysql_close(conn);
                                return ans;
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

string TotalItems::validId() {

    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    string  val;
    string valid_id;
    int valid_id1=0;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
            if(conn){
                    query="SELECT * FROM totalItems ";

                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                         if(!qstate){
                                res=mysql_store_result(conn);
                                int x=mysql_num_rows(res);

                                while(x>0){
                                    row=mysql_fetch_row(res);
                                    valid_id=row[2];
                                    stringstream ss(valid_id);
                                    int temp;
                                    ss>>temp;
                                    valid_id1=max(valid_id1,temp);
                                    x--;
                                }
                                valid_id1++;
                                string t="";

                                while(valid_id1){
                                    t+=(valid_id1%10)+'0';
                                    valid_id1/=10;
                                }
                                reverse(t.begin(),t.end());
                                mysql_close(conn);
                                return t;
                         }
                         else{
                                cout<<"\n"<<mysql_error(conn)<<"\n";
                                mysql_close(conn);
                                return NULL;
                         }
            }
            else{
                cout<<"\n"<<mysql_error(conn)<<"\n";
                return NULL;
            }
}

void TotalItems::updateId(string ItemType){


    string curr_valid_id=this->validId();

    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    string  val;
    string valid_id;
    int valid_id1=0;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);
            if(conn){
                    query="SELECT * FROM totalItems WHERE Item_CATEGORY= '"+ItemType+"'";

                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                    if(!qstate){
                                res=mysql_store_result(conn);
                                row=mysql_fetch_row(res);

                                string price=row[1];

                                 query="DELETE FROM totalItems WHERE Item_CATEGORY= '"+ItemType+"'";

                                    q=query.c_str();

                                    qstate=mysql_query(conn,q );

                                         if(!qstate){
                                                 query="INSERT INTO totalItems (Item_CATEGORY,PRICE,LAST_ISSUED_ID) VALUES ('"+ItemType+"','"+price+"','"+curr_valid_id+"')";

                                                    q=query.c_str();

                                                    qstate=mysql_query(conn,q );
                                                    mysql_close(conn);
                                            }
                                            else{
                                                cout<<"\n"<<mysql_error(conn)<<"\n";
                                                mysql_close(conn);
                                            }
                    }
                    else{
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                        mysql_close(conn);
                    }
                }
                else{
                    cout<<"\n"<<mysql_error(conn)<<"\n";
                }
}
