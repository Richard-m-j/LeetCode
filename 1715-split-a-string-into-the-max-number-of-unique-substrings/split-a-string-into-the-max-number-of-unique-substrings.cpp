int speed = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    unordered_set<string> subs;
    int res = 0;
        void dfs(const string &s, int idx, int uniqueCount) {
        // Update result with the maximum unique split
        res = max(res, uniqueCount);

        if (idx >= s.length())
            return;
        
        // For substring exploration, avoid concatenating each time
        for (int i = idx; i < s.length(); i++) {
            // Check the substring directly using slicing (no need to concatenate manually)
            string curr = s.substr(idx, i - idx + 1);
            
            if (!subs.count(curr)) {
                subs.insert(curr);
                // Increase uniqueCount when we find a new unique substring
                dfs(s, i + 1, uniqueCount + 1);
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