// Last updated: 7/24/2025, 8:22:52 AM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<int> res;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                if(x==words[i][j]){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};