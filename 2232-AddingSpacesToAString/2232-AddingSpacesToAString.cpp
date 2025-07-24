// Last updated: 7/24/2025, 8:24:51 AM
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int i=0,j=0,k=0;
        int l = s.length()+spaces.size();
        char res[l];
        while(i<s.length()){
            if(j<spaces.size() && i==spaces[j]){
                res[k++] = ' ';
                j++;
            }
            res[k++] =s[i];
            i++;
        }
        return string(res,l);
    }
};