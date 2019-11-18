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

void Node::deleteData2()
{
    if(data2) delete data2;
    data2 = NULL;
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
    insert(root, obj);
}

void Tree::insert(Node * & root, Reserved * obj)
{
    if(!root) //if root is empty
    {
        root = new Node();
        root->setData1(obj);
    }
    else if(!root->getLeft() && !root->getMiddle() && !root->getRight()) //if no children
    {
        if(!root->isData2()) //if no second data member
        {
            if(root->getData1() < obj) //if root is smaller
            {
                root->setData2(obj);
            }
            else //else switch data to correct sides
            {
                root->setData2(root->getData1());
                root->setData1(obj);
            }
        }
        else //else push nodes down (root is full)
        {
            Node * temp = new Node;
            root->setLeft(temp);

            Node * temp2 = new Node;
            root->setRight(temp2);

            if(obj > root->getData1())
            {
                temp->setData1(root->getData1());

                if(obj > root->getData2())
                {
                    temp2->setData1(obj); //set right to data1
                    root->setData1(root->getData2()); //set data1 to data2
                }
                else
                {
                    temp2->setData1(root->getData2()); //set right to data2
                    root->setData1(obj); //set data 1 to obj
                }
            }
            else
            {
                temp->setData1(obj); //set left to obj
                temp->setData1(root->getData2()); //set right to data2
            }
            root->deleteData2(); //delete data 2
        }
    }
    else if(obj < root->getData1() && root->getLeft()) //if there are children and obj goes to left
    {
        if(root->getLeft()->isData2()) //if left is full
        {
            insertLeft(root, obj); //add to left / create middle
        }
        insert(root->getLeft(), obj); //add to left / traverse
    }
    else if(obj > root->getData1() && root->getRight()) //if there are children and obj goes to right
    {
        if(root->getRight()->isData2()) //if right is full
        {
            insertRight(root, obj); //add to right / create middle
        }
        insert(root->getRight(), obj); //add to right / traverse
    }
    else return;
}

void Tree::insertLeft(Node * & root, Reserved * obj)
{
    if(!root->getMiddle()) //if no middle
    {
        Node * temp = new Node;
        root->setMiddle(temp); //create new middle node

        if(obj < root->getLeft()->getData1()) //check values in left node... if obj is smallest
        {
            temp->setData1(obj); //make obj new middle
        }
        else if(obj < root->getLeft()->getData2()) //obj is median val
        {
            temp->setData1(root->getLeft()->getData1()); //make middle w/val of data1
            root->getLeft()->setData1(obj); //replace leftData1 with obj
        }
        else
        {
            temp->setData1(root->getLeft()->getData1()); //make middle data1
            root->getLeft()->setData1(root->getLeft()->getData2()); //put data2 into leftData1
            root->getLeft()->setData2(obj); //put obj into old leftData2
        }
    }
    else
    {
        //rotate the tree to make room
    }

}

void Tree::insertRight(Node * & root, Reserved * obj)
{
    if(!root->getMiddle()) //if no middle
    {
        //if 1 or 2 data members in node
        //if 1 then move data so that there are 2 in any node
        //else push new middle
    }
    else
    {
        //rotate the tree to make room
    }
}