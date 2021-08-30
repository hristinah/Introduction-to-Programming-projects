#include <iostream>

using namespace std;

struct MobilePlan {
    unsigned int price;
    unsigned int minutes;
    unsigned int mgb;
    unsigned int sms;
};

void insertCurrentPlanInAcepptable( MobilePlan * acceptablePlans, int & countAcceptablePlans, MobilePlan currentPlan );
bool satisfiesNeeds ( MobilePlan plan, unsigned int minMinutes, unsigned int minMgb, unsigned int minSms );
size_t findPositionToInsert( MobilePlan * acceptablePlans, int leftIndex, int rightIndex, MobilePlan currentPlan );
int comparePlans ( MobilePlan planA, MobilePlan planB );

void insertCurrentPlanInAcepptable( MobilePlan * acceptablePlans, int & countAcceptablePlans, MobilePlan currentPlan ) {
    if (countAcceptablePlans==0) {
        acceptablePlans[0]=currentPlan;
    } else {
        size_t pos=findPositionToInsert(acceptablePlans,0,countAcceptablePlans-1,currentPlan);

        for(size_t i=countAcceptablePlans; i>pos; i--) {
            acceptablePlans[i]=acceptablePlans[i-1];
        }
        acceptablePlans[pos]=currentPlan;
    }
    countAcceptablePlans++;
}

size_t findPositionToInsert( MobilePlan * acceptablePlans, int leftIndex, int rightIndex, MobilePlan currentPlan ) {
    if (rightIndex <= leftIndex) {
        if (comparePlans(currentPlan,acceptablePlans[leftIndex])==-1)
            return leftIndex + 1;
        else
            return leftIndex;
    }

    int midIndex = (leftIndex + rightIndex) / 2;

    if (comparePlans(currentPlan,acceptablePlans[midIndex])==0)
        return midIndex + 1;


    if (comparePlans(currentPlan,acceptablePlans[midIndex])==-1)
        return findPositionToInsert(acceptablePlans,midIndex+1,rightIndex,currentPlan);
    else
        return findPositionToInsert(acceptablePlans,leftIndex,midIndex-1,currentPlan);
}

int comparePlans ( MobilePlan planA, MobilePlan planB ) {
    if (planA.price > planB.price)
        return -1;
    else if (planA.price == planB.price )
        return 0;
    else
        return 1;
}

bool satisfiesNeeds ( MobilePlan plan, unsigned int minMinutes, unsigned int minMgb, unsigned int minSms ) {
    return (plan.minutes>=minMinutes && plan.mgb>=minMgb && plan.sms>=minSms);
}

int main() {
    int n,countAcceptablePlans=0;
    unsigned int neededMinutes, neededMgb, neededSms;

    cin>>n;
    MobilePlan * allPlans = new MobilePlan [n];
    MobilePlan * acceptablePlans = new MobilePlan [n];

    for (int i=0; i<n; i++) {
        cin>>allPlans[i].price>>allPlans[i].minutes>>allPlans[i].mgb>>allPlans[i].sms;
    }
    cin>>neededMinutes>>neededMgb>>neededSms;

    for (int i=0; i<n; i++) {
        if (satisfiesNeeds(allPlans[i],neededMinutes,neededMgb,neededSms))
            insertCurrentPlanInAcepptable(acceptablePlans,countAcceptablePlans,allPlans[i]);
    }

    if(countAcceptablePlans>0)
        for (int i=0; i<countAcceptablePlans; i++)
            cout<<acceptablePlans[i].price<<" "<<acceptablePlans[i].minutes<<" "<<acceptablePlans[i].mgb<<" "<<acceptablePlans[i].sms<<endl;
    else
        cout<<"No solution"<<endl;
    delete[] allPlans;
    delete[] acceptablePlans;
    return 0;
}
