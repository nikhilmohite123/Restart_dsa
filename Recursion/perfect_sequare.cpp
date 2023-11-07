// Given an integer n, return the least number of perfect square numbers that sum to n.


#include<iostream>
#include<cmath>
#include<climits>
using namespace std;


int numSquares(int n){
    if(n==0){
        return 0;
    }

int i=1,end=sqrt(n);
int ans=INT_MAX;

while(i<=end){
    int perfectSeq=i*i;
    int numbers=numSquares(n-perfectSeq)+1;
    ans=min(ans,numbers);
    i++;
}
return ans;


}

int main(){
    int n;
    cin>>n;

    cout<<numSquares(n);
}