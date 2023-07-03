#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	if(n<3)return {};
	vector<vector<int>> triplets;
    sort(nums.begin(), nums.end());
	for(int i = 0; i<n-2; i++){
        int start = i+1;
        int end = n-1;
        while(start<end){
                
            int sum = nums[i] + nums[start] + nums[end];
            if(sum == K){
                triplets.push_back({nums[i], nums[start], nums[end]});
                start++;
                end--;
                while(start<n && nums[start] == nums[start-1]){
					start++;
				}
					
                while(end>i && nums[end] == nums[end+1]){
					end--;
				}	
            }
			else if(sum>K){
                end--;
            } 
			else {
              start++;
            }
        }
        while (i < n - 1 && nums[i] == nums[i + 1])
          i++;
    }
    return triplets;
}
