#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    unordered_map<int,int>mp;
       for(int i=0;i<n;i++)
       {
           mp[nums[i]]++;
       }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      for(auto it:mp)
      {
          pq.push({it.second,it.first});
          if(pq.size()>k)
          pq.pop();
      }
      vector<int>ans(k);
      while(!pq.empty())
      {
         ans[k-1]=(pq.top().second);
         k--;
          pq.pop();
      }
      sort(ans.begin(),ans.end());
      return ans;
}
