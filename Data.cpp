#include <iostream>

using namespace std;

class Data {
    private:
        int operand;
        string operatorSign;
        bool isNum;
    
    public:
        Data() {
            this->isNum = false;
        }

        Data(int operand) {
            Data();
            this->setOperand(operand);
        }

        Data(string operatorSign) {
            Data();
            this->operatorSign = operatorSign;
            this->isNum = false;
        }

        void setOperand(int operand) {
            this->operand = operand;
            this->isNum = true;
        }

        void setOperator(string operatorSign) {
            this->operatorSign = operatorSign;
            this->isNum = false;
        }

        int getOperand() {
            return this->operand;
        }

        string getOperator() {
            return this->operatorSign;
        }

        bool isOperand() {
            return this->isNum;
        }
};