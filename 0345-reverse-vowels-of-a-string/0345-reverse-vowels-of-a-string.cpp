class Solution {
public:
    string reverseVowels(string s) {
        int l=0;
        int r=s.length()-1;
        int left{-1},right{-1}; 
        char *str=&s[0];       
        while(l<=r)
        {
            if(isVovel(str[l]))
                left=l;
            
            while(right==-1&&l<r)
            {
                if(isVovel(str[r]))
                    right=r;
                r--;
            }
            if(left!=-1&&right!=-1)
            {
                char temp=str[left];
                str[left]=str[right];
                str[right]=temp;
                left=right=-1;
            }
            l++;
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