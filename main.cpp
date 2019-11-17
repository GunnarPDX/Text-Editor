// Carl Gunnar Rosenberg
// CS 202
//

#include "Tree.h"

#include <sstream> //input delimitation

int main() {
    cout << "Hello, World!" << endl;

    for(int i = 0; i < 8; ++i)
    {
        cout << "\x1B[" << 3 << i << "m" << "Text" <<"\033[0m\t\t" << endl;
    }




    return 0;
}