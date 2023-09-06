# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def dfs(node, current_sum, path_sum):
            if not node:
                return 0
            
            current_sum += node.val
            path_sum += current_sum == targetSum
            
            return (
                path_sum
                + dfs(node.left, current_sum, 0)
                + dfs(node.right, current_sum, 0)
            )
        
        if not root:
            return 0
        
        return (
            dfs(root, 0, 0)
            + self.pathSum(root.left, targetSum)
            + self.pathSum(root.right, targetSum)
        )
