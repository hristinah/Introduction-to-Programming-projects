#include <iostream>
#include <string>

using namespace std;

long int NumStringInBaseKToNumberInBase10( string number, int base );
string NumberInBase10ToNumStringInBaseK( long int number, int base );
int CharacterToDigit( char c );
char DigitToCharacter ( int d );


int CharacterToDigit( char c ) {
    return ( (int)c - 48 );
}

char DigitToCharacter ( int d ) {
    return ( char( d + 48 ) );
}

long int NumStringInBaseKToNumberInBase10( string number, int base ) {
    int digit;
    int numLength=number.length();
    unsigned long int coefficient=1;
    long int numInBase10=0;

    for (int i=numLength-1; i>=0; i--) {
        digit=CharacterToDigit(number[i]);

        if (digit<0||digit>=base)
            return -1;
        else
            numInBase10+=digit*coefficient;

        coefficient*=base;
    }

    return numInBase10;
}

string NumberInBase10ToNumStringInBaseK( long int number, int base ) {
    string numString="";
    while (number>0) {
        numString=DigitToCharacter(number%base) + numString;
        number/=base;
    }
    return numString;
}



int main()
{
    string strNumber1, strNumber2;
    long int number1, number2;
    int base;

    cin>>strNumber1>>strNumber2>>base;
    number1=NumStringInBaseKToNumberInBase10(strNumber1,base);
    number2=NumStringInBaseKToNumberInBase10(strNumber2,base);
    if(number1==-1 || number2==-1)
        cout<<"Bad input data!";
    else
        cout<<NumberInBase10ToNumStringInBaseK((number1+number2),base);
    return 0;
}
