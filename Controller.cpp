// Carl Gunnar Rosenberg
// CS 202
//

#include "Controller.h"

void Controller::program()
{
    int input = 0;

    do{
        //call menu

        cin >> input;
        cin.ignore(100, '\n');
        cin.clear();

        if(input < 0 || input > 3) cout << " Invalid Entry " << endl;
        else switch(input)
        {
            case 1:
            {

            }
            break;
            case 2:
            {

            }
            break;
            case 3:
            {

            }
            break;
            default:
            {

            }
            break;
        }
    }while(input != 0);

}