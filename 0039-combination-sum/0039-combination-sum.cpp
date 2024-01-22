int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
private:
    vector<vector<int>> res;
    vector<int> candidates;
    int target,n;
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        candidates = c;
        target = t;
        n = candidates.size();
        helper({},0,0);
        return res;
        
    }
    void helper(vector<int> currentList, int currentSum,int i)
    {
        if(i == n)
        {
            if(currentSum == target)
                res.push_back(currentList);
            return;
        }
        if(candidates[i] + currentSum <= target)
        {
            currentList.push_back(candidates[i]);
            helper(currentList,currentSum + candidates[i],i);
            currentList.pop_back();
        }
        
        helper(currentList,currentSum,i+1);
    }
};