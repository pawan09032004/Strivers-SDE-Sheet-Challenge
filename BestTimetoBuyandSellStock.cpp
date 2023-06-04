#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int minimum = prices[0];
    int maxprofit = 0;
    int n = prices.size();
    for(int i=1; i<n; i++){
        int cost = prices[i] - minimum;
        maxprofit = max(maxprofit, cost);
        minimum = min(minimum, prices[i]);
    }
    return maxprofit;
}
