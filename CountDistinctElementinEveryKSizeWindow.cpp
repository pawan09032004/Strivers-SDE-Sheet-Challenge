#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> ans;
    int n=arr.size();
    unordered_map<int,int> mp;
    int i;
    for(i=0;i<k;i++)
    {
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());
    i=k;
    while(i<n)
    {
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0)
        {
            mp.erase(arr[i-k]);
        }
        mp[arr[i]]++;
        ans.push_back(mp.size());
        i++;
    }
    return ans;

}
