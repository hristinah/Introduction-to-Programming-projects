#include <iostream>

using namespace std;

int main() {
    int n,number,modNum;
    cin>>n;
    int * helperArr = new int [3*n];
    int posInHelperArrOfNextWithModK[3] = {0, n, 2*n};
    int posInHelperArrOfFirstWithModK[3] = {0, n, 2*n};

    for(int i=0; i<n; i++) {
        cin>>number;
        modNum = number%3;
        if(modNum<0) modNum+=3;
        helperArr[ posInHelperArrOfNextWithModK[modNum] ] = number;
        posInHelperArrOfNextWithModK[modNum]++;
    }

    for(int i=0; i<3; i++)
        for(int j=posInHelperArrOfFirstWithModK[i]; j<posInHelperArrOfNextWithModK[i]; j++)
            cout<<helperArr[j]<<" ";

    cout<<endl;
	delete[] helperArr;
    return 0;
}
