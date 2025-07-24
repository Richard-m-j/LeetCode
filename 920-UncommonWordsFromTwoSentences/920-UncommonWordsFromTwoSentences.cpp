// Last updated: 7/24/2025, 8:28:48 AM
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        string word = "";
        for(int i=0;i<s1.length();i++){
            if(s1[i] == ' '){
                mp[word]++;
                word = "";
            }
            else
                word += s1[i];
        }
        mp[word]++;
        word = "";
        for(int i=0;i<s2.length();i++){
            if(s2[i] == ' '){
                mp[word]++;
                word = "";
            }
            else
                word += s2[i];
        }
        mp[word]++;
        vector<string> res;
        for(auto& it: mp)
            if(it.second == 1)
                res.push_back(it.first);
        return res;
    }
};