#include <iostream>
#include <string>

using namespace std;

int main() {
    string firstNumber, secondNumber;
    size_t positionLastMatch=0;
    unsigned int occurencessOfFirstNumber=0;

    cin>>firstNumber>>secondNumber;
    positionLastMatch=secondNumber.find(firstNumber,positionLastMatch);

    while (positionLastMatch!=string::npos) {
        occurencessOfFirstNumber++;
         positionLastMatch=secondNumber.find(firstNumber,positionLastMatch+1);
    }

    cout<<occurencessOfFirstNumber<<endl;

    return 0;
}
