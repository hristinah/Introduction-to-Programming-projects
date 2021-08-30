#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void handleUserInput();
unsigned long long int findValueStr(string str);
unsigned long long int NumStrInBaseKToNumInBase10( string number, int base );
unsigned int charToNum( char c );



void handleUserInput() {
    string formula,numberOrSumator;
    unsigned long long int sum=0;
    stringstream strStr;

    getline(cin,formula);
    strStr<<formula;

    while(strStr>>numberOrSumator) {
        sum+=findValueStr(numberOrSumator);
    }

    cout<<sum;
}

unsigned long long int findValueStr(string str) {
    if (str[0]=='+')
        return 0;
    else if (str.length()>=3 && str[0]=='0' && str[1]=='b')
        return NumStrInBaseKToNumInBase10(str.substr(2),2);
    else if (str.length()>=3 && str[0]=='0' && str[1]=='x')
        return NumStrInBaseKToNumInBase10(str.substr(2),16);
    else if (str.length()>=2 && str[0]=='0')
        return NumStrInBaseKToNumInBase10(str.substr(1),8);
    else
        return NumStrInBaseKToNumInBase10(str,10);
}

unsigned long long int NumStrInBaseKToNumInBase10( string number, int base ) {
    int digit;
    int numLength=number.length();
    unsigned long long int coefficient=1;
    unsigned long long int numInBase10=0;

    for (int i=numLength-1; i>=0; i--) {
        digit=charToNum(number[i]);
        numInBase10+=digit*coefficient;
        coefficient*=base;
    }

    return numInBase10;
}

unsigned int charToNum( char c ) {
    if (c>='0' && c<='9')
        return ( (int)c - 48 );
    else if ((c>='A' && c<='F'))
        return ( (int)c - 55 );
    else
        return 0;
}


int main()
{
    handleUserInput();
    return 0;
}
