class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length(),numOnes;
        vector<int> left(n);
        left[0]=0,numOnes=boxes[0]-'0';
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+numOnes;
            numOnes+=boxes[i]-'0';
        }
        vector<int> right(n);
        right[n-1]=0,numOnes=boxes[n-1]-'0';
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+numOnes;
            numOnes+=boxes[i]-'0';
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i] = left[i]+right[i];
            // cout<<left[i]<<" "<<right[i]<<endl;
        }
        return res;
    }
};