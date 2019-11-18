// Carl Gunnar Rosenberg
// CS 202
//

#ifndef TREE_H
#define TREE_H

#include "Inheritance.h"


class Node {
public:
    Node();
    Node(const Node & obj);
    Node(Reserved * obj);

    ~Node();

    //getters and setters

    Reserved *& getData1();
    void setData1(Reserved *& newData);

    Reserved *& getData2();
    void setData2(Reserved *& newData);

    Node *& getLeft();
    void setLeft(Node * newNode);

    Node *& getMiddle();
    void setMiddle(Node * newNode);

    Node *& getRight();
    void setRight(Node * newNode);

protected:
    Reserved * data1;
    Reserved * data2;

    Node * left;
    Node * middle;
    Node * right;

};

class Tree {
public:
    Tree();
    ~Tree();

    int display();
    bool insert(Reserved * obj);
    void removeAll();

protected:
    Node * root;

};

#endif
