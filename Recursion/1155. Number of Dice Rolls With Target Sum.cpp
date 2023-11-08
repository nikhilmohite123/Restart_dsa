// You have n dice, and each die has k faces numbered from 1 to k.
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/


#include<iostream>
using namespace std;





int numRollsToTarget(int n, int k, int target) {
        if(n>target)return 0;

        if(n==0 && target==0){
            return 1;
        }
        if(n!=0 && target<=0 ){
            return 0;
        }
        if(n==0 && target!=0){
            return 0;
        }
        if(target<0){
            return 0;
        }


int ans=0;
for(int i=1; i<=k; i++){
    ans=ans+numRollsToTarget(n-1,k,target-i);
}
return ans;

    }

    int main(){
        int n,k,target;
        n=3;
        k=2;
        target=4;
        cout<<numRollsToTarget(n,k,target);
    }