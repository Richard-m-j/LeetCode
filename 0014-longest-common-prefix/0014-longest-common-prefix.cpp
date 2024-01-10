class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        int j = 0;
        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            int m = strs[i].size();
            mini = min(mini,m); 
        }

        for(int i=0;i<mini;i++)
        {
            char ch = strs[0][i];
            int j;
            for(j=1;j<n;j++)
            {
                if(ch != strs[j][i])
                    break;
            }
            if(j < n)
                break;
            ans += ch;      
        }
        return ans;
    }
};