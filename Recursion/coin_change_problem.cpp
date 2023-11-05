#include <iostream>
#include <climits>
using namespace std;
// minimum no of coin required to create to target
// infinite supply of uniqu coins
int solve(int *a, int n, int target)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {

        
        int ans = solve(a, n, target - a[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

// int solve2(int *a,int n,int &target,int op){
//   if(op==target){
//     return 0;
//   }
//   if(target<op){
//     return INT_MAX;
//   }
//   int mini=INT_MAX;
//   for(int i=0; i<n; i++){
//     int ans=solve2(a,n,target,op+a[i]);
//     if(ans!=INT_MAX){
//       mini=min(mini,ans+1);
//     }
//   }
//   return mini;
// }
int main()
{
    int a[] = {2, 4, 10};
    int target = 10;

    cout << solve(a, 3, target);
}