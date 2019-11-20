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
    String(const String & obj);
    ~String();
    String & operator = (const String & obj);
    String & operator = (const char * input);
    bool operator > (const String & obj)const;
    bool operator < (const String & obj)const;
    bool operator >= (const String & obj)const;
    bool operator <= (const String & obj)const;
    bool operator == (const String & obj)const;
    bool operator != (const String & obj)const;
    friend ostream & operator << (ostream & obj1, const String & obj2);
    friend istream & operator >> (istream & obj1, String & obj2);
    char * operator [] (int i);


private:
    char * string;
    int length;

};


#endif
