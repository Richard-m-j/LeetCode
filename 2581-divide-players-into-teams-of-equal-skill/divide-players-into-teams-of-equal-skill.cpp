class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = skill.size();
        if(n<2)
            return -1;
        
        sort(skill.begin(),skill.end());

        int pairSum = skill[0] + skill[n-1];
        long long res = skill[0] * skill[n-1];
        for(int i=1;i<n/2;i++){
            if(skill[i] + skill[n-i-1] != pairSum)
                return -1;
            res += skill[i] * skill[n-i-1];
        }
        return res;
    }
};