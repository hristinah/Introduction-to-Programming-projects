#include <iostream>

using namespace std;

void printNumberOfBillsForTypeAndSubstract( int & number , int typeBills ) {
    int countBills=number/typeBills;
    if (countBills > 0) {
        number=number%typeBills;
        cout<<countBills<<'*'<<typeBills;
        if(number>0)
            cout<<" + ";
    }
}

int main() {
    int number;
    cin>>number;
    cout<<number<<" = ";
    printNumberOfBillsForTypeAndSubstract(number,50);
    printNumberOfBillsForTypeAndSubstract(number,20);
    printNumberOfBillsForTypeAndSubstract(number,10);
    printNumberOfBillsForTypeAndSubstract(number,5);
    printNumberOfBillsForTypeAndSubstract(number,2);
    printNumberOfBillsForTypeAndSubstract(number,1);
    cout<<endl;
    return 0;
}
