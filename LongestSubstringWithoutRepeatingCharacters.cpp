#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
  if (s.length() == 0) {
    return 0;
  }
  
  unordered_map<char,int> m;  
        int a=0,b=0,ans=INT_MIN; 
        while(b<s.length())   
        {
            m[s[b]]++;  
            if(m.size()==b-a+1)  
            {
                ans = max(ans,b-a+1); 
            }
            else if(m.size()<b-a+1)  
            {
                while(m.size()<b-a+1)  
                {
                    m[s[a]]--; 
                      
                    if(m[s[a]]==0)  
                    {
                        m.erase(s[a]);
                    }
                    a++; 
                }
            }
             b++;  
        }
        return ans;
}
