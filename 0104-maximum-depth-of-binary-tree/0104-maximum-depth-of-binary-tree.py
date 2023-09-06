# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    
    def dfs(self,node: Optional[TreeNode]) -> int:
        if not node:
            return 0
        if node.left or node.right :
            leftDepth = self.dfs(node.left)
            rightDepth = self.dfs(node.right)
            depth = max(leftDepth,rightDepth)+1
            return depth
        else:
            return 1

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)
