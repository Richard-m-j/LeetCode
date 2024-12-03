class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int i=0,j=0;
        string res="";
        while(i<s.length()){
            if(j<spaces.size() && i==spaces[j]){
                res += ' ';
                j++;
            }
            res+=s[i];
            i++;
        }
        return res;
    }
};