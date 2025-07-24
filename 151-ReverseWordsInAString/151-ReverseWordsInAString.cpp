// Last updated: 7/24/2025, 8:33:34 AM
// class Solution {
// public:
//     string reverseWords(string s) {
//         int left=s.length()-1;
//         int right=s.length();
//         string out="";
//         while(left>=0)
//         {
//             if(s[left]==' '&&(left+1)==right)
//             {
//                 left--;
//                 right--;
//                 continue;
//             }
//             if(s[left]==' ')
//             {
//                 for(int i=left+1;i<right;i++)
//                     out+=s[i];
//                 if(left!=0)
//                     out+=" ";
//                 right=left;
//             }
//             left--;
//         }
//         if((left+1)!=right)
//             for(int i=left+1;i<right;i++)
//                 out+=s[i];
//         if(out[out.length()-1]==' ')
//             out = out.substr(0, out.size() - 1);
//         return out;
//     }
// };
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return(0);}();
class Solution {
public:
    void reverseString(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    string reverseWords(string s) {
        int n = s.length();

        // Step 1: Reverse the entire string
        reverseString(s, 0, n - 1);

        // Step 2: Reverse each individual word
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }

        // Reverse the last word (or the only word if there's only one)
        reverseString(s, start, n - 1);

        // Step 3: Remove extra spaces
        int index =0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ' || (i > 0 && s[i - 1] != ' ')) {
                s[index++] = s[i];
            }
        }

        if(s[n-1] == ' ')
            index--;

        // Resize the string to remove extra characters
        s.resize(index);

        return s;
    }
};