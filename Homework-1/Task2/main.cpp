#include<iostream>
#include <string>

using namespace std;

void verifyAndPrint(long long int);
int * getDigits(long long int);
bool isControlCorrect(int *);
bool isMonthCorrect(int);
void updateMonthAndYear(int & , int &);
bool isDayCorrect(int , int , int);
void printDate(int , int , int);
void printGender(int);

void getAndHandleInput() {
    long long int idn;
    cin>>idn;
    verifyAndPrint(idn);
}

void verifyAndPrint(long long int idn)
{
    if(idn<1010000||idn>9952319999) cout<<"Bad input data!"<<endl;
    else {
        int year,month,day,gender;
        int * digits=getDigits(idn);
        year=digits[0]*10+digits[1];
        month=digits[2]*10+digits[3];
        day=digits[4]*10+digits[5];
        gender=digits[8];
        if (isControlCorrect(digits)&&isMonthCorrect(month)) {
            updateMonthAndYear(month, year);
            if (isDayCorrect(day, month, year)) {
                printDate(day, month, year);
                printGender(gender);
            }
            else {
                cout<<"Bad input data!"<<endl;
            }
        }
        else {
            cout<<"Bad input data!"<<endl;
        }
    }
}

int * getDigits(long long int idn) {
    int * digits=new int [10];
    for (int i=9; i>=0; i--) {
        digits[i]=idn%10;
        idn=idn/10;
    }
    return digits;
}

bool isControlCorrect(int * digits) {
    int idncontrol=digits[9];
    int sum=digits[0]*2 + digits[1]*4 + digits[2]*8 + digits[3]*5 +
    digits[4]*10 + digits[5]*9 + digits[6]*7 + digits[7]*3 + digits[8]*6;
    int sumRemainder=sum%11;
    return idncontrol==sumRemainder;
}

bool isMonthCorrect(int month) {
    if(month==0 ||(month>12 && month<=20)||(month>32 && month<=40)|| month>52) {
        return false;
    }
    return true;
}

void updateMonthAndYear(int & month , int & year) {
    if (month>=1&&month<=12)
        year=year+1900;
    else if (month>=21&&month<=32) {
        year=year+1800;
        month=month-20;
    }
    else if (month>=41&&month<=52) {
        year=year+2000;
        month=month-40;
    }
}

bool isDayCorrect(int day , int month , int year) {
    if ((month==1||month==3||month==7||month==8||month==12)&&(day==0||day>31)) // checking months with 31 days
        return false;
    else if ((month==4||month==6||month==9||month==10||month==11)&&(day==0||day>30)) // checking months with 30 days
        return false;
    else if ((month==5||((month==2)&&((year%4==0&&year%100!=0)||year%400==0)))&&(day==0||day>29)) // checking month with 29 days and febuary on leap years
        return false;
    else if((month==2)&&((year%4!=0)||(year%4==0&&year%100==0&&year%400!=0))&&(day==0||day>28)) // checking febuary on non-leap years
        return false;
    return true;
}

void printDate(int day , int month , int year) {
    if(day<10&&month<10)
        cout<<"0"<<day<<"."<<"0"<<month<<"."<<year<<" ";
    else if(day<10&&month>=10)
        cout<<"0"<<day<<"."<<month<<"."<<year<<" ";
    else if(day>=10&&month<10)
        cout<<day<<"."<<"0"<<month<<"."<<year<<" ";
    else
        cout<<day<<"."<<month<<"."<<year<<" ";
}

void printGender(int gender) {
    if(gender%2==0)
        cout<<"M"<<endl;
    else
        cout<<"F"<<endl;
}


int main() {
    getAndHandleInput();
    return 0;
}
