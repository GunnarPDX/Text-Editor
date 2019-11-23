// Carl Gunnar Rosenberg


#ifndef TREE_H
#define TREE_H

#include "Inheritance.h"

#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;


class Node {
public:
    Node(); //constructors
    Node(const Node & obj);

    ~Node(); //destructor

    //getters and setters
    Reserved *& getData1();
    void setData1(Reserved *& newData);

    Reserved *& getData2();
    void setData2(Reserved *& newData);
    void nullifyData2();
    bool isData2();

    Node *& getLeft();
    void setLeft(Node * newNode);

    Node *& getMiddle();
    void setMiddle(Node * newNode);

    Node *& getRight();
    void setRight(Node * newNode);

protected:
    Reserved * data1; //data 1 ptr
    Reserved * data2; //data 2 ptr

    Node * left; //left ptr
    Node * middle; //middle ptr
    Node * right; //right ptr

};

class Tree {
public:
    Tree(); //constructor
    ~Tree(); //destructor

    void display(); //display all method
    void insert(Reserved * obj); //insert wrapper
    void removeAll(); //remove all wrapper
    int search(String input); //return default white if no match is found

protected:
    Node * root; //root ptr
    Colors color; //color obj, contains highlight colors

    void display(Node * root); //display all method
    void removeAll(Node *& root); //remove all method
    void insert(Node * & root, Reserved * obj); //2-3 insert
    void insertLeft(Node * & root, Reserved * obj); //left branch insert
    void insertRight(Node * & root, Reserved * obj); //right branch insert
    int search(Node * root, String input); //search func, returns highlight color

};

#endif
