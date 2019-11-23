// Carl Gunnar Rosenberg


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
    char * getStr();


private:
    char * string;
    int length;

};


#endif
