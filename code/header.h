#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<mysql.h>
#include<bits/stdc++.h>
#ifndef UNTITLED_ITEMCONTROLLER_H
#define UNTITLED_ITEMCONTROLLER_H
#ifndef UNTITLED_APPLICATION_H
#define UNTITLED_APPLICATION_H
#ifndef UNTITLED_AVAILABLEITEMS_H
#define UNTITLED_AVAILABLEITEMS_H
#ifndef UNTITLED_WATCHMAN_H
#define UNTITLED_WATCHMAN_H
#ifndef UNTITLED_OUTSTANDINGITEMS_H
#define UNTITLED_OUTSTANDINGITEMS_H
#ifndef UNTITLED_SECRETARYCONTROLLER_H
#define UNTITLED_SECRETARYCONTROLLER_H
#ifndef UNTITLED_SECRETARYHOMEPAGECONTROLLER_H
#define UNTITLED_SECRETARYHOMEPAGECONTROLLER_H
#ifndef UNTITLED_SECRETARYLOGINCONTROLLER_H
#define UNTITLED_SECRETARYLOGINCONTROLLER_H
#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#ifndef UNTITLED_STUDENTCONTROLLER_H
#define UNTITLED_STUDENTCONTROLLER_H
#ifndef UNTITLED_ControlDuesOfStudent_H
#define UNTITLED_ControlDuesOfStudent_H
#ifndef UNTITLED_STUDENTHOMAPAGECONTROLLER_H
#define UNTITLED_STUDENTHOMAPAGECONTROLLER_H
#ifndef UNTITLED_ItemIssue_H
#define UNTITLED_ItemIssue_H
#ifndef UNTITLED_Login_H
#define UNTITLED_Login_H
#ifndef UNTITLED_ReturnItem_H
#define UNTITLED_ReturnItem_H
#ifndef UNTITLED_TOTALITEMS_H
#define UNTITLED_TOTALITEMS_H
#ifndef UNTITLED_VIEWBYAVAILABILITYCONTROLLER_H
#define UNTITLED_VIEWBYAVAILABILITYCONTROLLER_H
#ifndef UNTITLED_VIEWBYCATEGORYCONTROLLER_H
#define UNTITLED_VIEWBYCATEGORYCONTROLLER_H
#ifndef UNTITLED_VIEWBYOUTSTANDINGCONTROLLER_H
#define UNTITLED_VIEWBYOUTSTANDINGCONTROLLER_H
#ifndef UNTITLED_VIEWDETAILSCONTROLLER_H
#define UNTITLED_VIEWDETAILSCONTROLLER_H
#ifndef UNTITLED_VIEWControlDuesOfStudent_H
#define UNTITLED_VIEWControlDuesOfStudent_H
class ItemAdding {
public:
    bool open();
    void getItemList(vector<string> &itemCategory);
    void showItemList(vector<string> itemCategory);
    void showMesage(string message, int pause);
    int getValidInput(int n);
    int getQuantity();
    string getId();
    void ITEM(string item,vector<string> itemId);
    bool logout();
    bool backToHomePage();
};
class Application {
public:
    void open();
    void showApplicationHome();
    int getValidInput();
};
class AvailableItems {
public:
    void removeFromData(vector<string> itemsId);
    int itemAvailable(string item);
    void addToAvailableData(vector<string> items,vector<string> itemId);
    void addItem(string item,vector<string> equimentId);
    void getCompleteList(vector<string> &itemCategory,vector<int> &itemCount);
    string getId(string item);
};
class Watchman {
    public:
    bool verifyWatchman(string password);
};
class OutstandingItems {
public:
    bool removeOutStanding(string items,Student student);
    void addToOutStandingData(vector<string> items,vector<string> itemId,Student student,vector<string> date);
    void getListOfOtstanding(string & item,vector<string> & itemId,vector<string> & roll,vector<string> & issueDate,vector<string> & returnDate);
    void removeFromOutStanding(vector<string> itemId);
    void getCompleteList(vector<string> &items,vector<string> &itemId,vector<string> &roll,vector<string> &issueDate,vector<string> &returnDate);
    string getTodayDate();
    int issuedByStudent(Student student);
    int to_integer(string s);
    string toString(int x);
    string returnDate(string date);
    string getId(string itemCategory, Student student);
    int additionalDays(string itemId);
};
class SecretaryController {
    Student secretary;
public:
    bool open();
};
class SecretaryHomePageController : public HomepageStudent {
public:
    bool open(Student secretary);
    void showSecretaryHomePage();
    int getValidInput();
    bool viewDetails();
    bool viewDuesOfStudent();
    bool addItem();
};
class SecretaryLoginController {
public:
    bool open(Student secretary);
    void showSecretaryLogin(string show);
    bool loginSuccess(Student secretary);
    bool loginFail(Student secretary);
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
class ControlStudent {
    Student student;
public:
    bool open();
};
class ControlDuesOfStudent {
public:
    bool open(Student student);
    void showStudentDues(double dues);
    int getValidInput();
    double getAmountToPay(double dues);
    void payDues(Student student);
    bool logout();
    bool backToHomepage();

};
class HomepageStudent {
public:
    bool open(Student student);
    void showStudentHomePage();
    int getVaildInput();
    bool issueitem(Student student);
    bool returnItem(Student student);
    bool checkDues(Student student);
    bool logout();
    bool exit();

};
class ItemIssue {
public:
    bool open(Student student);
    bool checkDue(Student student);
    void showMessage(string show);
    int getValidInput(int n);
    bool canIssue(Student student);
    void showItemList(vector<string>itemCategory);
    void showFinalItemsList(vector<string> itemCategory);
    void getAvailableItems(vector<string>&itemCategory, Student student);
    void getItemData(vector<string>&itemCategory, vector<string> &itemId, vector<string> &issueDate);
    bool watchmanVerification();
    void changeItemData(vector<string> itemCategory, vector<string> itemId, Student student, vector<string>Date);
    bool logout();
    bool backToHomepage();
};
class Login {

public:
    bool open(Student student);
    void showStudentLogin(string show);
    bool loginSuccess(Student student);
    bool loginFail(Student student);

};
class ReturnItem {
public:
    bool open(Student student);
    void showMessage(string show);
    void showItemList(vector<string>itemCategory);
    void getItemList(vector<string> &itemCatgeory, Student student);
    string getItemDetails(string itemsCategory, Student student);
    void removeFromOutstanding(string itemId);
    void addToAvailable(string itemCatgeory, string itemId);
    void addDues(Student student, int damaged, string itemId, string itemCategory);
    bool watchmanVerificatiion();
    bool logout();
    bool backToHomePage();
    int getValidInput(int n);
};
class TotalItems {
public:
    void totalItems();
    void getItemList(vector<string> &items);
    double getPrice(string item);
    string validId();
    void updateId(string itemcategory);
};
class ViewByAvailabilityController {
public:
    bool open();
    void getAvailabilityList(vector<string> &itemCategory,vector<int> &itemCount);
    void showItemList(vector<string> ItemCategory,vector<int> ItemCount);
    bool logout();
    int getValidInput();
    bool goBackToViewDetails();
};
class ViewByCategoryController {
public:
    bool open();
    void showList(vector<string>ItemCategory);
    int getValidInput(int n);
    void getItemCategory(vector<string>&itemCategory);
    void showOutStanding(string itemCategory, vector<string>itemId ,vector<string>roll, vector<string> issueDate, vector<string> returnDate );
    void getOutStandingList(string item,vector< string > &itemId,vector<string > &roll ,vector<string> &issueDate,vector<string>&returnDate);
    int getAvailableList(string item);
    void showAvailableList(int count, string itemCategory);
    bool logout();
    bool goBackToViewDetails();
};
class ViewByOutstandingController {
public:
    bool open();
    void getOutstandingList(vector<string> &itemCategory, vector<string> &itemId, vector<string> &roll, vector<string> &issueDate, vector<string> &returnDate);
    void showOutStandingList(vector<string> itemCategory, vector<string> equimentId, vector<string> roll, vector<string> issueDate, vector<string> returnDate);
    bool  logout();
    bool goBackToViewDetails();
    int getValidInput();
};
class ViewDetailsController {
public:
    bool open();
    void showViewDetails();
    int getValidInput();
    bool viewByCategory();
    bool viewByOutstanding();
    bool viewByAvailability();
    bool logout();
    bool backToHomepage();
};
class ViewControlDuesOfStudent {
public:
    bool open();
    string getRollNumber();
    string getName(Student student);
    double getDues(Student student);
    void showMessage(string message);
    void showViewControlDuesOfStudent();
    int getValidInput(int n);
    bool goBackToHomePage();
    bool logout();
};


#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif