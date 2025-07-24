// Last updated: 7/24/2025, 8:29:07 AM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        int n = s.length();

        for(int i=0;i<n;i++){
            bool rotatable = true;
            for(int j=0;j<n;j++){
                if(goal[(i+j)%n] != s[j]){
                    rotatable = false;
                    break;
                }
            }
            if(rotatable)
                return true;
        }
        return false;
    }
};