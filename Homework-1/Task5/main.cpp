#include <iostream>
#include<math.h>

using namespace std;

const double r1 = 8;
const double r2 = 3;
const double r3 = 1;
const double precision=0.0001;

double findDistance(double , double , double , double);
int findResult(double);

double findDistance(double targetX , double targetY , double deviationX , double deviationY) {
    return sqrt( pow((targetX + deviationX) , 2.0) + pow((targetY + deviationY) , 2.0));
}

int findResult(double distanceFromCenter) {
    //landing on the borders or outside the target both give no points
    if((fabs(distanceFromCenter-r1)<precision) || (fabs(distanceFromCenter-r2)<precision) ||
            (fabs(distanceFromCenter-r3)<precision) || ((distanceFromCenter-r1)>=precision))
        return 0;
    else if((distanceFromCenter-r3)<-precision)
        return 60;
    else if((distanceFromCenter-r2)<-precision)
        return 20;
    else
        return 10;
}

int main() {
    double targetX, targetY, deviationX, deviationY, distanceFromCenter;
    cin>>targetX>>targetY>>deviationX>>deviationY;
    distanceFromCenter=findDistance(targetX, targetY, deviationX, deviationY);
    cout<<findResult(distanceFromCenter)<<endl;
    return 0;
}
