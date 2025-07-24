// Last updated: 7/24/2025, 8:31:43 AM
class Solution {
public:
    string reverseVowels(string s) {
        int l=0;
        int r=s.length()-1; 
        char *str=&s[0];       
        while(l<r)
        {
            if(!isVovel(str[l]))
                l++;
            else if(!isVovel(str[r]))
                r--;
            else 
            {
                char temp=str[l];
                str[l]=str[r];
                str[r]=temp;
                l++;
                r--;
            }
        }
        string out(str);
        return out;
    }
    bool isVovel(char s)
    {
        switch(s)
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': return true;
            default: return false;
        }
    }
};