// Carl Gunnar Rosenberg
// CS 202
//

#ifndef INHERITANCE_H
#define INHERITANCE_H
#include "String.h"
#include <cstring>

class Colors {
public:
    const int WHITE = 30; //highlight colors
    const int RED = 31;
    const int GREEN = 32;
    const int YELLOW = 33;
    const int BLUE = 34;
    const int PURPLE = 35;
    const int CYAN = 36;
    const int GREY = 37;

    int colorPicker(); //returns a color
};

class Reserved {
public:
    Reserved(); //constructors
    Reserved(const String & input);
    Reserved(const Reserved & obj);
    virtual ~Reserved(); //destructor

    virtual void print() = 0; //pure virtual func
    int getHighlight();
    String getCharacters();

    //overloaded operators
    bool operator > (const Reserved & obj) const; //checks if data is larger for 2-3 tree...
    bool operator < (const Reserved & obj) const; //these all just do what the operators normally do
    bool operator >= (const Reserved & obj) const;
    bool operator <= (const Reserved & obj) const;
    bool operator == (const Reserved & obj) const;
    bool operator != (const Reserved & obj) const;

protected:
    Colors color; //color obj
    String characters; //reserved characters
    int highlight; //highlight color
};

class Word : public Reserved { // ex : "if" "return" "int" "char" "false" etc...
public:
    Word(); //constructor
    Word(const String & input); //copy constructor

    ~Word(); //destructor

    void print(); //display method

private:

};

class Symbol : public Reserved { // ex : ; + - = == != && etc...
public:
    Symbol(); //constructors
    Symbol(const String & input, int color);

    ~Symbol(); //destructor

    void print(); //display method
    int getColor(int input); //color selector

private:

};

class Comment : public Reserved { // can be : " //... " or " /* ... */ "
public:
    Comment(); //constructor
    Comment(String input);
    //Comment(int size); //length of comment, not used

    ~Comment(); //destructor

    void print(); //display mehtod

private:

};


#endif
