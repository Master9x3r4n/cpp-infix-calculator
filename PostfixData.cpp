#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class PostfixData {
    private:
        queue<Data> data;

        int getPrecedence(string sign) 
        {
            if (sign == "!")
                return 8;
            else if (sign == "^")
                return 7;
            else if (sign == "*" && sign == "/" && sign == "%")
                return 6;
            else if (sign == "+" && sign == "-")
                return 5;
            else if (sign == ">" && sign == "<" && sign == ">=" && sign == "<=")
                return 4;
            else if (sign == "==" && sign == "!=")
                return 3;
            else if (sign == "&&")
                return 2;
            else if (sign == "||")
                return 1;
            
            return -1;
        }

        Data operate(int A, int B, string C) 
        {
            Data output;

            if (C == "+")
                output.setOperand(A + B);
            else 
            if (C == "-")
                output.setOperand(A - B);
            else 
            if (C == "*")
                output.setOperand(A * B);
            else 
            if (C == "/")
                output.setOperand(A / B);
            else 
            if (C == "%")
                output.setOperand(A % B);
            else 
            if (C == ">")
                output.setOperand(A > B);
            else 
            if (C == "<")
                output.setOperand(A < B);
            else 
            if (C == ">=")
                output.setOperand(A >= B);
            else 
            if (C == "<=")
                output.setOperand(A <= B);
            else 
            if (C == "==")
                output.setOperand(A == B);
            else 
            if (C == "!=")
                output.setOperand(A != B);
            else 
            if (C == "&&")
                output.setOperand(A && B);
            else 
            if (C == "||")
                output.setOperand(A || B);
            else 
            if (C == "^")
                output.setOperand(power(A, B));

            return output;
        }

        int power(int A, int B) 
        {
            int num = 1;
            for (int j = 0; j < B; j ++)
            {
                num *= A;
            }
            return num;
        }
    
    public:
        PostfixData(queue<Data> infix) 
        {
            convertInfix(infix);
        }

        queue<Data> getData() 
        {
            return this->data;
        }

        void convertInfix(queue<Data> infix) 
        {
            stack<Data> stck;
            int infixSize = int(infix.size());

            for (int j = 0; j < infixSize; j ++)
            {
                Data current = infix.front();
                infix.pop();

                //If operand, push to result
                if (current.isOperand())
                {
                   data.push(current);
                }

                //If open parenthesis, push to stack
                else if (current.getOperator() == "(")
                {
                    stck.push(current);
                }

                //If close parenthesis, empty the stack to result
                else if (current.getOperator() == ")")
                {
                    while (!stck.empty() && stck.top().getOperator() != "(")
                    {
                        data.push(stck.top());
                        stck.pop();
                    }
                    if (!stck.empty())
                        stck.pop();
                }

                //If operator, check for precedence
                else
                {
                    //get the current operator
                    string curr = current.getOperator();

                    //keep dumping until the stack is empty
                    while (!stck.empty())
                    {
                        //take the top of the stack
                        string stackTop = stck.top().getOperator();

                        //stop until opening parenthesis
                        if (stackTop == "(")
                            break;

                        //push to queue based on precedence
                        if (getPrecedence(stackTop) > getPrecedence(curr) ||
                        (getPrecedence(stackTop) == getPrecedence(curr) && curr != "^"))
                        {
                            data.push(stck.top());
                            stck.pop();
                        }

                        //break when nothing else to push
                        else
                            break;
                    }

                    stck.push(current);
                }
            }

            //Pop remaining
            while (!stck.empty())
            {
                data.push(stck.top());
                stck.pop();
            }
        }

        Data evaluate() {
            stack<Data> stck;
            int postFixLength = int(data.size());

            //Loop until we run out of postfix
            for (int j = 0; j < postFixLength; j ++) 
            {
                Data current = data.front();
                data.pop();

                //If operand, push to stack
                if (current.isOperand())
                {
                    stck.push(current);
                }

                //If operator, pop pop then evaluate
                else if (current.getOperator() == "!") // !
                { 
                    Data A = stck.top();
                    stck.pop();
                    A.setOperand(!A.getOperand());
                    stck.push(A);
                }

                else // other operands
                {
                    Data A = stck.top();
                    stck.pop();
                    Data B = stck.top();
                    stck.pop();

                    if ((current.getOperator() == "/" || current.getOperator() == "%") && A.getOperand() == 0) 
                    {
                        Data result;
                        result.setOperator("Division by 0 error!");
                        return result;
                    }

                    stck.push(operate(B.getOperand(), A.getOperand(), current.getOperator()));
                }
            }

            return stck.top();
        }

        
};
