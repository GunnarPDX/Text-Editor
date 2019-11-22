// Carl Gunnar Rosenberg
// CS 202
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Tree.h"
#include "List.h"
#include "String.h"
#include <cstring>
using namespace std;


class Controller {
public:
    Controller(int size); //constructor
    ~Controller(); //destructor

    void program(); //cli for program

private:
    Tree tree; //2-3 tree obj
    List list; //table obj
    Colors highlights; //colors obj

    void insertReserved();
    void insertText();
    void insertText(int i);
    void test();
    void menu();

};


#endif
