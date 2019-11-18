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

void Tree::insert(Reserved * obj)
{
    if(!root) //if root is empty
    {
        root = new Node();
        root->setData1(obj);
        return;
    }
    if(!root->getLeft() && !root->getMiddle() && !root->getRight()) //if no children
    {
        if(!root->isData2()) //if no second data member
        {
            if(root->getData1() < obj) //if root is smaller
            {
                root->setData2(obj);
                return;
            }
            else //else switch data to correct sides
            {
                root->setData2(root->getData1());
                root->setData1(obj);
                return;
            }
        }
        else //else push nodes down
        {
            if(obj > root->getData1())
            {
                Node * temp = new Node;
                root->setLeft(temp);
                temp->setData1(root->getData1());

                if(obj > root->getData2())
                {
                    Node * temp2 = new Node;
                    root->setRight(temp2);
                    temp2->setData1(obj);

                    root->setData1(root->getData2());
                }
                else
                {
                    //set data1 to obj
                    //set right to data 2
                }
                //delete data 2
                return;
            }
            else
            {
                //set left to obj
                //set right to data2
                //delete data2
            }
        }
    }
    if(!root->getMiddle()) //if no middle
    {
        //if 1 or 2 data members in node
            //if 1 then move data so that there are 2 in any node
            //else push new middle

        //if

    }

    return;
}