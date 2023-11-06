// maximum number of segments

#include <iostream>
#include <climits>
using namespace std;
int solve3(int target, int x, int y, int z)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MIN;
    }

    int ans1 = solve3(target - x, x, y, z) + 1;
    int ans2 = solve3(target - y, x, y, z) + 1;
    int ans3 = solve3(target - z, x, y, z) + 1;

    int ans = max(ans1, max(ans2, ans3));
    return ans;
}
int main()
{

    int ans = solve3(8, 5, 5, 7);
    if (ans < 0)
    {
        cout << 0;
        return 0;
    }
    cout << ans;
}