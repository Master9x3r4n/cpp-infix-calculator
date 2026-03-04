#include <iostream>
#include <string>
#include <queue>

using namespace std;

class InfixData {
    //Private attributes
    private:
        queue<Data> data;
    
    //Public methods
    public:
        //Constructor
        InfixData(string input) 
        {
            setQueue(input);
        }

        //Getter
        queue<Data> getData() 
        {
            return data;
        }
        
        //Setter (parses the input string as a Data queue)
        void setQueue(string input) 
        {
            //Iterate through each characters in the string
            int buffer = -1;
            size_t stringLen = input.length();
            for (int j = 0; j < int(stringLen); j ++) 
            {
                char current = input[j];

                //If the current char is a number, keep pushing to the buffer
                if (current >= 48 && current <= 57) 
                {
                    //Keep pushing it into the buffer
                    if (buffer == -1)
                        buffer = 0;
                    buffer *= 10;
                    buffer += current - 48;
                } 
                //If the current char is an operator, push to the queue
                else 
                {
                    //If the buffer is not empty, push the operand first
                    if (buffer != -1) 
                    {
                        Data temp1;
                        temp1.setOperand(buffer);
                        data.push(temp1);
                        buffer = -1;
                    } 

                    // simply push to buffer
                    Data temp2;
                    string tempOp = "_";
                    tempOp[0] = current; //yes, i know this is stupid but you gotta admire the creativity

                    //Check for double length operators
                    if (current == '|' || current == '&' || current == '=' 
                        || ((current == '>' || current == '<' || current == '!') && input[j + 1] == '=')) 
                    {
                        tempOp += "_";
                        tempOp[1] = input[j+1];
                        j ++;
                    }
                    temp2.setOperator(tempOp);
                    data.push(temp2); 
                }
            }

            //Push last input for operands
            if (buffer != -1) 
            {
                Data temp1;
                temp1.setOperand(buffer);
                data.push(temp1);
                buffer = -1;
            } 
        }        
    
};
