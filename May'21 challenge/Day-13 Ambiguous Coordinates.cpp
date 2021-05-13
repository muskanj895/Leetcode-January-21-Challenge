class Solution {
public:
           vector <string> helper(string s)
    {
        vector <string> v;
        if(s.size()<2)
            return {s};
        int n=s.size();
        if(s[0]=='0')
        {
             if(s[n-1]=='0')
                 return {};
            string t=s.substr(0,1)+ '.' + s.substr(1); // if s[0] is 0, only possible solution is 0.xxxxx where last digit!=0
            return {t};
        }
        if(s[n-1]=='0')
            return {s}; // if last digit is 0, only possible solution is the string itself
        for(int i=0;i<n-1;i++)
        {
            v.push_back(s.substr(0,i+1)+'.'+s.substr(i+1)); // '.' in between all substrings
        }
        v.push_back(s);
        return v;
        
    }
    vector<string> ambiguousCoordinates(string s) {
        int n=s.size();
        
        vector <string> ans;
        vector <string> v1,v2;
        for(int i=1;i<n-2;i++)
        {
            v1.clear();
            v2.clear();
            v1= helper(s.substr(1,i));
            v2= helper(s.substr(i+1,n-i-2));
            cout<<s.substr(1,i)<<" "<<s.substr(i+1,n-i-2)<<" ";
            if(v1.empty() || v2.empty())
                continue;
            for(int a=0;a<v1.size();a++)
            {
                for(int b=0;b<v2.size();b++)
                {
                    ans.push_back('('+v1[a]+','+' '+v2[b]+')');
                }
            }
        }
        return ans;
    }
};
