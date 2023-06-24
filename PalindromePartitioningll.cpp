#include <bits/stdc++.h> 

bool ispalindrome(int i, int j, string s){
    while(i<j){
        if(s[i] != s[j] ){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int fun(int i, int n, string &str, vector<int> &dp){
    if(i==n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int mc = INT_MAX;
    for(int j=i ; j<n ; j++){
        if(ispalindrome(i,j,str)) {
            int c = 1 + fun(j+1, n , str , dp);
            mc = min(mc,c);
        }
    }
    return dp[i] = mc;
}
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    return fun(0,n,str,dp) - 1;
}
