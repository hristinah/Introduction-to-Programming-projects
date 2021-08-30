#include <iostream>

using namespace std;

void printAllFormulasForN(short unsigned int n);
void findAndPrintAllFormulas(short unsigned int n, short unsigned int remaining, short int last, short unsigned int summandsTable[]);
void printFormula(short unsigned int n, short int last, short unsigned int summandsTable[]);


void printAllFormulasForN(short unsigned int n) {
    short unsigned int summandsTable[32]={0}; // n<=32 so there can be no more than 32 summands in any formula
    findAndPrintAllFormulas(n,n,-1,summandsTable);
}

void findAndPrintAllFormulas(short unsigned int n, short unsigned int remaining, short int last, short unsigned int summandsTable[]) {
    if(remaining==0)
        printFormula(n,last,summandsTable);
    else
        for(short unsigned int i=remaining; i>=1; i--)
            if( last==-1 || i<=summandsTable[last] ) {
                summandsTable[last+1]=i;
                findAndPrintAllFormulas(n,(remaining-i),(last+1),summandsTable);
            }
}

void printFormula(short unsigned int n, short int last, short unsigned int summandsTable[]) {
    cout<<n<<" = "<<summandsTable[0];
    for(short unsigned int i=1; i<=last; i++)
        cout<<" + "<<summandsTable[i];
    cout<<endl;
}

int main() {
    short unsigned int n;
    cin>>n;
    printAllFormulasForN(n);
    return 0;
}
