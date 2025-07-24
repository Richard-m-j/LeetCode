// Last updated: 7/24/2025, 8:27:59 AM
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();

        int gcd=__gcd(n,m);
        string str="";
        for(int i=0;i<gcd;i++)
            if(str1[i]==str2[i])
                str+=str1[i];     
            else
                return "";
        int k=0;
        for(int i=gcd;i<n;i++)
        {
            if(k==gcd)
                k=0;
            if(str1[i]!=str[k])
                return "";
            k++;
        }
        k=0;
        for(int i=gcd;i<m;i++)
        {
            if(k==gcd)
                k=0;
            if(str2[i]!=str[k])
                return "";
            k++;
        }
        return str;
    }
};