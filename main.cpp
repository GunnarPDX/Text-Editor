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



    String obj1, obj2;

    obj1 = "hello ";
    cout << "Hello ____ ?" << endl;
    cin >> obj2;  // cin >> a;
    cout << "result : " << obj1 << obj2 <<endl;




    return 0;
}