class unionFind {
public:
    vector<int> id;
    unionFind(int n) {
        id.resize(n);
        for (int i = 0; i < n; i++)
            id[i] = i;
    }
    void connect(int a, int b) { id[find(b)] = find(a); }
    int find(int a) { return id[a] == a ? a : (id[a] = find(id[a])); }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        
        unordered_set<int> factors;
        for (int num : nums) {
            for (int i = 2; i * i <= num; i++) {
                while (num % i == 0) {
                    factors.insert(i);
                    num /= i;
                }
            }
            if (num > 1) factors.insert(num);
        }
        
        unordered_map<int, int> factorMap;
        int idx = 0;
        for (int factor : factors) {
            factorMap[factor] = idx++;
        }
        
        vector<vector<int>> graph(factorMap.size());
        
        for (int num : nums) {
            if(num == 1)
                return false;
            unordered_set<int> numFactors;
            for (int i = 2; i * i <= num; i++) {
                while (num % i == 0) {
                    numFactors.insert(i);
                    num /= i;
                }
            }
            if (num > 1) numFactors.insert(num);
            
            for (int factor : numFactors) {
                int factorIdx = factorMap[factor];
                for (int otherFactor : numFactors) {
                    if (factor != otherFactor) {
                        int otherFactorIdx = factorMap[otherFactor];
                        graph[factorIdx].push_back(otherFactorIdx);
                    }
                }
            }
        }
        
        unionFind uf(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (int neighbor : graph[i]) {
                uf.connect(i, neighbor);
            }
        }
        
        int head = uf.find(0);
        for (int i = 1; i < graph.size(); i++) {
            if (head != uf.find(i)) return false;
        }
        
        return true;
    }
};

// int n = nums.size();
// unionFind uf(n);

// for (int i = 0; i < n; i++){
//     for (int j = i+1; j < n; j++){
//         if (gcd(nums[i], nums[j]) > 1) {
//             uf.connect(i, j);
//         }
//     }
// }
// int head = uf.find(0);
// for(int i = 1;i<n;i++)
//     if(head != uf.find(i))
//         return false;
// return true;