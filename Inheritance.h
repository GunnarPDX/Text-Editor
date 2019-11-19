// Carl Gunnar Rosenberg
// CS 202
//

#ifndef INHERITANCE_H
#define INHERITANCE_H
#include "String.h"
#include <cstring>

class Colors {
public:
    const int WHITE = 30;
    const int RED = 31;
    const int GREEN = 32;
    const int YELLOW = 33;
    const int BLUE = 34;
    const int PURPLE = 35;
    const int CYAN = 36;
    const int GREY = 37;
};

class Reserved {
public:
    Reserved();
    Reserved(const String & input);
    Reserved(const Reserved & obj);
    virtual ~Reserved();

    virtual void print() = 0; //pure virtual func

    bool operator > (const Reserved & obj) const;
    bool operator < (const Reserved & obj) const;
    bool operator >= (const Reserved & obj) const;
    bool operator <= (const Reserved & obj) const;
    bool operator == (const Reserved & obj) const;
    bool operator != (const Reserved & obj) const;

protected:
    Colors color;
    String characters;
    int highlight;
};

class Word : public Reserved { // ex : "if" "return" "int" "char" "false" etc...
public:
    Word();
    Word(const String & input);
    ~Word();

    void print();

private:

};

class Symbol : public Reserved { // ex : ; + - = == != && etc...
public:
    Symbol();
    Symbol(const String & input, int color);

    ~Symbol();

    void print();
    int getColor(int input);

private:

};

class Comment : public Reserved { // can be : " //... " or " /* ... */ "
public:
    Comment();
    Comment(String input);
    Comment(int size);

    ~Comment();

    void print();

private:

};


#endif
