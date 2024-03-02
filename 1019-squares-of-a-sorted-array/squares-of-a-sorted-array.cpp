class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);

        priority_queue<int> squares;
        for(int&num: nums)
            squares.push(num*num);
        for(int i=n-1;i>=0;i--){
            res[i] = squares.top();
            squares.pop();
        }   
        return res;     
    }
};