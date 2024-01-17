#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#include "header.h"

using namespace std;

bool ControlStudent::open(){

    Login myLogin;
    return myLogin.open(this->student);

}
