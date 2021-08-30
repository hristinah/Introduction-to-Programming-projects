#include <iostream>

using namespace std;

bool sameDigitsInHexadecimal(unsigned long int number) {
    int quotient, remainder;
    quotient=number/16;
    remainder=number%16;
    while (quotient)
    {
        if (remainder!=quotient%16)
            return false;
        else
            quotient=quotient/16;
    }
    return true;
}

int main()
{
    unsigned long int number;
    cin>>number;
    if (sameDigitsInHexadecimal(number))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
