#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &arr)
{
    stack<int> st;
    st.push(0);
    vector<int> ans;
    ans.push_back(1);
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        int x = st.empty() ? i + 1 : i - st.top();
        ans.push_back(x);
        st.push(i);
    }
    return ans;
}
