#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double maxAbsX=5.0;
const double maxAbsY=2.0;
const double constantForAproximation = 5.14/4; // approximation=(3.14*x/2 + x)/2   =>  approximation=5.14*x/4


double approximateDistanceBetweenTwoPoints(double , double , double , double);
double distanceBetweenPoints(double , double , double , double);
double approximationFunction(double);
void swapOuterPointWithIntersectionRectangle(double , double , double & , double &);
void swapOuterPointWithIntersectionVerticalLine(double & , double & , double , double , double);
void swapOuterPointWithIntersectionHorisontalLine(double & , double & , double , double , double);


double approximateDistanceBetweenTwoPoints(double x1, double y1, double x2, double y2) {
    if( ((fabs(x1)>maxAbsX)||fabs(y1)>maxAbsY) && ((fabs(x2)>maxAbsX)||fabs(y2)>maxAbsY) ) // both points are outside
        return 0;
    else if ((fabs(x1)>maxAbsX)||fabs(y1)>maxAbsY) //only first point is outside
        swapOuterPointWithIntersectionRectangle(x2,y2,x1,y1);
    else if ((fabs(x2)>maxAbsX)||fabs(y2)>maxAbsY) //only second point is outside
        swapOuterPointWithIntersectionRectangle(x1,y1,x2,y2);

    return approximationFunction(distanceBetweenPoints(x1,y1,x2,y2));
}

double distanceBetweenPoints(double x1, double y1, double x2, double y2) {
    return sqrt( pow(x1-x2,2.0) + pow(y1-y2,2.0) );
}

double approximationFunction(double distance) {
    return constantForAproximation*distance;
}

void swapOuterPointWithIntersectionRectangle(double innerX, double innerY, double & outerX, double & outerY) {
    if(innerX==outerX) {
        if (outerY>maxAbsY)
            outerY=maxAbsY;
        else
            outerY=-maxAbsY;
    } else {
        double k=(innerY-outerY)/(innerX-outerX);
        double q=innerY-k*innerX;

        if(outerX>maxAbsX)
            swapOuterPointWithIntersectionVerticalLine(outerX,outerY,k,q,maxAbsX);
        else if(outerX<-maxAbsX)
            swapOuterPointWithIntersectionVerticalLine(outerX,outerY,k,q,-maxAbsX);
        //if point is still outside rectangle
        if (outerY>maxAbsY)
            swapOuterPointWithIntersectionHorisontalLine(outerX,outerY,k,q,maxAbsY);
        else  if (outerY<-maxAbsY)
            swapOuterPointWithIntersectionHorisontalLine(outerX,outerY,k,q,-maxAbsY);
    }
}

void swapOuterPointWithIntersectionVerticalLine(double & outerX, double & outerY, double k, double q, double verticalX) {
    outerX=verticalX;
    outerY=k*verticalX+q;
}

void swapOuterPointWithIntersectionHorisontalLine(double & outerX, double & outerY, double k, double q, double horisontalY) {
    outerX=(horisontalY-q)/k;
    outerY=horisontalY;
}



int main() {
    long int n;
    double distance=0;
    double x1,y1,x2,y2;

    cin>>n;
    if(n>0)
        cin>>x1>>y1;

    for(int i=1; i<n; i++) {
        cin>>x2>>y2;
        distance+=approximateDistanceBetweenTwoPoints(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
    }

    cout<<setiosflags(ios::fixed)<<setprecision(3)<<distance;
    return 0;
}
