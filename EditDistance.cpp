#include <bits/stdc++.h>

int editDistance(string word1, string word2)
{

        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        int n=word1.length(),m=word2.size();

        for(int ind1=0;ind1<=n;ind1++){
            dp[ind1][m]=n-ind1;
        }

        for(int ind2=0;ind2<=m;ind2++){
            dp[n][ind2]=m-ind2;
        }

        for(int ind1=n-1;ind1>=0;ind1--){
            for(int ind2=m-1;ind2>=0;ind2--){

                if(word1[ind1]==word2[ind2]){
                    dp[ind1][ind2]=dp[ind1+1][ind2+1];
                }
                else{
                    int insert=1+dp[ind1][ind2+1];
                    int Delete=1+dp[ind1+1][ind2];
                    int replace=1+dp[ind1+1][ind2+1];

                    dp[ind1][ind2] = min({insert,Delete,replace});
                }
            }
        }

        return dp[0][0];
}
