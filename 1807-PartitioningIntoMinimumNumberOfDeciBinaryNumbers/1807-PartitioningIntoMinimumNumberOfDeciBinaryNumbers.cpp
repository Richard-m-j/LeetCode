// Last updated: 7/24/2025, 8:25:56 AM
static const auto _ = [](){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return 0;
}();
class Solution {
public:
    int minPartitions(string n) {
        char ans=0;
        for(auto& it:n)
        {
            ans=max(ans,it);
        }
        return ans-'0';
    }
};