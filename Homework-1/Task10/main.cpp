#include <iostream>
#include<iomanip>

using namespace std;

/* Solving a system of two equations in two variables of type :
    | a1*x + b1*y = c1
    | a2*x + b2*y = c2
*/
double calculateDeterminant(double , double , double , double);
bool systemIsDependent (double , double , double , double , double , double);

double calculateDeterminant(double a1, double a2, double b1, double b2) {
    return (a1*b2 - a2*b1);
}

bool systemIsDependent (double a1, double b1, double c1, double a2, double b2, double c2) {
    return ((a1/a2)==(b1/b2) && (a1/a2)==(c1/c2));
}

int main() {
    double a1, b1, c1, a2, b2, c2, y, x;
    double determinant, determinantX, determinantY; // Determinants used in Cramer’s Rule to solve the system
    cin>>a1>>b1>>c1>>a2>>b2>>c2;

    determinant=calculateDeterminant(a1,a2,b1,b2);

    if(determinant!=0) {
        determinantX=calculateDeterminant(c1,c2,b1,b2);
        determinantY=calculateDeterminant(a1,a2,c1,c2);
        x=determinantX/determinant;
        y=determinantY/determinant;
        cout<<setprecision(5)<<x<<" "<<y<<endl;
    }
    else if(systemIsDependent(a1,b1,c1,a2,b2,c2))
        cout<<"Many solutions"<<endl;
    else
        cout<<"No solution"<<endl;

    return 0;
}
