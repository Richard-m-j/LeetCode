// Last updated: 7/24/2025, 8:22:19 AM
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banSet;
        for(auto& s: bannedWords)
            banSet.insert(s);
        int count =0;
        for(auto& s: message)
            if(banSet.find(s)!=banSet.end()){
                count++;
                if(count==2)
                    return true;
            }
        return false;
    }
};