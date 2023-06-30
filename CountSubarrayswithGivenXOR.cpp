#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int xxor = 0;
    map<int, int> visited;
    visited[xxor]++;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xxor = xxor ^ arr[i];
        int a = xxor ^ x;
        cnt += visited[a];
        visited[xxor]++;
    }
    return cnt;
}
