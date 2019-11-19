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

    ~Node();

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

    void display();
    void insert(Reserved * obj);
    void removeAll();

protected:
    Node * root;

    void display(Node * root);
    void removeAll(Node * root);
    void insert(Node * & root, Reserved * obj);
    void insertLeft(Node * & root, Reserved * obj);
    void insertRight(Node * & root, Reserved * obj);

};

#endif
