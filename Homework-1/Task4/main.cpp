#include <iostream>

using namespace std;

int charCoordinateToInt (char);
bool checkWithQueen ( int , int , int , int );
bool checkWithBishop ( int , int , int , int );
bool checkWithRook ( int , int , int , int );
bool checkWithKnight ( int , int , int , int );

int charCoordinateToInt (char coordinate) {
    return (int)coordinate - 96;
}

bool checkWithQueen ( int opponentX , int opponentY , int kingX , int kingY ) {
    if((kingX-kingY)==(opponentX-opponentY)||(kingX+kingY)==(opponentX+opponentY)||kingX==opponentX||kingY==opponentY)
        return true;
    else
        return false;
}

bool checkWithBishop ( int opponentX, int opponentY, int kingX, int kingY ) {
    if((kingX-kingY)==(opponentX-opponentY)||(kingX+kingY)==(opponentX+opponentY))
        return true;
    else
        return false;
}

bool checkWithRook ( int opponentX, int opponentY, int kingX, int kingY ) {
    if(kingX==opponentX||kingY==opponentY)
        return true;
    else
        return false;
}

bool checkWithKnight ( int opponentX, int opponentY, int kingX, int kingY ) {
    if(((kingX-1)==opponentX&&(kingY-2)==opponentY)||((kingX+1)==opponentX&&(kingY-2)==opponentY)||
            ((kingX-1)==opponentX&&(kingY+2)==opponentY)||((kingX+1)==opponentX&&(kingY+2)==opponentY)||
            ((kingX-2)==opponentX&&(kingY-1)==opponentY)||((kingX+2)==opponentX&&(kingY-1)==opponentY)||
            ((kingX-2)==opponentX&&(kingY+1)==opponentY)||((kingX+2)==opponentX&&(kingY+1)==opponentY))
        return true;
    else
        return false;
}

int main()
{
    int opponentX, opponentY, kingX, kingY;
    char opponentType, opponentCharX, kingCharX;
    cin>>opponentType;
    cin>>opponentCharX>>opponentY;
    cin>>kingCharX>>kingY;
    if ((opponentCharX<'a' || opponentCharX>'h') || (kingCharX<'a' || kingCharX>'h') ||
            (opponentY<1 || opponentY>8) || (kingY<1 || kingY>8) )
        cout<<"Incorrect Coordinates"<<endl;
    else
    {
        opponentX=charCoordinateToInt(opponentCharX);
        kingX=charCoordinateToInt(kingCharX);
        switch(opponentType)
        {
        case 'Q':
            if(checkWithQueen (opponentX, opponentY, kingX, kingY ))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            break;
        case 'B':
            if(checkWithBishop (opponentX, opponentY, kingX, kingY ))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            break;
        case 'N':
            if(checkWithKnight (opponentX, opponentY, kingX, kingY ))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            break;
        case 'R':
            if(checkWithRook (opponentX, opponentY, kingX, kingY ))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            break;
        default:
            cout<<"Incorrect Opponent Type"<<endl;
        }
    }
    return 0;
}
