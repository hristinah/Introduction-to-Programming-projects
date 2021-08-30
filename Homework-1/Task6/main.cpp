#include <iostream>
#include <algorithm>

using namespace std;

int calculateTopRightCoordinate(int , int); //identical for both x and y
int calculateSCommonPart(int , int , int , int , int , int , int , int);

int calculateTopRightCoordinate(int base , int dimention) {
    return base+dimention;
}

calculateSCommonPart(int firstRectangleBottomLeftX, int firstRectangleBottomLeftY, int firstRectangleTopRightX, int firstRectangleTopRightY,
                     int secondRectangleBottomLeftX, int secondRectangleBottomLeftY, int secondRectangleTopRightX, int secondRectangleTopRightY) {

    int commonPartLeftX, commonPartRightX, commonPartBottomY, commonPartTopY, commonPartWidth, commonPartHeight;

    commonPartLeftX=max(firstRectangleBottomLeftX, secondRectangleBottomLeftX);
    commonPartRightX=min(firstRectangleTopRightX, secondRectangleTopRightX);
    commonPartWidth=commonPartRightX - commonPartLeftX;

    commonPartBottomY=max(firstRectangleBottomLeftY, secondRectangleBottomLeftY);
    commonPartTopY=min(firstRectangleTopRightY, secondRectangleTopRightY);
    commonPartHeight=commonPartTopY - commonPartBottomY;

    if (commonPartWidth>0 && commonPartHeight>0)
        return commonPartWidth*commonPartHeight;
    else return 0;

}

int main() {
    int firstRectangleBottomLeftX , firstRectangleBottomLeftY , firstRectangleTopRightX , firstRectangleTopRightY , firstRectangleHeight , firstRectangleWidth ,
    secondRectangleBottomLeftX , secondRectangleBottomLeftY , secondRectangleTopRightX , secondRectangleTopRightY , secondRectangleHeight , secondRectangleWidth;

    cin>>firstRectangleBottomLeftX>>firstRectangleBottomLeftY>>firstRectangleHeight>>firstRectangleWidth;
    cin>>secondRectangleBottomLeftX>>secondRectangleBottomLeftY>>secondRectangleHeight>>secondRectangleWidth;

    firstRectangleTopRightX=calculateTopRightCoordinate(firstRectangleBottomLeftX,firstRectangleWidth);
    firstRectangleTopRightY=calculateTopRightCoordinate(firstRectangleBottomLeftY,firstRectangleHeight);
    secondRectangleTopRightX=calculateTopRightCoordinate(secondRectangleBottomLeftX,secondRectangleWidth);
    secondRectangleTopRightY=calculateTopRightCoordinate(secondRectangleBottomLeftY,secondRectangleHeight);

    cout<<calculateSCommonPart(firstRectangleBottomLeftX , firstRectangleBottomLeftY , firstRectangleTopRightX , firstRectangleTopRightY ,
                               secondRectangleBottomLeftX , secondRectangleBottomLeftY , secondRectangleTopRightX , secondRectangleTopRightY)<<endl;

    return 0;
}
