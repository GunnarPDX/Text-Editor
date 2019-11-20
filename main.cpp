// Carl Gunnar Rosenberg
// CS 202
//

#include "Tree.h"

#include <sstream> //input delimitation

int main() {

    cout << endl
         << "  -Select a Color-    " << endl
         << "\x1B[" << 30 << "m" << "1  = White" << "\033[0m\t\t" << endl
         << "\x1B[" << 31 << "m" << "2  = Red" << "\033[0m\t\t" << endl
         << "\x1B[" << 32 << "m" << "3  = Green" << "\033[0m\t\t" << endl
         << "\x1B[" << 33 << "m" << "4  = Yellow" << "\033[0m\t\t" << endl
         << "\x1B[" << 34 << "m" << "5  = Blue" << "\033[0m\t\t" << endl
         << "\x1B[" << 35 << "m" << "6  = Purple" << "\033[0m\t\t" << endl
         << "\x1B[" << 36 << "m" << "7  = Cyan" << "\033[0m\t\t" << endl
         << "\x1B[" << 37 << "m" << "8  = Grey" << "\033[0m\t\t" << endl
         << endl;


    Tree tree;
    String obj1, obj2, obj3, obj4, obj5, obj6, obj7, obj8, obj9, obj10, obj11, obj12;

    obj1 = "if";
    obj2 = "while";
    obj3 = "NULL";
    obj4 = "new";
    obj5 = ":";
    obj6 = ";";
    obj7 = "+";
    obj8 = "==";
    obj9 = "/* */";
    obj10 = "//";
    obj11 = "zzzz";

    obj12 = "NULL";


    Reserved * ptr1 = new Word(obj1);
    Reserved * ptr2 = new Word(obj2);
    Reserved * ptr3 = new Symbol(obj3, 2);
    Reserved * ptr4 = new Word(obj4);
    Reserved * ptr5 = new Symbol(obj5, 7);
    Reserved * ptr6 = new Symbol(obj6, 7);
    Reserved * ptr7 = new Symbol(obj7, 7);
    Reserved * ptr8 = new Symbol(obj8, 7);
    Reserved * ptr9 = new Comment(obj9);
    Reserved * ptr10 = new Comment(obj10);
    Reserved * ptr11 = new Word(obj11);
    Reserved * ptr12 = new Word(obj12);

    tree.insert(ptr2);
    tree.insert(ptr11);
    tree.insert(ptr4);
    tree.insert(ptr5);
    tree.insert(ptr6);
    tree.insert(ptr3);
    tree.insert(ptr9);
    tree.insert(ptr10);
    tree.insert(ptr7);
    tree.insert(ptr1);
    tree.insert(ptr8);

    cout << obj12 << " highlight: " << tree.search(obj12) << endl << endl;
    tree.display();



    return 0;
}