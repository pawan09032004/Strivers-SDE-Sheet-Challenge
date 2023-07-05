#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int K)
{
     priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                pq.push(arr[i][j]);
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
}
