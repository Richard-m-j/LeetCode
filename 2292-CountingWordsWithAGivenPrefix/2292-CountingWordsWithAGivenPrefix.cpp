// Last updated: 7/24/2025, 8:24:42 AM
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(int i=0;i<words.size();i++){
            int j;
            for(j=0;j<pref.length();j++)
                if(words[i][j] !=pref[j])
                    break;
            if(j == pref.length())
                res++;
        }
        return res;
    }
};