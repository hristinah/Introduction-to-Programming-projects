#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double d, dSquaredAndDivided, aIteration, vIteration=0, s=0, sIteration;
    cin>>n>>d;
    dSquaredAndDivided=pow(d,2.0)/2;

    for(int i=0; i<n; i++) {
        cin>>aIteration;
        sIteration=vIteration*d + aIteration*dSquaredAndDivided;
        if(sIteration<0) sIteration=0;
        s+=sIteration;
        vIteration+=aIteration*d;
        if(vIteration<0) vIteration=0;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(5)<<s;
    return 0;
}
