#include <iostream>
#include <string>

using namespace std;


string twistString( string str, unsigned int n );
string twistWord( string word, unsigned int n );
size_t findBeginningOfWord( string str, size_t pos );
size_t findEndingOfWord( string str, size_t pos );
bool isRomanLetter( char c );


string twistString( string str, unsigned int n ) {
    size_t lenStr=str.length();
    if(!str.empty()) {
        size_t beginningWord, endingWord=0, lenWord;
        string twistedWord;
        beginningWord=findBeginningOfWord(str,endingWord);

        while(beginningWord<lenStr) {
            endingWord=findEndingOfWord(str,beginningWord);

            if(endingWord>=lenStr) {  //the ending of word is the ending of the string
                lenWord=lenStr-beginningWord;
                twistedWord=twistWord(str.substr(beginningWord),n);
                str.replace(beginningWord,lenWord,twistedWord);
                return str;
            } else {
                lenWord=endingWord-beginningWord;
                twistedWord=twistWord(str.substr(beginningWord,lenWord),n);
                str.replace(beginningWord,lenWord,twistedWord);
                beginningWord=findBeginningOfWord(str,endingWord);
            }
        }
    }
    return str;
}

string twistWord( string word, unsigned int n ) {
    size_t lenWord=word.length();
    n=n%lenWord;
    if( n==0 || lenWord==1 )
        return word;
    else
        return ( word.substr(lenWord-n) + word.substr(0,lenWord-n) );
}

size_t findBeginningOfWord( string str, size_t pos ) {
    size_t lenStr=str.length();
    while(pos<lenStr) {
        if( isRomanLetter(str[pos]) )
            return pos;
        else
            pos++;
    }
    return pos;
}

size_t findEndingOfWord( string str, size_t pos ) {
    size_t lenStr=str.length();
    while(pos<lenStr) {
        if( !isRomanLetter(str[pos]) ) {
            if( str[pos]=='-' && pos>=1 && (pos+1)<lenStr && isRomanLetter(str[pos-1]) && isRomanLetter(str[pos+1]) ) //'-' can connect two words
                pos++;
            else
                return pos;
        }
        else
        pos++;
    }
    return pos;
}

bool isRomanLetter( char c ){
    return ( (c>='a' && c<='z') || (c>='A' && c<='Z') );
}


int main() {
    string userInput;
    unsigned int n;
    getline(cin,userInput);
    cin>>n;
    cout<<twistString(userInput,n);
    return 0;
}
