#include <iostream>

using namespace std;

bool identicalIfOneDigitIsRemoved( unsigned int longerNum, unsigned int shorterNum );
bool countOfDigitsInNumbersDifferByOne( unsigned int bigger, unsigned int smaller );
unsigned int countOfDigits( unsigned int number );


bool identicalIfOneDigitIsRemoved( unsigned int longerNum, unsigned int shorterNum ) {
    unsigned int countDifferences=0;
    while (countDifferences<2 && shorterNum>0) {
        if (shorterNum%10 == longerNum%10) {
            shorterNum/=10;
            longerNum/=10;
        } else {
            countDifferences++;
            longerNum/=10;
        }
    }
    if (countDifferences<2)
        return true;
    else
        return false;
}

bool countOfDigitsInNumbersDifferByOne( unsigned int bigger, unsigned int smaller ) {
    return ( (countOfDigits(bigger) - countOfDigits(smaller)) == 1 );
}

unsigned int countOfDigits( unsigned int number ) {
    unsigned int countDigits=0;
    unsigned int nthPowerOf10=1;
    while (nthPowerOf10<=number) {
        countDigits++;
        nthPowerOf10*=10;
    }

    return countDigits;
}



int main() {
    unsigned int first,second;
    cin>>first>>second;

    if ( (first>second) && countOfDigitsInNumbersDifferByOne(first,second) ) {
        if (identicalIfOneDigitIsRemoved(first,second))
            cout<<"Yes";
        else
            cout<<"No";
    } else
        cout<<"No";

    return 0;
}
