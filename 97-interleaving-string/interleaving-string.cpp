class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length(), n = s2.length(), l= s3.length();
        if(m+n!=l)
            return false;
        if(!m)
            return s2 == s3;
        if(!n)
            return s1 == s3;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[m][n] = true;
        for (int i = m - 1; i >= 0; --i)
            dp[i][n] = (s1[i] == s3[i + n]) && dp[i + 1][n];
        

        for (int j = n - 1; j >= 0; --j) 
            dp[m][j] = (s2[j] == s3[m + j]) && dp[m][j + 1];
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j] = (s1[i] == s3[i+j]) && dp[i+1][j] || (s2[j] == s3[i+j]) && dp[i][j+1];
                cout<<dp[i][j]<<" ";
            }
        }
        return dp[0][0];
    }
};