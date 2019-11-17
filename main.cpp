// Carl Gunnar Rosenberg
// CS 202
//

#include "Tree.h"
#include "String.h"

#include <sstream> //input delimitation

int main() {


    for(int i = 0; i < 8; ++i)
    {
        cout << "\x1B[" << 3 << i << "m" << "Text" <<"\033[0m\t\t" << endl;
    }



    String obj1, obj2;

    obj1 = "hello ";

    cin >> obj2;  // cin >> a;

    cout << "here it comes: " << obj1 << obj2 <<endl;




    return 0;
}