// Last updated: 7/24/2025, 8:32:48 AM
static const int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
private:
    vector<vector<int>> res;
    int k, n;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        Solution:: k = k;
        Solution:: n = n;
        vector<int> currentList;
        findCombo(currentList,0,0);
        return res;
    }
    void findCombo(vector<int>&currentList, int currentSum, int index)
    {
        if(currentSum > n)
            return;
        if(currentList.size() < k)
        {
            for(int i = index+1; i<=9;i++)
            {
                currentList.push_back(i);
                findCombo(currentList, currentSum + i, i);
                currentList.pop_back();
            }
        }
        if(currentSum == n && currentList.size() == k)
        {
            res.push_back(currentList);
            return;
        }
    }
};