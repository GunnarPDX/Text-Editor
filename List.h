// Carl Gunnar Rosenberg
// CS 202
//

#ifndef LIST_H
#define LIST_H

#include "String.h"
#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;

class Text {
public:
    Text();
    Text(const String & word, int highlight);
    Text(const Text & obj);
    ~Text();

    void print();
    void setHighlight(int color);

private:
    String word;
    int highlight;
};

class ListNode {
public:
    ListNode();
    ListNode(const ListNode & obj);
    ListNode(Text * obj);
    ~ListNode();

    ListNode *& getNext();
    void setNext(ListNode * newNode);
    ListNode *& getPrevious();
    void setPrevious(ListNode * newNode);
    Text *& getData();
    void setData(Text *& newData);

private:
    ListNode * next;
    ListNode * previous;
    Text * data;
};

class List {
public:
    List(int size);
    ~List();

    bool insert(int i, Text * obj);
    void removeAll();
    void removeAllLoop(int i);
    void display();

private:
    int size;
    ListNode ** head;

    bool insert(ListNode *& head, Text * obj);
    void deleteAll(ListNode *& head);
    void removeAll(ListNode * & head);
    void displayLoop(int i);
    void display(ListNode * head);

};


#endif
