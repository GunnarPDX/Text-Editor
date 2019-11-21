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
    void insert();

private:
    Tree tree;
    List list;
};


#endif //UNTITLED3_CONTROLLER_H
