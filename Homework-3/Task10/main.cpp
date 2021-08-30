#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

const size_t TABLE_DIMENSIONS = 5;

struct Coordinates {
    size_t row;
    size_t col;
};


void fillTable ( char table[][TABLE_DIMENSIONS] );
bool tableIsCorrect ( char table[][TABLE_DIMENSIONS] );
string transformText ( string text, char table[][TABLE_DIMENSIONS], char substitute );
string findTextFromCoord ( Coordinates * coordText, size_t lenTxt, char table[][TABLE_DIMENSIONS] );
Coordinates * findAllCoordOfText ( string text, size_t lenTxt, char table[][TABLE_DIMENSIONS], Coordinates cooSubstitute );
Coordinates findCoordInTable ( char c, char table[][TABLE_DIMENSIONS] );
void shiftCoordidantesOfText ( Coordinates * coordText, size_t lenText, Coordinates cooSubstitute );
void shiftCoordidantes( Coordinates & cooLetter1, Coordinates & cooLetter2, Coordinates cooSubstitute );
void strToUpper ( string & str );


void fillTable ( char table[][TABLE_DIMENSIONS] ) {
     for ( size_t row=0; row<TABLE_DIMENSIONS; row++ )
        for ( size_t col=0; col<TABLE_DIMENSIONS; col++ )
            cin>>table[row][col];
}

bool tableIsCorrect ( char table[][TABLE_DIMENSIONS] ) {
    int entriesOfLetterInTable [26] {};
    size_t hashValOfLetter;

    for ( size_t row=0; row<TABLE_DIMENSIONS; row++ )
        for ( size_t col=0; col<TABLE_DIMENSIONS; col++ )
            if ( isupper(table[row][col]) )
            {
                hashValOfLetter = (int)table[row][col] - 65;
                entriesOfLetterInTable [hashValOfLetter]++;
                if ( entriesOfLetterInTable [hashValOfLetter] > 1 )
                    return false;
            }
            else
                return false;

    return true;
}

string transformText ( string text, char table[][TABLE_DIMENSIONS], char substitute ) {
    Coordinates cooSubstitute = findCoordInTable(substitute,table);
    size_t lenTxt = text.length();

    if ( lenTxt & 1 ) {//length of text is odd
        text+=substitute;
        lenTxt++;
    }
    strToUpper(text);

    Coordinates * coordText = findAllCoordOfText(text,lenTxt,table,cooSubstitute);
    shiftCoordidantesOfText(coordText,lenTxt,cooSubstitute);
    return findTextFromCoord(coordText,lenTxt,table);
}

string findTextFromCoord ( Coordinates * coordText, size_t lenTxt, char table[][TABLE_DIMENSIONS] ) {
    string text = "";
    for ( size_t i=0; i<lenTxt; i++ )
        text+=table[coordText[i].row][coordText[i].col];
    delete[] coordText;
    return text;
}

Coordinates * findAllCoordOfText ( string text,  size_t lenTxt, char table[][TABLE_DIMENSIONS], Coordinates cooSubstitute ) {
    Coordinates * coordText= new Coordinates [lenTxt];

    for ( size_t i=0; i<lenTxt; i++ ) {
        coordText[i]=findCoordInTable(text[i],table);
        if ( coordText[i].col == TABLE_DIMENSIONS ) //symbol not in table
            coordText[i] = cooSubstitute;
    }

    return coordText;
}

Coordinates findCoordInTable ( char c, char table[][TABLE_DIMENSIONS] ) {
    for ( size_t row=0; row<TABLE_DIMENSIONS; row++ )
        for ( size_t col=0; col<TABLE_DIMENSIONS; col++ )
            if( table[row][col]==c )
                return Coordinates {row,col};

    return Coordinates {TABLE_DIMENSIONS,TABLE_DIMENSIONS};
}

void shiftCoordidantesOfText ( Coordinates * coordText, size_t lenText, Coordinates cooSubstitute ) {
    for ( size_t i=0; i<lenText; i=i+2 )
        shiftCoordidantes(coordText[i],coordText[i+1],cooSubstitute);
}

void shiftCoordidantes( Coordinates & cooLetter1, Coordinates & cooLetter2, Coordinates cooSubstitute ) {
    if ( cooLetter1.row == cooLetter2.row && cooLetter1.col == cooLetter2.col )
        if ( cooLetter1.row == cooSubstitute.row && cooLetter1.col == cooSubstitute.col )
            return;
        else {
            cooLetter2 = cooSubstitute;
            shiftCoordidantes(cooLetter1,cooLetter2,cooSubstitute);
        }
    else if (cooLetter1.row == cooLetter2.row) {
        cooLetter1.col = (cooLetter1.col+1)%TABLE_DIMENSIONS;
        cooLetter2.col = (cooLetter2.col+1)%TABLE_DIMENSIONS;
    } else if (cooLetter1.col == cooLetter2.col) {
        cooLetter1.row = (cooLetter1.row+1)%TABLE_DIMENSIONS;
        cooLetter2.row = (cooLetter2.row+1)%TABLE_DIMENSIONS;
    } else {
        swap(cooLetter1.col,cooLetter2.col);
    }
}

void strToUpper ( string & str ) {
    size_t lenStr = str.length();
    for ( size_t i=0; i<lenStr; i++ )
        str[i]=(char)toupper(str[i]);
}


int main() {
    string text;
    char substitute = 'X';
    char table[TABLE_DIMENSIONS][TABLE_DIMENSIONS];

    fillTable(table);
    cin.seekg(0,ios::end);
    cin.clear();
    getline(cin,text);

    if ( tableIsCorrect(table) ) {
        if ( findCoordInTable(substitute,table).col==TABLE_DIMENSIONS )
            substitute = 'Y';


        cout <<transformText(text,table,substitute)<< endl;
    }
    else
        cout<<"Bad table!"<<endl;


    return 0;
}
