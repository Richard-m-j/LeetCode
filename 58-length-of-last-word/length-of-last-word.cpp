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