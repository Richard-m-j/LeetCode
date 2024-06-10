# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.maxDia = 0
        def getDepth(root):
            if not root:
                return 0
            left = getDepth(root.left)
            right = getDepth(root.right)
        
            self.maxDia = max(left + right, self.maxDia)
            if left and right:
                return max(left,right)+1
            if left:
                return left + 1
            return right + 1
        getDepth(root)
        return self.maxDia
        
        
        
