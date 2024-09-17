class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while (a || b || c) {
            int op = ((a & 1)<<2) + ((b & 1)<<1) + (c & 1);
            switch(op){                
                case 0:
                case 3:
                case 5:
                case 7: break;
                case 1:
                case 2: 
                case 4: res++; break;
                case 6: res+=2; break;
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return res;
    }
};