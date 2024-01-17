#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;

bool OutstandingItems::removeOutStanding(string Items, Student student) {

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
                query="SELECT * FROM outstandingItems WHERE ROLL_NUMBER='"+student.getRoll()+"' AND Item_CATEGORY= '"+Items+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q);
                    if(!qstate){
                                res=mysql_store_result(conn);
                                int x=mysql_num_rows(res);
                                if(x>0){
                                        mysql_close(conn);
                                    return 1;
                                }
                                else{
                                    mysql_close(conn);
                                    return 0;
                                }
                        }
                        else{
                            mysql_close(conn);
                            return 0;
                        }
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
            return 0;
        }


}



void OutstandingItems::addToOutStandingData(vector<string> Items, vector<string> ItemId, Student student,
                                                 vector<string> date) {
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
                for(int i=0;i<ItemId.size();i++){
                    query="INSERT INTO outstandingItems ( Item_CATEGORY,Item_ID,STUDENT_NAME,ROLL_NUMBER,ISSUE_DATE,RETURN_DATE) VALUES('"+Items[i]+"','"+ItemId[i]+"','"+student.getName()+"','"+student.getRoll()+"','"+date[i]+"','"+returnDate(date[i])+"')";
                    q=query.c_str();
                    qstate=mysql_query(conn,q);
                }
                mysql_close(conn);
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
        }
}

void OutstandingItems::getListOfOtstanding(string & Item, vector<string>& ItemId, vector<string>& roll,
                                                vector<string>& issueDate, vector<string>& returnDate) {


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
                query="SELECT * FROM outstandingItems WHERE Item_CATEGORY='"+Item+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q);
                if(!qstate){
                            res=mysql_store_result(conn);
                            int x=mysql_num_rows(res);

                            while(x--){
                                row=mysql_fetch_row(res);
                                ItemId.push_back(row[1]);
                                roll.push_back(row[3]);
                                issueDate.push_back(row[4]);
                                returnDate.push_back(row[5]);
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

void OutstandingItems::removeFromOutStanding(vector<string> ItemId) {


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
            for(int i=0;i<ItemId.size();i++){
                query="DELETE FROM outstandingItems WHERE Item_ID='"+ItemId[i]+"'";

                q=query.c_str();
                qstate=mysql_query(conn,q);
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

void OutstandingItems::getCompleteList(vector<string> &Items, vector<string> &ItemId, vector<string> &roll,
                                            vector<string> &issueDate, vector<string> &returnDate) {

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
                    query="SELECT * FROM outstandingItems ";

                     q=query.c_str();
                     qstate=mysql_query(conn,q);
                     if(!qstate){
                                 res=mysql_store_result(conn);
                                 int x=mysql_num_rows(res);
                                 while(x--){
                                    row=mysql_fetch_row(res);
                                    Items.push_back(row[0]);
                                    ItemId.push_back(row[1]);
                                    roll.push_back(row[3]);
                                    issueDate.push_back(row[4]);
                                    returnDate.push_back(row[5]);
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

string  OutstandingItems::getTodayDate() {

      time_t now = time(0);
      tm *ltm = localtime(&now);

       int y=1900+(ltm->tm_year);
       int m=1+(ltm->tm_mon);
       int d=(ltm->tm_mday);

    return toString(y)+"-"+toString(m)+"-"+toString(d);

}


int OutstandingItems::issuedByStudent(Student student){

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
                query="SELECT * FROM outstandingItems WHERE ROLL_NUMBER='" +student.getRoll()+"'";

                 q=query.c_str();
                 qstate=mysql_query(conn,q);
                    if(!qstate){
                             res=mysql_store_result(conn);
                             if(mysql_num_rows(res)>0){int x=mysql_num_rows(res);
                             mysql_close(conn);
                                return x;
                             }
                             else{
                                    mysql_close(conn);
                                return 0;
                             }
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
 int OutstandingItems::to_integer(string s){
                int sum=0;
                for(int i=0;i<s.size();i++){
                    sum*=10;
                    sum+=s[i]-'0';
                }
                return sum;
              }





string OutstandingItems::toString(int x){
    int t=x;
    string s="";
    while(x){
    s+='0'+(x%10);
        x/=10;
        }
    if(t<10){string t="0";t+=s;
            return t;
        }
    reverse(s.begin(),s.end());
        return s;
    }


string OutstandingItems::returnDate(string date){
                         int y=to_integer(date.substr(0,4));
                         int m=to_integer(date.substr(5,2));
                         int d=to_integer(date.substr(8,2));


                            tm t = {};
                            t.tm_year = y-1900;
                            t.tm_mon  = m-1;
                            t.tm_mday = d;

                            t.tm_mday += 2;
                            mktime(&t);

                            string ans="" ;
                            ans+=toString(t.tm_year+1900);
                            ans+='-';
                            ans+=toString(1+t.tm_mon);
                            ans+='-';
                            ans+=toString(t.tm_mday);
                        return ans;
    }

string OutstandingItems::getId(string ItemCategory, Student student){
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    string  val;

    const char* q;
    conn=mysql_init(0);
    if(conn){
                 conn=mysql_real_connect(conn,"sql6.freesqldatabase.com","sql6412395","RCMdFqCyxZ","sql6412395",0,NULL,0);

                query="SELECT * FROM outstandingItems WHERE ROLL_NUMBER='" +student.getRoll()+"' AND Item_CATEGORY='"+ItemCategory+"'";

                 q=query.c_str();
                 qstate=mysql_query(conn,q);
                    if(!qstate){
                             res=mysql_store_result(conn);

                              int x=mysql_num_rows(res);
                              if(x>0){
                                row=mysql_fetch_row(res);
                                string x=row[1];
                                mysql_close(conn);
                                return x;
                              }
                              else{
                                    mysql_close(conn);
                                return NULL;
                              }
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

int OutstandingItems::additionalDays(string ItemId){

    string today=getTodayDate();
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
                query="SELECT * FROM outstandingItems WHERE Item_ID='" +ItemId+"'";
                 q=query.c_str();
                 qstate=mysql_query(conn,q);
                        if(!qstate){
                                     res=mysql_store_result(conn);
                                     int x=mysql_num_rows(res);
                                     if(x>0){
                                            row=mysql_fetch_row(res);
                                            string date=row[4];
                                            int count=0;
                                            string ans=date.substr(0,10) ;
                                            while(ans!=today){
                                                         int y=to_integer(date.substr(0,4));
                                                         int m=to_integer(date.substr(5,2));
                                                         int d=to_integer(date.substr(8,2));
                                                            tm t = {};
                                                            t.tm_year = y-1900;
                                                            t.tm_mon  = m-1;
                                                            t.tm_mday = d;
                                                            t.tm_mday += 1;
                                                            mktime(&t);
                                                            ans=toString(t.tm_year+1900);
                                                            ans+='-';
                                                            ans+=toString(1+t.tm_mon);
                                                            ans+='-';
                                                            ans+=toString(t.tm_mday);
                                                            date=ans;
                                                            count++;
                                            }
                                            mysql_close(conn);
                                        if(count>2){return count-2;}
                                        else{return 0;}
                                     }
                                     else{
                                        mysql_close(conn);
                                        return 0;
                                     }

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
