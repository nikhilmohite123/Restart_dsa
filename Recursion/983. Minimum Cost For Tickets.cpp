// https://leetcode.com/problems/minimum-cost-for-tickets/
#include <iostream>
#include <vector>
using namespace std;

int mincostTickets_helper(vector<int> &days, vector<int> &costs, int i)
{

    //    bs

    if (i >= days.size())
    {
        return 0;
    }
    // ek case la solution

    // using 1 day pass
    int ans1 = costs[0] + mincostTickets_helper(days, costs, i + 1);

    // using 7days pass
    int endpass = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= endpass)
    {
        j++;
    }
    int ans2 = costs[1] + mincostTickets_helper(days, costs, j);

    // 30 days of pass
    endpass = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= endpass)
    {
        j++;
    }
    int ans3 = costs[2] + mincostTickets_helper(days, costs, j);

    int ans = min(ans1, min(ans2, ans3));
    return ans;
}

int main()
{

    vector<int> days = {1, 3, 4, 7, 9, 13};
    vector<int> costs = {2, 5, 30};
    int i = 0;
    cout << mincostTickets_helper(days, costs, i);
}