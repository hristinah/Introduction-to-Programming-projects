#include <iostream>

using namespace std;

void inputNumberAndConvert();
void toRoman(int);
void showThousands(int);
void showHundreds(int);
void showTens(int);
void showOnes(int);

void toRoman(int number) {
    if (number<=0||number>3000)
        cout<<"Invalid number!"<<endl;
    else
    {
        int quotient1000=number/1000;
        number=number%1000;
        showThousands(quotient1000);

        int quotient100=number/100;
        number=number%100;
        showHundreds(quotient100);

        int quotient10=number/10;
        number=number%10;
        showTens(quotient10);

        showOnes(number);

        cout<<endl;
    }
}

void showThousands(int quotient1000) {
    switch(quotient1000) {
        case 3:
            cout<<"MMM";
            break;
        case 2:
            cout<<"MM";
            break;
        case 1:
            cout<<"M";
            break;
    }
}

void showHundreds(int quotient100) {
    switch(quotient100) {
        case 9:
            cout<<"CM";
            break;
        case 8:
            cout<<"DCCC";
            break;
        case 7:
            cout<<"DCC";
            break;
        case 6:
            cout<<"DC";
            break;
        case 5:
            cout<<"D";
            break;
        case 4:
            cout<<"CD";
            break;
        case 3:
            cout<<"CCC";
            break;
        case 2:
            cout<<"CC";
            break;
        case 1:
            cout<<"C";
            break;
    }
}

void showTens(int quotient10) {
    switch(quotient10) {
        case 9:
            cout<<"XC";
            break;
        case 8:
            cout<<"LXXX";
            break;
        case 7:
            cout<<"LXX";
            break;
        case 6:
            cout<<"LX";
            break;
        case 5:
            cout<<"L";
            break;
        case 4:
            cout<<"XL";
            break;
        case 3:
            cout<<"XXX";
            break;
        case 2:
            cout<<"XX";
            break;
        case 1:
            cout<<"X";
            break;
    }
}

void showOnes(int number) {
    switch(number) {
        case 9:
            cout<<"IX";
            break;
        case 8:
            cout<<"VIII";
            break;
        case 7:
            cout<<"VII";
            break;
        case 6:
            cout<<"VI";
            break;
        case 5:
            cout<<"V";
            break;
        case 4:
            cout<<"IV";
            break;
        case 3:
            cout<<"III";
            break;
        case 2:
            cout<<"II";
            break;
        case 1:
            cout<<"I";
            break;
    }
}

void inputNumberAndConvert() {
    int number;
    cin>>number;
    toRoman(number);
}


int main() {
    inputNumberAndConvert();
    return 0;
}
