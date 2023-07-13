#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &strs, int n)
{
    sort(strs.begin(), strs.end());

    string s = strs[0], t = strs[strs.size() - 1];
    int l = s.length(), m = t.length();
    int c = 0;
    string ans = "";
    for (int i = 0; i < min(l, m); i++)
    {
        if (s[i] == t[i])
        {
            ans += s[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}


