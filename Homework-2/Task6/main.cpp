#include <iostream>

using namespace std;

int main() {
    int n;
    unsigned long long int coeficient=1;
    cin>>n;
    cout<<coeficient;
    if(n==1) cout<<" "<<coeficient;
    else
        for(int k=1; k<=n; k++) {
            coeficient=coeficient*(n-k+1)/k;
            cout<<" "<<coeficient;
        }

    return 0;
}
