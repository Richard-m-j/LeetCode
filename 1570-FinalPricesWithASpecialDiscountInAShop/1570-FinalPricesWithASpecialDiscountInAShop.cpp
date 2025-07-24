// Last updated: 7/24/2025, 8:26:37 AM
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(prices.back());
        for(int i=prices.size()-2;i>=0;i--){
            while(!st.empty()&&prices[i]<st.top())
                st.pop();
            int val = prices[i];
            if(!st.empty())
                prices[i] -= st.top();
            st.push(val);
        }
        return prices;
    }
};