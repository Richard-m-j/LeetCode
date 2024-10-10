class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        stack<int> s;
        int n = nums.size();
        int res=0;
        for(int i=0;i<n;i++)
            if(s.empty()||nums[s.top()]>nums[i])
                s.push(i);
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                res = max(res,i-s.top());
                cout<<s.top()<<" "<<i<<endl;
                s.pop();
                if(s.empty())
                    return res;
            }
        }
        return res;
    }
};