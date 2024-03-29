// Carl Gunnar Rosenberg


#include "Controller.h"


Controller::Controller(int size) : list(size), tree(){}

Controller::~Controller() {}

void Controller::program()
{
    int input = 0;

    do{
        menu();

        cin >> input; //menu selection
        cin.ignore(100, '\n');
        cin.clear();

        if(input < 0 || input > 6) cout << " Invalid Entry " << endl;
        else switch(input)
        {
            case 0:
            {
                cout << endl << "Ending Program" << endl;
            }break;
            case 1:
            {
                insertReserved();
            }break;
            case 2:
            {
                tree.display();
            }break;
            case 3:
            {
                test();
            }break;
            case 4:
            {
                insertText();
            }break;
            case 5:
            {
                list.display();
            }break;
            case 6:
            {
                tree.removeAll();
                list.removeAll();
            }break;
            default:
            {
                cout << endl << "Invalid Input" << endl;
            }
            break;
        }
    }while(input != 0);

}

void Controller::menu()
{
    cout << endl << endl << "          -MENU-"
         << endl << endl
         << " 1- Enter a reserved word/symbol or comment" << endl
         << " 2- Display all reserved words" << endl
         << " 3- Run 2-3 tree test (preload data)" << endl
         << " 4- Insert text" << endl
         << " 5- Display text" << endl
         << " 6- Remove all" << endl
         << " 0- Exit program" << endl << endl
         << " Select an operation (0-4): ";
}

void Controller::insertReserved()
{
    cout << "select an option" << endl
            << " 1- Enter a reserved word" << endl
            << " 2- Enter a reserved symbol" << endl
            << " 3- Enter a comment" << endl
            << "Select an option (1-3): ";

    int input = 0; //menu selection
    cin >> input;
    cin.ignore(100, '\n');
    cin.clear();

    if(input < 0 || input > 3) cout << " Invalid Entry " << endl;
    else switch(input)
        {
            case 1:
            {
                String wordInput;

                cout << "Please enter a reserved word: ";
                cin >> wordInput;

                Reserved * ptr = new Word(wordInput);
                tree.insert(ptr);
            }break;
            case 2:
            {
                String symbolInput;

                cout << "Please enter a reserved symbol: ";
                cin >> symbolInput;

                int color = highlights.colorPicker(); //pick a custom color

                Reserved * ptr = new Symbol(symbolInput, color);
                tree.insert(ptr);
            }break;
            case 3:
            {
                String commentInput;

                cout << "Please enter a comment: ";
                cin >> commentInput;

                Reserved * ptr = new Word(commentInput);
                tree.insert(ptr);
            }break;
            default:
            {
                cout << "Please enter a valid input (1-3)" << endl;
            }break;
        }

}

void Controller::insertText()
{
    cout << "Enter text: " << endl;
    insertText(0);
}

void Controller::insertText(int i)
{
    if(i == list.getSize())return;

    char textInput[100];
    cout << i << ": ";
    cin.get(textInput, 100, '\n');
    cin.ignore(101, '\n');
    cin.clear();

    char * split;
    split = strtok(textInput," "); //use strtok() to "tokenize" (split) the string

    while(split)
    {
        String splitInput;
        splitInput = split;

        int highlight = tree.search(splitInput);

        Text * ptr = new Text(splitInput, highlight);
        list.insert(i, ptr); //input tokenized words into table

        split = strtok(NULL, " "); //next token
    }
    insertText(++i);
}



void Controller::test()
{
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
}