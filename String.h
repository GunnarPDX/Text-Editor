// Carl Gunnar Rosenberg
// CS 202
//
// String.h
//
// A string class based off of Karla's "kstring" demo class

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class String
{
public:
    String();
    String(const String &);
    ~String();
    String & operator = (const String &);
    String & operator = (const char *);
    friend ostream & operator << (ostream &, const String &);
    friend istream & operator >> (istream &, String &);


private:
    char * string;
    int length;

};


#endif
