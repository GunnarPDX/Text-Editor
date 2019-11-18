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

/*
Node::Node(Reserved * obj) // ?
{
    if(!data1) data1 = obj;
    else if(!data2) data2 = obj; // ?

    left = NULL;
    middle  = NULL;
    right  = NULL;
}
*/

Node::~Node()
{
    if(data1) delete data1;
    data1 = NULL;
    if(data2) delete data2;
    data2 = NULL;

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

bool Node::isData2()
{
    return data2 != NULL;
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
    root = NULL;
}

Tree::~Tree()
{
    removeAll();
    root = NULL;
}

void Tree::display()
{
    display(root);
}

void Tree::display(Node * root)
{
    if(!root) return;
    display(root->getLeft());
    display(root->getMiddle());
    display(root->getRight());

    root->getData1()->print();
    if(root->isData2())root->getData2()->print();
}

bool Tree::insert(Reserved * obj)
{

}

void Tree::removeAll()
{
    removeAll(root);
    root = NULL;
}

void Tree::removeAll(Node * root)
{
    if(!root) return;
    removeAll(root->getLeft());
    removeAll(root->getMiddle());
    removeAll(root->getRight());

    root->setLeft(NULL);
    root->setMiddle(NULL);
    root->setRight(NULL);
    delete root;
    root = NULL;
}