class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=0;
        vector<int> mp(26,0);
        for(char& c:allowed)
            mp[c-'a']++;
        for(auto& word: words){
            bool consistent = true;
            for(char&c:word){
                if(!mp[c-'a']){
                    consistent = false;
                    break;
                }
            }
            if(consistent)
                res++;
        }
        return res;
    }
};