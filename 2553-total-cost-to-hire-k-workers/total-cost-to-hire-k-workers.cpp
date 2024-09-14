class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long res=0;
        int n = costs.size();
        vector<int> hired(n,0);
        
        priority_queue<int,vector<int>,greater<int>> left,right;
        int l=0,r=n-1;
        for(;l<candidates;l++){
            left.push(costs[l]);
            hired[l]=1;
        }
        l--;
        
        for(;r>=n-candidates;r--){
            if(!hired[r]){
                right.push(costs[r]);
                hired[r]=1;
            }
            else
                break;
        }
        r++;

        cout<<endl<<left.size()<<" "<<right.size()<<" "<<endl;
        for(int i=0;i<k;i++){
            if(left.size() && (!right.size() || left.top()<=right.top())){
                res+=left.top();
                // cout<<left.top()<<"l ";
                left.pop();
                ++l;
                if(l<n && !hired[l]){   
                    left.push(costs[l]);
                    hired[l]=1;
                }
            }
            else{
                res+=right.top();
                // cout<<right.top()<<"r "<<right.size()<<" ";
                right.pop();
                r--;
                if(r>=0 && !hired[r]){
                    right.push(costs[r]);
                    hired[r]=1;
                    // cout<<"**";
                }
            }
        }
        return res;
    }
};