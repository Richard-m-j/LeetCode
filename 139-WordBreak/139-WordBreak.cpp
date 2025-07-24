// Last updated: 7/24/2025, 8:33:46 AM
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<string> words;
        for(string& word: wordDict)
            words.insert(word);
        int n = s.length();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++)
                if(dp[j]&&words.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
        }
        return dp[n];
    }
};