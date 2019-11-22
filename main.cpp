// Carl Gunnar Rosenberg
// CS 202
//
// main.cpp
// this is my programs main, it pretty much just builds and calls the program method of the controller class

#include "Controller.h"

int main() {

    Controller window(5); // 5 = max num of lines in file

    window.program();

    return 0;
}