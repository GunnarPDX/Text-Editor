// Carl Gunnar Rosenberg
// CS 202
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Tree.h"
#include "List.h"
#include "String.h"
using namespace std;


class Controller {
public:
    Controller(int size);
    ~Controller();

    void program();

private:
    Tree tree;
    List list;
    Colors highlights;

    void insertReserved();
    void insertText();
    void test();

};


#endif //UNTITLED3_CONTROLLER_H
