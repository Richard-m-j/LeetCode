// Last updated: 7/24/2025, 8:26:19 AM
int speed = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    unordered_set<string> subs;
    int res = 0;
    void dfs(string &s, int idx,int unique){

        res = max(res,unique);
        if(unique + s.size() - idx <= res)
            return;
        if(idx>=s.length())
            return;
        for(int i = idx;i<s.length();i++){
            string curr = s.substr(idx, i - idx + 1);
            if(!subs.count(curr)){
                subs.insert(curr);
                dfs(s,i+1,unique+1);
                subs.erase(curr);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        dfs(s,0,0);
        return res;
    }
};