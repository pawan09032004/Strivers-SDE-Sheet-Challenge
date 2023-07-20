#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    int m=p.size();
    vector<int> pre(m,0);
    int i=1,len=0;
    while(i<m)
    {
        if(p[len]==p[i])
        {
            len++;
            pre[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                pre[i]=0;
                i++;
            }
            else
            {
                len=pre[len-1];   
            }
        }
    }
    int n=s.size();
    i=0;
    int j=0;
    while(i<n)
    {
        if(s[i]==p[j])
        {
            i++; j++;
            if(j==m)
            {
                return true;

            }
        }
        else if(i<n && s[i]!=p[j])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=pre[j-1];
            }   
        }
    }
    return false;
}
