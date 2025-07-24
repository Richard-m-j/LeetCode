// Last updated: 7/24/2025, 8:35:54 AM
class Solution {
    public String countAndSay(int n) {
        if(n==1)
            return "1";
        StringBuffer s = new StringBuffer();
        s.append('1');
        for(int i=2;i<=n;i++){
            StringBuffer next = new StringBuffer();
            int f=1,k=0;
            char c=s.charAt(0);
            for(int j=1;j<s.length();j++){
                if(c==s.charAt(j)){
                    f++;
                }
                else{
                    next.append(f).append(c);
                    f=1;
                    c=s.charAt(j);
                }
            }
            next.append(f).append(c);
            s = next;
        }
        return s.toString();
    }
        
}