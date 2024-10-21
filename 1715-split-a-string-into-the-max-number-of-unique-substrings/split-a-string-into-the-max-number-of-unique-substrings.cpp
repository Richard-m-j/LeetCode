class Solution {
private:
    unordered_set<string> subs;
    int res = 0;
    void dfs(string &s, int idx){
        if(subs.size()>res)
            res = subs.size();
        if(idx>=s.length())
            return;
        string curr = "";
        for(int i = idx;i<s.length();i++){
            curr += s[i];
            if(!subs.count(curr)){
                subs.insert(curr);
                dfs(s,i+1);
                subs.erase(curr);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        dfs(s,0);
        return res;
    }
};