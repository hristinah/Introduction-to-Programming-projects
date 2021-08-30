#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    if(number<3 || number%3==0) return false;   // the function won't be called for even numbers  so it won't check for them

    int checkLimit=(int) sqrt(number);
    for (int i=5; i<=checkLimit; i+=6)
        if (number%i==0 || number%(i+2)==0)
            return false;

    return true;
}

int main() {
    int numberOfPairs;
    int firstNumInPotentialPair=5;
    cin>>numberOfPairs;

    if(numberOfPairs>=1) {
        cout<<"3 5"<<endl;
        numberOfPairs--;
    }

    while(numberOfPairs>0) {
        if(isPrime(firstNumInPotentialPair) && isPrime(firstNumInPotentialPair+2)) {
            cout<<firstNumInPotentialPair<<" "<<firstNumInPotentialPair+2<<endl;
            numberOfPairs--;
        }
        firstNumInPotentialPair+=6;
    }

    return 0;
}
