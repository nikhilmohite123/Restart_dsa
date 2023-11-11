#include <iostream>
#include <vector>
using namespace std;
// tc=O(nlogn *logn) sc=o(1);
// gap _method
void merge(vector<int> &a, int s, int e)
{

    int total_legth = (e - s + 1);
    int gap = (total_legth / 2) + (total_legth % 2);

    while (gap > 0)
    {
        int j = s + gap, i = 0;
        while (j <= e)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
            i++;
            j++;
        }
        gap=gap==1?0:(gap/2)+(gap%2);
    }
}

void mergeSort(vector<int> &a, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int m = (s + e) / 2;
    mergeSort(a, s, m);
    mergeSort(a, m + 1, e);
    merge(a, s, e);
}

int main()
{
    vector<int> a = {5, 2, 3, 1, 9, 2, 1};
    int s = 0, e = a.size() - 1;
    for (int i = 0; i <= e; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    mergeSort(a, s, e);
    for (int i = 0; i <= e; i++)
    {
        cout << a[i] << " ";
    }
}