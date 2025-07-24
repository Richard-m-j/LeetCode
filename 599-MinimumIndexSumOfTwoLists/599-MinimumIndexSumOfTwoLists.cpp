// Last updated: 7/24/2025, 8:30:12 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string,int> listMap2;

        int n = list1.size();
        int m = list2.size();

        for(int i = 0; i<m; i++)
            listMap2[list2[i]] = i+1;

        int small = INT_MAX;
        vector<string> ans;
        for(int i = 0; i < n; i++)
        {
            int index = listMap2[list1[i]];
            if(index> 0)
                if(small > i+index-1)
                {
                    small = i+index-1;
                    vector <string> temp;
                    temp.push_back(list1[i]);
                    ans = temp;
                }
                else if(small == i+index-1)
                    ans.push_back(list1[i]);
        }
        return ans;
    }
};