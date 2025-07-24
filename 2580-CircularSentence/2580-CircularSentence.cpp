// Last updated: 7/24/2025, 8:23:50 AM
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i=0,n=sentence.length();
        char prev = sentence[n-1];
        while(i<n){
            if(prev != sentence[i])
                return false;
            
            while(i<n && sentence[i] != ' ')
                i++;
            prev = sentence[i-1];
            i++;
        }
        return true;
    }
};