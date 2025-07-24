// Last updated: 7/24/2025, 8:35:26 AM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for(int i = s.length()-1;i>=0;i--){
            if(length && s[i] == ' ')
                return length;
            if(!length && s[i] == ' ')
                continue;
            length++;
        }
        return length;
    }
};