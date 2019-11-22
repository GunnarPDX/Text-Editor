// Carl Gunnar Rosenberg
// CS 202
//
// String.cpp
//
// A string class based off of Karla's "kstring" demo class

#include "String.h"

String::String(): string(NULL), length(0) {}

String::String(const String & input)
{
    length = input.length;
    string = new char[length + 1];
    strcpy(string, input.string);
}

String::~String()
{
    delete [] string;
    string = NULL;
    length = 0;
}

String & String::operator = (const String & obj)
{
    if(this == & obj) return *this;

    delete [] string;
    length = obj.length;
    string = new char[length + 1];
    strcpy(string, obj.string);
    return *this;
}

bool String::operator > (const String & obj)const
{
    if(strcmp(this->string, obj.string) > 0)
    {
        return true;
    }
    else return false;
}

bool String::operator < (const String & obj)const
{
    if(strcmp(this->string, obj.string) < 0) return true;
    else return false;
}

bool String::operator <= (const String & obj)const
{
    if(strcmp(this->string, obj.string) <= 0) return true;
    else return false;
}

bool String::operator >= (const String & obj)const
{
    if(strcmp(this->string, obj.string) >= 0) return true;
    else return false;
}

bool String::operator == (const String & obj)const
{
    if(strcmp(this->string, obj.string) == 0) return true;
    else return false;
}

bool String::operator != (const String & obj)const
{
    if(strcmp(this->string, obj.string) != 0) return true;
    else return false;
}

String & String::operator = (const char * input)
{
    if(string) delete [] string;

    length = strlen(input);
    string = new char[length + 1];
    strcpy(string, input);
    return *this;
}

ostream & operator << (ostream & obj1, const String & obj2)
{
    obj1 << obj2.string;
    return obj1;
}


istream & operator >> (istream & obj1, String & obj2)
{
    char temp[100];
    obj1 >> temp;
    if(obj2.string) delete [] obj2.string;
    obj2.length = strlen(temp);
    obj2.string = new char[obj2.length + 1];
    strcpy(obj2.string, temp);
    return obj1;
}

char * String::getStr()
{
    return string;
}