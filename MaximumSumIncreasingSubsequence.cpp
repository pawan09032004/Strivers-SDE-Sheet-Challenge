#include <bits/stdc++.h>
int help(vector<int> &rack, int n,int curr,int prev,vector<vector<int>> &dp)
{
	if(curr>=n)
	{
		return 0;
	}
	if(dp[curr][prev+1]!=-1)
	{
		return dp[curr][prev+1];
	}
	int ex=help(rack,n,curr+1,prev,dp);
	int in=0;
	if(prev==-1 || rack[curr]>rack[prev])
	{
		in=rack[curr]+help(rack,n,curr+1,curr,dp);
	}
	return dp[curr][prev+1]=max(in,ex);
} 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return help(rack,n,0,-1,dp);
}
