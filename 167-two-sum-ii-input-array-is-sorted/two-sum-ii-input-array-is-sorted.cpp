class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, vector<int>> mp;
        vector<int> res;

        for (int i = 0; i < numbers.size(); i++) {
            if ((mp.find(numbers[i]) != mp.end()) && !mp[numbers[i]].empty()) {
                vector<int> it;
                res.push_back(mp[numbers[i]][0] + 1);
                res.push_back(i + 1);

                // res.push_back(it);
                mp[numbers[i]].pop_back();
            } else {
                mp[target - numbers[i]].push_back(i);
            }
        }
        return res;
    }
};