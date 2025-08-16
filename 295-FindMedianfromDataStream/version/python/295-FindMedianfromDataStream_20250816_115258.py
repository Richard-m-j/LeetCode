# Last updated: 8/16/2025, 11:52:58 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validate(node: TreeNode,low,high):
            if not node:
                return True
            if low >= node.val or high <= node.val:
                # print(node.val)
                return False

            isLeftValid = validate(node.left,low,node.val)
            isRightValid = validate(node.right,node.val,high)

            return isLeftValid and isRightValid 
        return validate(root,float('-inf'),float('inf'))
