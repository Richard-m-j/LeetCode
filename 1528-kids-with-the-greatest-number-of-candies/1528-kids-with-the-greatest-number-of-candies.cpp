class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max=0;
        for(int i=0;i<candies.size();i++)
            if(max<candies[i])
                max=candies[i];
        vector <bool> result;
        for(int i=0;i<candies.size();i++)
            if(candies[i]+extraCandies>=max)
                result.push_back(true);
            else
                result.push_back(false);
        return result;
    }
};