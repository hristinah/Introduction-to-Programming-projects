#include <iostream>
#include <math.h>

using namespace std;


/* Uses that (a*b) mod p = ( (a mod p)*(b mod p) ) mod p
to calculate (x^n) mod m */

int powModCalculator( int x, int n, int m) {
    if (n==1)
        return x%m;
    else {
        int n1=n/2;
        int powN1Mod=powModCalculator(x,n1,m);
        if (n & 1) //n is odd
            return (powN1Mod*powN1Mod*(x%m)) % m;
        else
            return (powN1Mod*powN1Mod) % m;
    }
}

int main() {
    int x,n,m,y,counterFound=0;
    cin>>n>>m>>y;
    for(x=1; x<m; x++) {
        if(powModCalculator(x,n,m)==y) {
            counterFound++;
            if(counterFound==1)
                cout<<x;
            else
                cout<<" "<<x;

        }
    }
    if(counterFound==0)
        cout<<-1;
    return 0;
}
