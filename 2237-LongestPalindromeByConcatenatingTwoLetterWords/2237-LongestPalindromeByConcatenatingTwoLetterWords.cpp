// Last updated: 7/24/2025, 8:24:48 AM
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> mp(26,vector<int>(26,0));
        int res=0;
        for(int i=0;i<words.size();i++){
            int x = words[i][0] - 'a';
            int y = words[i][1] - 'a';
            if(mp[y][x] != 0){
                mp[y][x]--;
                res+=4;
            }
            else{
                mp[x][y]++;
            }
        }
        int dia = 0;
        for(int i=0;i<26;i++){
            if(mp[i][i]!=0){
                dia++;
            }
        }
        if(dia)
            res += 2;
        return res;
    }
};