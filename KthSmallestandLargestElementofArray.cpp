#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	
	 sort(nums.begin(),nums.end());
        
		return {nums[k-1],nums[n-k]};

}
