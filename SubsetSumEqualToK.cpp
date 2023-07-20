#include <bits/stdc++.h>
bool help(int i,int n, int k, vector<int> &arr,vector<vector<int>> &dp)
{
    if(0==k)
    {
        return true;
    }
    if(i==arr.size())
    {
        return false;
    }
    if(dp[i][k]!=-1)
    {
        return dp[i][k];
    }
    bool ex=help(i+1,n,k,arr,dp);
    // sum+=arr[i];
    bool in=false;
    if(arr[i]<=k)
    {
        in=help(i+1,n,k-arr[i],arr,dp);
    }
    // bool 
    // sum-=arr[i];
    return dp[i][k]=ex || in;
} 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    int sum=0;
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return help(0,n,k,arr,dp);
}
