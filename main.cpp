#include <iostream>
#include <string>
#include <algorithm>
#include "Data.cpp"
#include "InfixData.cpp"
#include "PostfixData.cpp"

using namespace std;

//This method prints out the contents of the queue
void displayQueue(queue<Data> data) {
    int length = data.size();
    for (int j = 0; j < length; j ++) 
    {
        Data temp = data.front();
        data.pop();
        data.push(temp);
        
        if (temp.isOperand())
            cout << temp.getOperand() << " ";
        else
            cout << temp.getOperator() << " ";
        }
    cout << "\n";
}

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
        cout << "Input: " + input << "\n";

        //Convert the infix to postfix
        PostfixData postfix = PostfixData(infix.getData());
        cout << "Postfix: ";
        displayQueue(postfix.getData());

        //Evaluate postfix
        Data result = postfix.evaluate();

        cout << "\nResult: ";
        if (result.isOperand())
            cout << result.getOperand() << "\n";
        else
            cout << result.getOperator() << "\n";
    }

    return 0;
}