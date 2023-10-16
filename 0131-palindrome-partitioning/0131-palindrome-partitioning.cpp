class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        n = s.length();
        func(s,0,path,res);
        return res;
    }
    void func(string s, int index, vector<string> &path,vector<vector<string>> &res)
    {
        if(index == n)
        {
            res.push_back(path);
            return;
        }
        for(int i = index; i<n; i++)
        {
            if(isPalin(s,index,i))
            {
                path.push_back(s.substr(index, i - index + 1));
                func(s,i+1,path,res);
                path.pop_back();
            }
        }
    }
    bool isPalin(string s, int start, int end)
    {
        while(start <= end)
            if(s[start++] != s[end--])
                return false;
        return true;
    }
    private:
        int n;
    
};