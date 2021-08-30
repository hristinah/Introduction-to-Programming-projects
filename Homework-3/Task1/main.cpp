#include <iostream>
#include <string>

using namespace std;

string numericalSequenceForN ( short unsigned int n ) {
    if (n==1)
        return "1";
    else {
       string numericalSequenceForPrevN=numericalSequenceForN(n-1);
       return numericalSequenceForPrevN+to_string(n)+numericalSequenceForPrevN;
    }
}

int main() {
    short unsigned int n;
    cin>>n;
    cout<<numericalSequenceForN(n)<<endl;
    return 0;
}
