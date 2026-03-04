#include <iostream>

using namespace std;

class Data {
    private:
        int operand;
        string operatorSign;
        bool isNum;
    
    public:
        //Constructor
        Data() {
            this->isNum = false;
        }

        //Constructor 1
        Data(int operand) {
            Data();
            this->setOperand(operand);
        }

        //Constructor 2
        Data(string operatorSign) {
            Data();
            this->operatorSign = operatorSign;
            this->isNum = false;
        }

        //Setter for the operand
        void setOperand(int operand) {
            this->operand = operand;
            this->isNum = true;
        }

        //Setter for the operator
        void setOperator(string operatorSign) {
            this->operatorSign = operatorSign;
            this->isNum = false;
        }

        //Getter for the operand
        int getOperand() {
            return this->operand;
        }

        //Getter for the operator
        string getOperator() {
            return this->operatorSign;
        }

        //Boolean checker for current data type
        bool isOperand() {
            return this->isNum;
        }
};