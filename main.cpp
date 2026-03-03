#include <iostream>
#include <string>
#include "Data.cpp"
#include "InfixData.cpp"
#include "PostfixData.cpp"

using namespace std;

int main(){
    string input;
    
    while (input != "EXIT" && input != "exit") 
    {
        cout << "\nInput Valid Infix Expression (type EXIT to stop): ";
        cin >> input;

        if (input == "EXIT" || input == "exit")
            break;
        
        //Convert string to infix data
        InfixData infix = InfixData(input);
        cout << "Input: " + input << endl;

        //Convert the infix to postfix
        PostfixData postfix = PostfixData(infix);

        //Evaluate postfix
        infix.displayQueue();
    }

    return 0;
}