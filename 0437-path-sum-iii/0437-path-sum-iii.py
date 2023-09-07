class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def dfs(node, pathSum):
            if not node:
                return 
            currentSum = pathSum + node.val
            x = currentSum - targetSum
            if x in freq:
                self.count += freq[x]
            if currentSum in freq:
                freq[currentSum] += 1
            else:
                freq[currentSum]=1
            dfs(node.left,currentSum)
            dfs(node.right,currentSum)
            freq[currentSum] -= 1
        self.count = 0
        freq = {0:1}
        dfs(root,0)
        return self.count