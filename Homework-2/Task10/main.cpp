#include <iostream>
#include <math.h>

using namespace std;

bool isFactorOfN(unsigned long long int n, unsigned long long int p) {
    return n%p==0;
}

int vpn(unsigned long int p, unsigned long long int n) {
    int powerP=1;
    int maxPowerP=0;
    unsigned long long int divisor=p;
    while (divisor<=n) {
        if (isFactorOfN(n,divisor))
            maxPowerP=powerP;
        powerP++;
        divisor*=p;
    }
    return maxPowerP;
}

int main() {
    int nq;
    unsigned long long int n;
    long int p1,p2;
    cin>>nq;

    while (nq>0) {
        nq--;
        cin>>p1>>n>>p2;
        if(n==0)
            cout<<"infinity"<<endl;
        else
            cout<<max( vpn(p1,n), vpn(p2,n) )<<endl;
    }

    return 0;
}
