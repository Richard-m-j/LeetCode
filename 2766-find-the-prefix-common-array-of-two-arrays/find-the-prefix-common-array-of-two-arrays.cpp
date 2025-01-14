class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_set<int> setA,setB;
        int n = A.size(),count=0;
        for(int i=0;i<n;i++){
            
            if(setB.count(A[i]))
                count++;
            if(setA.count(B[i]))
                count++;
            if(A[i]==B[i])
                count++;
            setA.insert(A[i]);
            setB.insert(B[i]);
            res.push_back(count);
        }
        return res;
    }
};