#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int N, int K){
	priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>st;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        pq.push({A[N-1]+B[N-1],{N-1,N-1}});
        st.insert({N-1,N-1});
        vector<int>ans;
        while(!pq.empty() && K>0)
        {
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.first);
            int L=it.second.first;
            int R=it.second.second;
            if(L>0  && st.find({L-1,R})==st.end())
            {
                pq.push({A[L-1]+B[R],{L-1,R}});
                st.insert({L-1,R});
            }
             if(R>0 && st.find({L,R-1})==st.end())
            {
                pq.push({A[L]+B[R-1],{L,R-1}});
                st.insert({L,R-1});
            }
            K--;
        }
        return ans;
}
