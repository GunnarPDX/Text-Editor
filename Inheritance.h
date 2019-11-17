// Carl Gunnar Rosenberg
// CS 202
//

#ifndef INHERITANCE_H
#define INHERITANCE_H


class Reserved {
public:
    Reserved();
    virtual ~Reserved();

    virtual void print() = 0; //pure virtual func
    virtual char * highlight() = 0;

private:
    char * characters;
};

class Word : public Reserved {
public:
    Word();
    Word(int size);

    ~Word();

    void print();
    char * replace(char * input);

private:

};

class Symbol : public Reserved {
public:
    Symbol();
    Symbol(int size);

    ~Symbol();

    void print();
    char * replace(char * input);

private:

};

class Comment : public Reserved {
public:
    Comment();
    Comment(int size);

    ~Comment();

    void print();
    char * replace(char * input);

private:

};


#endif
