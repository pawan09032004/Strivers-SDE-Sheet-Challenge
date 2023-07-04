#include <bits/stdc++.h>

void helper (vector <vector <int>> &final, vector <int> &temp, vector<int>& candidates, int target, int sum, int start) {

        if (sum == target) {
            final.push_back (temp);
            return;
        }
        if (sum > target) return;

        //Include it:
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) {
                continue; // skip duplicates
            }
            temp.push_back(candidates[i]);
            helper(final, temp, candidates, target, sum + candidates[i], i+1);
            temp.pop_back();

        }

    }

vector<vector<int>> combinationSum2(vector<int> &candidates, int n, int target)
{
	// Write your code here.
	sort(candidates.begin(), candidates.end());
        vector <vector <int>> final;
        vector <int> temp;
        helper (final, temp, candidates, target, 0, 0);

        return final;
}
