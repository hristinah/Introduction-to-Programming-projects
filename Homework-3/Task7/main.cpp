#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

void printStringInPigLatin( string str );
string translateWord( string word );
size_t findBeginningOfWord( string str, size_t pos );
size_t findEndingOfWord( string str, size_t pos );
size_t findFirstVowel( string word );
bool allLettersAreUpper( string word );
bool isVowel( char c );

void printStringInPigLatin( string str ) {
    size_t lenStr=str.length();
    if(!str.empty()) {
        size_t beginningWord, endingWord=0;
        string twistedWord;
        beginningWord=findBeginningOfWord(str,endingWord);

        while(beginningWord<lenStr) {
            cout<<str.substr(endingWord,beginningWord-endingWord); //unchanged part of string
            endingWord=findEndingOfWord(str,beginningWord);

            if(endingWord>=lenStr) {  //the ending of word is the ending of the string
                cout<<translateWord(str.substr(beginningWord));
                return;
            } else {
                cout<<translateWord(str.substr(beginningWord,endingWord-beginningWord));
                beginningWord=findBeginningOfWord(str,endingWord);
            }
        }
        cout<<str.substr(endingWord)<<endl;
    }
}

string translateWord( string word ) {
    string additionIfVowelFirst, additionIfConsonantFirst;
    bool allUpper=allLettersAreUpper(word);

    if(allUpper) {
    additionIfVowelFirst="WAY";
    additionIfConsonantFirst="AY";
    } else {
    additionIfVowelFirst="way";
    additionIfConsonantFirst="ay";
    }


    if (isVowel(word[0]))
        return word+additionIfVowelFirst;
    else {
        size_t pos=findFirstVowel(word);
        if(isupper(word[0]))
            if(allUpper)
                return (char)toupper(word[pos]) + word.substr(pos+1) + word.substr(0,pos) + additionIfConsonantFirst ;
            else
                return (char)toupper(word[pos]) + word.substr(pos+1) + (char)tolower(word[0]) + word.substr(1,pos-1) + additionIfConsonantFirst ;
        else
            return word.substr(pos) + word.substr(0,pos) + additionIfConsonantFirst ;
    }

}

size_t findBeginningOfWord( string str, size_t pos ) {
    size_t lenStr=str.length();
    while(pos<lenStr) {
        if( isalpha(str[pos]) )
            return pos;
        else
            pos++;
    }
    return pos;
}

size_t findEndingOfWord( string str, size_t pos ) {
    size_t lenStr=str.length();
    while(pos<lenStr) {
        if( !isalpha(str[pos]) ) {
            if( str[pos]=='-' && pos>=1 && (pos+1)<lenStr && isalpha(str[pos-1]) && isalpha(str[pos+1]) ) //'-' can connect two words
                pos++;
            else
                return pos;
        }
        else
        pos++;
    }
    return pos;
}

size_t findFirstVowel( string word ) {
    size_t pos=0;
    size_t lenWord=word.length();
    while(pos<lenWord) {
        if( isVowel(word[pos]) )
            return pos;
        else
            pos++;
    }
    return pos;
}

bool allLettersAreUpper( string word ) {
    size_t lenWord=word.length();
    if (lenWord==1)
        return false;
    else
        for (size_t i=0; i<lenWord; i++)
            if ( islower(word[i]) )
                return false;
    return true;
}

bool isVowel( char c ) {
    return ( c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U' || c=='y' || c=='Y' );
}

int main()
{
    string str;
    getline(cin,str);
    printStringInPigLatin(str);
    return 0;
}
