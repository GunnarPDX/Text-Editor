// Carl Gunnar Rosenberg
// CS 202
//

#include "List.h"


Text::Text()
{

}

Text::Text(String word)
{

}

Text::Text(const Text & obj)
{

}

Text::~Text()
{

}

void Text::print()
{

}

void Text::setHighlight(int color)
{

}


//- list node class methods


ListNode::ListNode() //default constructor
{
    data = NULL;
    next = NULL;
    previous = NULL;
}

ListNode::ListNode(const ListNode & obj) //copy constructor
{
    data = obj.data;
    next = obj.next;
    previous = obj.previous;
}

ListNode::ListNode(Text * obj) //obj constructor
{
    data = obj;
    next = NULL;
    previous = NULL;
}

ListNode::~ListNode() //destructor
{
    if(data)
    {
        delete data;
        data = NULL;
    }
    next = NULL;
    previous = NULL;
}

ListNode *& ListNode::getNext() //next getter
{
    return(next);
}

void ListNode::setNext(ListNode * newNode) //next setter
{
    next = newNode;
}

ListNode *& ListNode::getPrevious() //previous getter
{
    return(previous);
}

void ListNode::setPrevious(ListNode * newNode) //previous setter
{
    previous = newNode;
}

Text *& ListNode::getData() //data getter
{
    return(data);
}

void ListNode::setData(Text *& newData) //data setter
{
    data = newData;
}



//----- list class methods



List::List(int size) : size(size) //default constructor
{
    head = new ListNode*[size];

    for(int i = 0; i < size; ++i)
    {
        head[i] = NULL;
    }
}

List::~List() //destructor
{
    for(int i = 0; i < size; ++i)
    {
        deleteAll(head[i]);
        head[i] = NULL;
    }
}

void List::deleteAll(ListNode *& head) //delete all function
{
    if(!head) return;
    deleteAll(head->getNext());
    head->setNext(NULL);
    delete head;
}

bool List::insert(int i, Text * obj) //insert function
{
    if(i >= size || i < 0)return false;
    return insert(head[i], obj);
}

bool List::insert(ListNode *& head, Text * obj) //adds at end
{
    if(!head) //if the DLL is empty
    {
        head = new ListNode(obj);
        head->setNext(NULL);
        head->setPrevious(NULL);
        return true;
    }
    else if(!head->getNext())
    {
        //set next to obj
        ListNode * temp = new ListNode(obj);
        head->setNext(temp);
        temp->setPrevious(head);
        return true;
    }
    return insert(head->getNext(), obj);
}

void List::removeAll() //remove all wrapper
{
    removeAllLoop(0);
}

void List::removeAllLoop(int i) //recursive remove all loop
{
    if(i >= size) return;
    removeAll(head[i]);
    removeAllLoop(++i);
}

void List::removeAll(ListNode *& head) //remove dll
{
    if(!head) return;
    removeAll(head->getNext());
    //remove(head);
    head = NULL;
}