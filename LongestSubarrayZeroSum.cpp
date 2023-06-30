#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{

    int maxi = 0;
    int sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (map.find(sum) != map.end())
                maxi = max(maxi, i - map[sum]);
            else
                map[sum] = i;
        }
    }
    return maxi;
}
