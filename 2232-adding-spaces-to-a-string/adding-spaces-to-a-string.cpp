class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
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