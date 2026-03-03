#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct dataTag {
    int operand;
    string operatorSign;
    bool isNum;
} Data;

class InfixData {
    //Private attributes
    private:
        queue<Data> data;
    
    //Public methods
    public:
        //Constructor
        InfixData(string input) {
            setQueue(input);
        }

        //Getter
        queue<Data> getData() {
            return data;
        }
        
        //Setter (parses the input string as a Data queue)
        void setQueue(string input) {
            //Iterate through each characters in the string
            int buffer = -1;
            for (size_t i = 0; i < input.length(); i ++) {
                char current = input[i];

                //If the current char is a number, keep pushing to the buffer
                if (current >= 48 && current <= 57) {
                    //Keep pushing it into the buffer
                    if (buffer == -1)
                        buffer = 0;
                    buffer *= 10;
                    buffer += current - 48;
                } 
                //If the current char is an operator, push to the queue
                else {
                    //If the buffer is not empty, push the operand first
                    if (buffer != -1) {
                        Data temp1;
                        temp1.operand = buffer;
                        temp1.isNum = true;
                        data.push(temp1);
                        buffer = -1;
                    } 

                    // simply push to buffer
                    Data temp2;
                    temp2.operatorSign = current;
                    temp2.isNum = false;

                    //Check for double length operators
                    if (current == '|' || current == '&' || current == '=' || (current == '!' && input[i + 1] == '=')) {
                        temp2.operatorSign += input[i+1];
                        i ++;
                    }

                    data.push(temp2); 
                }
            }

            //Push last input for operands
            if (buffer != -1) {
                Data temp1;
                temp1.operand = buffer;
                temp1.isNum = true;
                data.push(temp1);
                buffer = -1;
            } 
        }

        //This method prints out the contents of the queue
        void displayQueue() {
            int length = data.size();
            for (int j = 0; j < length; j ++) {
                Data temp = data.front();
                data.pop();
                data.push(temp);
                
                if (temp.isNum)
                    cout << temp.operand << " ";
                else
                    cout << temp.operatorSign << " ";
                cout << "\n";
            }
        }
        
    
};
