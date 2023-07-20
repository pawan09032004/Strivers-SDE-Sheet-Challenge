#include<bits/stdc++.h>
long long int help(int i,int *denominations, int n, int value,vector<vector<long long int>> &dp)
{
    if(i==0)
    {
        return (value%denominations[i]==0);
    }
    if(dp[i][value]!=-1)
    {
        return dp[i][value];
    }
    long take=0;
    if(value>=denominations[i])
    {
        take=help(i,denominations,n,value-denominations[i],dp);
    }
    long nt=help(i-1,denominations,n,value,dp);
    return dp[i][value]=nt+take;

}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long long int>> dp(n,vector<long long int>(value+1,0));
    for(int t=0;t<=value;t++)
    {
        dp[0][t]=(t%denominations[0]==0);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=value;j++)
        {
            long take=0;
            if(j>=denominations[i])
            {
                take=dp[i][j-denominations[i]];
            }
            long nt=dp[i-1][j];
            dp[i][j]=nt+take;
        }
    }
    return dp[n-1][value];
}
