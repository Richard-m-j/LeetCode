// Last updated: 7/24/2025, 8:28:41 AM
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<int> maxFreq(26,0);
        for(string& s: words2){
            vector<int> mp(26,0);
            for(char& c: s)
                mp[c-'a']++;
            for(int i=0;i<26;i++)
                maxFreq[i] = max(maxFreq[i],mp[i]);
        }
        vector<string> res;
        for(string& s: words1){
            vector<int> mp(26,0);
            for(char& c: s)
                mp[c-'a']++;
            int i;
            for(i=0;i<26;i++)
                if(mp[i]<maxFreq[i])
                    break;
            if(i==26)
                res.push_back(s);
        }
        return res;
    }
};