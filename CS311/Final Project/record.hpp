/*
 AlligatorTaffy
 Final Project - Media Collection Database
 record.hpp - Class with Function Declarations for record.cpp
 
 Description of the Problem:
 User has various quantities of diverse media types (Videos, Music, and Games).
 A program was needed to help create and inventory based upon the most popular 
 media in possesion.  The database helps organize and record what media is actually
 owned.
 
 Pseudo Code:
 Data:
    int mediaType = Used to identifythe types of media stored. (1 = Music, 2 = Video, 3 = Game)
    string console = Used solely for Games. Identifies what console the game is for
    string title = Universal. Contains the title of media being stored
    string artist = Used solely for Music. Identifies who the artist is of the album 
    string genre = Universal. Contains the kind of genre each piece of media falls into
    string developer = Used solely for Games. Identifies the developer of the software
    string publisher = Universal. Contains the producer/publisher of the media
    int yearPub = Universal. Contains the year in which the media was released
    string format = Universal. Contains various types of formats (CD, DVD, VHS, ...)
    int discNum = Dependent on if the media is Disc based.  Stores number of discs
    int review = Universal.  User based review score out of 10
    int datNum = Universal.  Counter to make unique database entries so that each piece
                of media can be searchable/modified/deleted
 
 Constructors:
    Default Constructor - sets the data in record object to 0 and NULL
    Overloaded Constructor - accepts passed values to assign values to media object
    Default Destructor - Deletes the class object instance
 
 Accessor Functions:
    static int getYear - static function to return value of 'yearPub'
    static string getPublisher - static function to return value of 'publisher'
    static int getReview - static function to return value of 'review'
    static string getArtist - static function to return value of 'artist'
    static string getConsole - static function to return value of 'console'
    static string getGenre - static function to return value of 'genre'
    static int getMediaType - static function to return value of 'mediaType'
    static int getDatNum - static function to return value of 'datNum'

 Member Functions:
    static void displayItem - static function to return contents of media object based on mediaType
    friend ostream& operator<< - Displays the raw contents of the media object
    static Record addEntry - Creates a new media object based upon user given parameters
*/

#ifndef __RECORD_HPP__
#define __RECORD_HPP__

#include <iostream>
#include <string>
using namespace std;

class Record {
private:
    // Private Variables
    int mediaType;
    string console;
    string title;
    string artist;
    string genre;
    string developer;
    string publisher;
    int yearPub;
    string format;
    int discNum;
    int review;
    int datNum;
public:
    // Constructors
    Record();
    Record(int a, string b, string c, string d, string e, string f, string g, int h, string j, int k, int l, int m);
    ~Record();
    // Member Functions
    static int getYear(Record &a);
    static string getPublisher(Record &a);
    static int getReview(Record &a);
    static string getArtist(Record &a);
    static string getConsole(Record &a);
    static string getGenre(Record &a);
    static int getMediaType(Record &a);
    static int getDatNum(Record &a);
    static void displayItem(Record &a);
    friend ostream& operator<<(ostream &os, const Record &a);
    static Record addEntry();
};

#endif