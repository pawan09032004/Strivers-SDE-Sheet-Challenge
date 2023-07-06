#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int start, int end, vector<vector<int>> &dp){
   
    if(start >= end) {dp[start][end]=1;return true;}

    if(dp[start][end] != -1) return dp[start][end];

    if(s[start]==s[end]) 
        dp[start][end] = isPalindrome(s, start+1, end-1,dp);

    else dp[start][end]=0;
    return dp[start][end];
}

string longestPalinSubstring(string str)
{
    int n = str.size();
    int mx = INT_MIN;
    int start = 0;
    int end = 0;
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(isPalindrome(str, i, j, dp) && mx < j-i+1){
                mx = j-i+1;
                start = i;
                end = j;
            }
        }
    }
    string ans="";
    for(int i=start;i<=end;i++){
        ans += str[i];
    }
    return ans;
}
