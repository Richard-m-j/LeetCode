# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:    
    def dfs(self,tree,depth) -> int:
        if not tree:
            return depth

        return max(self.dfs(tree.left,depth+1),self.dfs(tree.right,depth+1))
        

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root,0)
