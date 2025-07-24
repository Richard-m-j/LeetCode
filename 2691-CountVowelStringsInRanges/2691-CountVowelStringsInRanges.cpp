// Last updated: 7/24/2025, 8:23:31 AM
class Solution {
private:
    bool isVowel(char c){
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': return true;
        }
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> dp(n+1),res;
        dp[0]=0;
        for(int i=0;i<n;i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back())){
                dp[i+1] = dp[i] + 1;
            }
            else
                dp[i+1]=dp[i];
        }
        for(vector<int>& q: queries){
            res.push_back(dp[q[1]+1] - dp[q[0]]);
        }
        return res;
    }
};