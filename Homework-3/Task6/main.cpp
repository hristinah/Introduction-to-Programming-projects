#include <iostream>

using namespace std;

void printContentsOfArrays(unsigned int * fn, unsigned short int * n, float * p, size_t countLines);
void fillArrays(unsigned int * fn, unsigned short int * n, float * p, size_t countLines);
void insertCurrentData(unsigned int * fn, unsigned short int * n, float * p, size_t countCurrentLines,
                            unsigned int currentFn, unsigned short int currentN, float currentP );
size_t findPositionToInsert(unsigned int * fn, unsigned short int * n, float * p, int leftIndex, int rightIndex,
                            unsigned int currentFn, unsigned short int currentN, float currentP );
short int compare(unsigned int fnFirst, unsigned short int nFirst, float pFirst,
                  unsigned int fnSecond, unsigned short int nSecond, float pSecond);


void printContentsOfArrays(unsigned int * fn, unsigned short int * n, float * p, size_t countLines) {
    for(size_t i=0; i<countLines; i++) {
        cout<<fn[i]<<" "<<n[i]<<" "<<p[i]<<endl;
    }
}

void fillArrays(unsigned int * fn, unsigned short int * n, float * p, size_t countLines) {
    unsigned int currentFn;
    unsigned short currentN;
    float currentP;

    for(size_t i=0; i<countLines; i++) {
        cin>>currentFn>>currentN>>currentP;
        insertCurrentData(fn,n,p,i,currentFn,currentN,currentP);
    }
}

void insertCurrentData(unsigned int * fn, unsigned short int * n, float * p, size_t countCurrentLines,
                            unsigned int currentFn, unsigned short int currentN, float currentP ) {
    if (countCurrentLines==0) {
        fn[0]=currentFn;
        n[0]=currentN;
        p[0]=currentP;
    } else {
        size_t pos=findPositionToInsert(fn,n,p,0,countCurrentLines-1,currentFn,currentN,currentP);

        for(size_t i=countCurrentLines; i>pos; i--) {
            fn[i]=fn[i-1];
            n[i]=n[i-1];
            p[i]=p[i-1];
        }
        fn[pos]=currentFn;
        n[pos]=currentN;
        p[pos]=currentP;
    }
}

//the function uses binary search on anlready sorted arrays to locate the corret position for the current elements faster
size_t findPositionToInsert(unsigned int * fn, unsigned short int * n, float * p, int leftIndex, int rightIndex,
                            unsigned int currentFn, unsigned short int currentN, float currentP ) {
    if (rightIndex <= leftIndex) {
        if (compare(currentFn,currentN,currentP,fn[leftIndex],n[leftIndex],p[leftIndex])==-1)
            return leftIndex + 1;
        else
            return leftIndex;
    }

    int midIndex = (leftIndex + rightIndex) / 2;

    if (compare(currentFn,currentN,currentP,fn[midIndex],n[midIndex],p[midIndex])==0)
        return midIndex + 1;


    if (compare(currentFn,currentN,currentP,fn[midIndex],n[midIndex],p[midIndex])==-1)
        return findPositionToInsert(fn,n,p,midIndex+1,rightIndex,currentFn,currentN,currentP);
    else
        return findPositionToInsert(fn,n,p,leftIndex,midIndex-1,currentFn,currentN,currentP);
}


//function returns -1 if first is bigger, 1 if second, and 0 if they are equal
short int compare(unsigned int fnFirst, unsigned short int nFirst, float pFirst,
                  unsigned int fnSecond, unsigned short int nSecond, float pSecond) {
    if(fnFirst>fnSecond)
        return -1;
    if(fnFirst<fnSecond)
        return 1;

    if(nFirst>nSecond)
        return -1;
    if(nFirst<nSecond)
        return 1;

    if(pFirst>pSecond)
        return -1;
    if(pFirst<pSecond)
        return 1;

    return 0;
}


int main() {
    size_t countLines;
    unsigned int * fn;
    unsigned short int * n;
    float * p;

    cin>>countLines;
    fn=new unsigned int [countLines];
    n=new unsigned short int [countLines];
    p=new float [countLines];

    fillArrays(fn,n,p,countLines);

    printContentsOfArrays(fn,n,p,countLines);

    delete[] fn;
    delete[] n;
    delete[] p;

    return 0;
}
