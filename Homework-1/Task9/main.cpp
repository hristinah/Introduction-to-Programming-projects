#include <iostream>

using namespace std;

const int range = 16;

void handleOveflow(int &);
int returnResult(int , int , char);

void handleOveflow(int & number) {
    if(number>=range)
        number=number%range;
    else if(number<0)
        number=number+range;
}

int returnResult(int firstOperand , int secondOperand , char operation) {
    int result = 0;
    switch(operation) {
    case '+' :
        result=firstOperand+secondOperand;
        break;
    case '-' :
        result=firstOperand-secondOperand;
        break;
    case '.' :
        result=firstOperand*secondOperand;
        break;
    case '/' :
        result=firstOperand/secondOperand;
        break;
    case '%' :
        result=firstOperand%secondOperand;
        break;
    }
    handleOveflow(result);
    return result;
}


int main() {
    int firstOperand, secondOperand;
    char operation;

    cin>>firstOperand>>operation>>secondOperand;
    handleOveflow(firstOperand);
    handleOveflow(secondOperand);

    if((operation=='%' || operation=='/') && secondOperand==0)
        cout<<"Division by zero!"<<endl;
    else
        cout<<returnResult(firstOperand,secondOperand,operation)<<endl;

    return 0;
}
