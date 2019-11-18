// Carl Gunnar Rosenberg
// CS 202
//

#include "Inheritance.h"

//Reserved class methods

Reserved::Reserved()
{
    characters = NULL;
}

Reserved::Reserved(const String &input) : characters(input){}

Reserved::~Reserved(){}

void Reserved::print(){}

void Reserved::highlight(){}

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

Word::Word() : Reserved(){}

Word::Word(const String & input) : Reserved(input){}

Word::~Word(){}

void Word::print()
{
    cout << "\x1B[" << highlight << "m" << characters <<"\033[0m\t\t" << endl;
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
    cout << "\x1B[" << highlight << "m" << characters <<"\033[0m\t\t" << endl;
}

//Comment class methods

Comment::Comment() : Reserved() {}

Comment::Comment(String input) : Reserved(input) {}

Comment::~Comment(){}

void Comment::print()
{
    cout << "\x1B[" << highlight << "m" << characters <<"\033[0m\t\t" << endl;
}