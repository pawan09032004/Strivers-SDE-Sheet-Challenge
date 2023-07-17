#include <bits/stdc++.h>
int f(int n, int k, vector<vector<int>> &dp){
    if(n<=1) return n;
    if(k==1) return n;
    if(dp[n][k]!=-1) return dp[n][k];
    int cnt=INT_MAX;
    int l=1,h=n;
    while(l<=h){
        int t=(l+h)/2;
        int right=f(n-t,k,dp);
        int left=f(t-1,k-1,dp);
        if(left<right){
            l=t+1;
        }else{
            h=t-1;
        }
        int cur=1+max(left,right);
        cnt=min(cnt,cur);
    }
    return dp[n][k]= cnt;
}

int cutLogs(int k, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
    return f(n,k,dp);
}



