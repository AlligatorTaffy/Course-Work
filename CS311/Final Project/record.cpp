/*
 AlligatorTaffy
 Final Project - Media Collection Database
 record.cpp - Function Definitions for record.hpp
*/

#include "record.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// External Variable declarations from project.cpp
extern int databaseNum;

// Default Constructor setting all ints to 0 and strings to NULL
Record::Record() {
    mediaType = 0;
    console = "NULL";
    title = "NULL";
    artist = "NULL";
    genre = "NULL";
    developer = "NULL";
    publisher = "NULL";
    yearPub = 0;
    format = "NULL";
    discNum = 0;
    review = 0;
    datNum = 0;
}

// Overloaded Constructor that accepts various ints and strings to complete a full entry
Record::Record(int a, string b, string c, string d, string e, string f, string g, int h, string j, int k, int l, int m) {
    mediaType = a;
    console = b;
    title = c;
    artist = d;
    genre = e;
    developer = f;
    publisher = g;
    yearPub = h;
    format = j;
    discNum = k;
    review = l;
    datNum = m;
}

// Default Destructor
Record::~Record(){}

// Accessor Function to return value of private member yearPub
int Record::getYear(Record &a) {
    return a.yearPub;
}

// Accessor Function to return value of private member publisher
string Record::getPublisher(Record &a) {
    return a.publisher;
}

// Accessor Function to return value of private member review
int Record::getReview(Record &a) {
    return a.review;
}

// Accessor Function to return value of private member artist
string Record::getArtist(Record &a) {
    return a.artist;
}

// Accessor Function to return value of private member console
string Record::getConsole(Record &a) {
    return a.console;
}

// Accessor Function to return value of private member genre
string Record::getGenre(Record &a) {
    return a.genre;
}

// Accessor Function to return value of private member mediaType
int Record::getMediaType(Record &a) {
    return a.mediaType;
}

// Accessor Function to return value of private member datNum
int Record::getDatNum(Record &a) {
    return a.datNum;
}

// Member Function to Display contents of class object based upon mediaType
void Record::displayItem(Record &a) {
    if(a.mediaType == 1) {  // Music
        cout << "Media Type:: " << "Music" << endl;
        cout << "Album:: " << a.title << endl;
        cout << "Artist:: " << a.artist << endl;
        cout << "Genre:: " << a.genre << endl;
        cout << "Producer:: " << a.publisher << endl;
        cout << "Year Published:: " << a.yearPub << endl;
        cout << "Media Format:: " << a.format << endl;
        if(a.format == "cd" || a.format == "Cd" || a.format == "CD") {
            cout << "Number of Discs:: " << a.discNum << endl;
        } 
        cout << "Rating:: " << a.review << endl;
        cout << "Database #" << a.datNum << endl;
    }
    if(a.mediaType == 2) {  // Video
        cout << "Media Type:: " << "Video" << endl;
        cout << "Title:: " << a.title << endl;
        cout << "Genre:: " << a.genre << endl;
        cout << "Publisher:: " << a.publisher << endl;
        cout << "Year Published:: " << a.yearPub << endl;
        cout << "Media Format:: " << a.format << endl;
        if(a.format == "DVD" || a.format == "LaserDisc" || a.format == "Bluray" || a.format == "HDDVD") {
            cout << "Number of Discs:: " << a.discNum << endl;
        }
        cout << "Rating:: " << a.review << endl;
        cout << "Database #" << a.datNum << endl;
    }
    if(a.mediaType == 3) {  // Video Game
        cout << "Media Type:: " << "Game" << endl;
        cout << "System:: " << a.console << endl;
        cout << "Title:: " << a.title << endl;
        cout << "Genre:: " << a.genre << endl;
        cout << "Developer:: " << a.developer << endl;
        cout << "Publisher:: " << a.publisher << endl;
        cout << "Year Published:: " << a.yearPub << endl;
        cout << "Media Format:: " << a.format << endl;
        if(a.format == "Disc") {
            cout << "Number of Discs:: " << a.discNum << endl;
        }
        cout << "Rating:: " << a.review << endl;
        cout << "Database #" << a.datNum << endl;
    }
}

// Overloaded operator<< to display raw contents of each class object
ostream& operator<<(ostream &os, const Record &a) {
    os << a.mediaType << endl;
    os << a.console << endl;
    os << a.title << endl;
    os << a.artist << endl;
    os << a.genre << endl;
    os << a.developer << endl;
    os << a.publisher << endl;
    os << a.yearPub << endl;
    os << a.format << endl;
    os << a.discNum << endl;
    os << a.review << endl;
    os << a.datNum << endl;
    return os;
}

// Member function to create new member entries given various criterion chosen by the user
Record Record::addEntry() {
    int a = 0, h = 0, k = 0, l = 0;
    string b, c, d, e, f, g, j;
    cout << "What Type of Media is to be added?\n\t1.) Music Album\n\t2.) Video\n\t3.) Video Game\nChoose a number above:: ";
    cin >> a;
    databaseNum++;
    if(a < 1 || a > 3) {
        throw "Invalid_Number";
    }
    if(a == 1) {
        b = "NULL";
        cout << "Title of Album:: ";
        cin.ignore();
        getline(cin, c);
        cout << "Artist of Album:: ";
        getline(cin, d);
        cout << "Music Genre:: ";
        getline(cin, e);
        f = "NULL";
        cout << "Producer:: ";
        getline(cin, g);
        cout << "Year Published:: ";
        cin >> h;
        cout << "Media Format:: ";
        cin.ignore();
        getline(cin,j);
        if(j == "cd" || j == "Cd" || j == "CD") {
            cout << "How many discs:: ";
            cin >> k;
        } else {
            k = 0;
        }
        while(l < 1 || l > 10) {
            cout << "Enter a rating between 1-10:: ";
            cin >> l;
            if(l < 1 || l > 10) {
                cout << "Invalid Rating!\n\n";
            }
        }
    }
    if(a == 2) {
        b = "NULL";
        cout << "Title of Video:: ";
        cin.ignore();
        getline(cin, c);
        d = "NULL";
        cout << "Genre:: ";
        getline(cin, e);
        f = "NULL";
        cout << "Publisher:: ";
        getline(cin, g);
        cout << "Year Published:: ";
        cin >> h;
        cout << "Media Format(DVD/LaserDisc/Bluray/HDDVD/VHS/Betamax):: ";
        cin.ignore();
        getline(cin,j);
        if(j == "DVD" || j == "LaserDisc" || j == "Bluray" || j == "HDDVD") {
            cout << "How many discs:: ";
            cin >> k;
        } else {
            k = 0;
        }
        while(l < 1 || l > 10) {
            cout << "Enter a rating between 1-10:: ";
            cin >> l;
            if(l < 1 || l > 10) {
                cout << "Invalid Rating!\n\n";
            }
        }
    }
    if(a == 3) {
        cout << "What System:: ";
        cin.ignore();
        getline(cin, b);
        cout << "Title of Game:: ";
        getline(cin, c);
        d = "NULL";
        cout << "Genre of Game:: ";
        getline(cin, e);
        cout << "Developer of Game:: ";
        getline(cin, f);
        cout << "Publisher of Game:: ";
        getline(cin, g);
        cout << "Year Published:: ";
        cin >> h;
        cout << "Media Format(Digital/Cartridge/Disc):: ";
        cin.ignore();
        getline(cin,j);
        if(j == "Disc") {
            cout << "How many discs:: ";
            cin >> k;
        } else {
            k = 0;
        }
        while(l < 1 || l > 10) {
            cout << "Enter a rating between 1-10:: ";
            cin >> l;
            if(l < 1 || l > 10) {
                cout << "Invalid Rating!\n\n";
            }
        }
    }
    Record temp(a, b, c, d, e, f, g, h, j, k, l, databaseNum);
    return temp;
} 