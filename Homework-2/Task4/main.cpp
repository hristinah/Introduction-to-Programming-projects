#include <iostream>
#include <string>

using namespace std;

const size_t sizeDigitTables=10;


bool sameDigits( bool * , bool * );
bool * createDigitTableForNumber( string );
int converCharacterToInt( char );
bool isNegative( string );

bool sameDigits( bool * digitsFirstNum, bool * digitsSecondNum ) {
    for (size_t i=0; i<sizeDigitTables; i++) {
        if (digitsFirstNum[i]!=digitsSecondNum[i])
            return false;
    }
    return true;
}


bool * createDigitTableForNumber( string number ) {
    bool * digitsNum=new bool [sizeDigitTables] ();
    size_t lengthNum=number.length();
    int currentDigit;

    for (size_t i=0; i<lengthNum; i++) {
        currentDigit=converCharacterToInt(number[i]);
        if (currentDigit>=0 && currentDigit<=9)
            digitsNum[currentDigit]=true;
    }

    return digitsNum;
}

int converCharacterToInt( char c ) {
    return ( (int)c - 48 );
}

bool isNegative( string number ) {
    return number[0]=='-';
}


int main() {
    string firstNum, secondNum;
    bool * digitsFirstNum, * digitsSecondNum;

    cin>>firstNum>>secondNum;

    digitsFirstNum=createDigitTableForNumber(firstNum);
    digitsSecondNum=createDigitTableForNumber(secondNum);

    if(sameDigits(digitsFirstNum,digitsSecondNum))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
