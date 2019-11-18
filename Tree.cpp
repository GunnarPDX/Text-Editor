// Carl Gunnar Rosenberg
// CS 202
//

#include "Tree.h"

//Node class members

Node::Node()
{
    data1 = NULL;
    data2 = NULL;

    left = NULL;
    middle  = NULL;
    right  = NULL;
}

Node::Node(const Node & obj)
{
    data1 = obj.data1;
    data2 = obj.data2;

    left = NULL;
    middle  = NULL;
    right  = NULL;
}

Node::Node(Reserved * obj) // ?
{
    if(!data1) data1 = obj;
    else if(!data2) data2 = obj; // ?

    left = NULL;
    middle  = NULL;
    right  = NULL;
}

Node::~Node()
{
    if(data1) delete data1;
    data1 = NULL;
    if(data2) delete data2;

    left = NULL;
    middle  = NULL;
    right  = NULL;
}

Reserved *& Node::getData1()
{
    return data1;
}

void Node::setData1(Reserved *& newData)
{
    data1 = newData;
}

Reserved *& Node::getData2()
{
    return data2;
}

void Node::setData2(Reserved *& newData)
{
    data2 = newData;
}

Node *& Node::getLeft()
{
    return left;
}

void Node::setLeft(Node * newNode)
{
    left = newNode;
}

Node *& Node::getMiddle()
{
    return middle;
}

void Node::setMiddle(Node * newNode)
{
    middle = newNode;
}

Node *& Node::getRight()
{
    return right;
}

void Node::setRight(Node * newNode)
{
    right = newNode;
}

//Tree class members

Tree::Tree()
{

}

Tree::~Tree()
{

}

int Tree::display()
{

}

bool Tree::insert(Reserved * obj)
{

}

void Tree::removeAll()
{

}