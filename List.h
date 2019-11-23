// Carl Gunnar Rosenberg


#ifndef LIST_H
#define LIST_H

#include "String.h"
#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;

//text obj
class Text {
public:
    Text(); //default constructor
    Text(const String & word, int highlight); //constructor
    Text(const Text & obj); //copy constructor
    ~Text(); //destructor

    void print(); //display func
    void setHighlight(int color); //set the highlight color of text obj

private:
    String word; //an individual word
    int highlight; //highlight color for word
};

class ListNode {
public:
    ListNode(); //default constructor
    ListNode(const ListNode & obj); //copy constructor
    ListNode(Text * obj); //constructor
    ~ListNode(); //destructor

    ListNode *& getNext(); //next getter
    void setNext(ListNode * newNode); //next setter
    ListNode *& getPrevious(); //previous getter
    void setPrevious(ListNode * newNode); //previous setter
    Text *& getData(); //data getter
    void setData(Text *& newData); //data setter

private:
    ListNode * next; //next ptr
    ListNode * previous; //previous ptr
    Text * data; //data ptr
};

class List {
public:
    List(int size); //construtor
    ~List(); //destructor

    bool insert(int i, Text * obj); //insert function
    void removeAll(); //remove all wrapper
    void display(); //display all wrapper
    int getSize(); //size getter

private:
    int size; //size of table arr
    ListNode ** head; //head ptr

    bool insert(ListNode *& head, Text * obj);
    void deleteAll(ListNode *& head);
    void removeAll(ListNode * & head);
    void removeAllLoop(int i); //iterates through arr index
    void displayLoop(int i); //iterates ...
    void display(ListNode * head); //display all method

};


#endif
