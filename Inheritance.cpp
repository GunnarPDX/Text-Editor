// Carl Gunnar Rosenberg
// CS 202
//
// inheritance.cpp
// this file contains all of the reserved class and color class methods

#include "Inheritance.h"


//color class methods



int Colors::colorPicker()
{
    cout << endl
         << "  -Select a Color-    " << endl
         << "\x1B[" << 30 << "m" << "1  = White" << "\033[0m" << endl
         << "\x1B[" << 31 << "m" << "2  = Red" << "\033[0m" << endl
         << "\x1B[" << 32 << "m" << "3  = Green" << "\033[0m" << endl
         << "\x1B[" << 33 << "m" << "4  = Yellow" << "\033[0m" << endl
         << "\x1B[" << 34 << "m" << "5  = Blue" << "\033[0m" << endl
         << "\x1B[" << 35 << "m" << "6  = Purple" << "\033[0m" << endl
         << "\x1B[" << 36 << "m" << "7  = Cyan" << "\033[0m" << endl
         << "\x1B[" << 37 << "m" << "8  = Grey" << "\033[0m" << endl
            << "Enter your selection: ";

    int input = 0;
    cin >> input;
    cin.ignore(100, '\n');
    cin.clear();
    if(input < 1 || input > 8)
    {
        cout << " Invalid Entry " << endl;
        return 1;
    }
    else return input;
}



//Reserved class methods



Reserved::Reserved()
{
    characters = NULL;
}

Reserved::Reserved(const String &input) : characters(input){}

Reserved::Reserved(const Reserved & obj) : characters(obj.characters){}

Reserved::~Reserved(){}

void Reserved::print(){}

int Reserved::getHighlight()
{
    return highlight;
}

String Reserved::getCharacters()
{
    return characters;
}

bool Reserved::operator > (const Reserved & obj)const
{
    if(this == & obj) return true;
    if (this->characters > obj.characters) return true;
    else return false;
}

bool Reserved::operator < (const Reserved & obj)const
{
    if(this == & obj) return true;
    if (this->characters < obj.characters) return true;
    else return false;
}

bool Reserved::operator >= (const Reserved & obj)const
{
    if(this == & obj) return true;
    if (this->characters >= obj.characters) return true;
    else return false;
}

bool Reserved::operator <= (const Reserved & obj)const
{
    if(this == & obj) return true;
    if (this->characters <= obj.characters) return true;
    else return false;
}

bool Reserved::operator == (const Reserved & obj)const
{
    if(this == & obj) return true;
    if (this->characters == obj.characters) return true;
    else return false;
}

bool Reserved::operator != (const Reserved & obj)const
{
    if(this == & obj) return true;
    if (this->characters != obj.characters) return true;
    else return false;
}



//Word class methods



Word::Word() : Reserved()
{
    highlight = color.GREEN;
}

Word::Word(const String & input) : Reserved(input)
{
    highlight = color.GREEN;
}

Word::~Word(){}

void Word::print()
{
    cout << "\x1B[" << highlight << "m" << characters <<"\033[0m" << endl;
}



//Symbol class methods



Symbol::Symbol() : Reserved()
{
    highlight = color.WHITE;
}

Symbol::Symbol(const String & input, int colorInput) : Reserved(input)
{
    highlight = getColor(colorInput);
}

int Symbol::getColor(int input)
{
    switch(input) {
        case 1: {return color.WHITE;}
        case 2: {return color.RED;}
        case 3: {return color.GREEN;}
        case 4: {return color.YELLOW;}
        case 5: {return color.BLUE;}
        case 6: {return color.PURPLE;}
        case 7: {return color.CYAN;}
        case 8: {return color.GREY;}
        default: return color.WHITE;
    }
    return color.WHITE;
}

Symbol::~Symbol(){}

void Symbol::print()
{
    cout << "\x1B[" << highlight << "m" << characters <<"\033[0m" << endl;
}



//Comment class methods



Comment::Comment() : Reserved()
{
    highlight = color.GREY;
}

Comment::Comment(String input) : Reserved(input)
{
    highlight = color.GREY;
}

Comment::~Comment(){}

void Comment::print()
{
    cout << "\x1B[" << highlight << "m" << characters <<"\033[0m" << endl;
}