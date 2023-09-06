# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        return self.recCheck(root, float('-inf'))

    def recCheck(self,root,big) -> int: 
        if not root:
            return 0
        good = True
        if root.val < big:
            good = False
        else:
            big = root.val
        leftCount = self.recCheck(root.left,big)
        rightCount = self.recCheck(root.right,big)
        
        return leftCount + rightCount + good
        