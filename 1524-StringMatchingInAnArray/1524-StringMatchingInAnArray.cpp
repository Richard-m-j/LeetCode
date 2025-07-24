// Last updated: 7/24/2025, 8:26:49 AM
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end());
        vector<string> res;
        for(int i=0;i<words.size();i++)
            for(int j=0;j<words.size();j++)
                if(i!=j && words[j].find(words[i]) != string::npos){
                    res.push_back(words[i]);
                    break;
                }

        return res;
    }
};