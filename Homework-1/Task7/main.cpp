#include <iostream>
#include<math.h>

using namespace std;

const double rYinYangSquared = 36;
const double rSmallCirclesSquared = 1;
const double rMediumHalfCirclesSquared = 9;
const double yTopInnerCircles = 3;
const double yBottomInnerCircles = -3;
const double precision=0.0001;

double distanceFromCircleCenter ( double , double , double);
bool isOnTheOutsideOrItsBorder (double , double);
bool isOnSmallCircleBorder (double , double , double);
bool isInSmallCircle (double , double , double);
bool isOnHalfCirclesBorder (double , double);
bool isInHalfCircle (double , double , double);

double distanceFromCircleCenter ( double x , double y , double yCircle=0) {
    return pow(x,2.0) + pow((y-yCircle),2.0);
}

bool isOnTheOutsideOrItsBorder (double x , double y) {
    return ( (distanceFromCircleCenter(x,y) - rYinYangSquared)>=-precision );
}

bool isOnSmallCircleBorder (double x , double y , double yCircle) {
    return ( fabs( distanceFromCircleCenter(x,y,yCircle) - rSmallCirclesSquared)<=precision );
}

bool isInSmallCircle (double x , double y , double yCircle) {
    return ( ( distanceFromCircleCenter(x,y,yCircle) - rSmallCirclesSquared)<=-precision );
}

bool isOnHalfCirclesBorder (double x , double y) {
    if (fabs(x)<=precision && fabs(y)<=precision) // in exact center
        return true;
    else if (x>precision && y>precision && fabs( distanceFromCircleCenter(x,y,yTopInnerCircles) - rMediumHalfCirclesSquared)<=precision) // in top half-circle's border
        return true;
    else if (x<-precision&&y<-precision && fabs( distanceFromCircleCenter(x,y,yBottomInnerCircles) - rMediumHalfCirclesSquared)<=precision) // in bottom half-circle's border
        return true;
    else
        return false;
}

bool isInHalfCircle (double x , double y , double yCircle) {
    return ( (distanceFromCircleCenter(x,y,yCircle) - rMediumHalfCirclesSquared)<=-precision );
}

int main() {
    double x,y;
    cin>>x>>y;
    if( isOnTheOutsideOrItsBorder(x,y) || isOnSmallCircleBorder(x,y,yTopInnerCircles) ||
            isOnSmallCircleBorder(x,y,yBottomInnerCircles) || isOnHalfCirclesBorder(x,y) )
        cout<<"Neutral"<<endl;
    else if ( isInSmallCircle(x,y,yBottomInnerCircles) ) // in bottom good small circle
        cout<<"Good"<<endl;
    else if ( !isInSmallCircle(x,y,yTopInnerCircles) ) { //  not in top bad small circle
        if ( x<0 && y>0 )  // good in quadrant 2 of the YinYang
            cout<<"Good"<<endl;
        else if ( x>0 && y>0 && isInHalfCircle(x,y,yTopInnerCircles) ) // good in quadrant 1 of the YinYang
            cout<<"Good"<<endl;
        else if ( x<0 && y<0 && !isInHalfCircle(x,y,yBottomInnerCircles) ) // good in quadrant 3 of the YinYang
            cout<<"Good"<<endl;
        else cout<<"Evil"<<endl;
    }
    else cout<<"Evil"<<endl;

    return 0;
}
