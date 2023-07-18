int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,0));
	for(int i=0;i<=n;i++){
		dp[0][i]=i*price[0];
	}
	for(int idx=1;idx<n;idx++){
		for(int N=0;N<=n;N++){
			int nottake=0+dp[idx-1][N];
			int rodlength=idx+1;
			int take=INT_MIN;
			if(rodlength<=N){
				take=price[idx]+dp[idx][N-rodlength];
			}
			dp[idx][N]=max(take,nottake);
		}
	}
	return dp[n-1][n];
}
