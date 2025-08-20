# Last updated: 8/20/2025, 8:57:52 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None
        if len(preorder) == 1:
            return TreeNode(preorder[0],None,None)
        root = preorder[0]
        rootIndex = inorder.index(root)
        leftInorder = inorder[:rootIndex]
        rightInorder = inorder[rootIndex+1:]
        leftPreorder = preorder[1:len(leftInorder)+1]
        rightPreorder = preorder[len(leftInorder)+1:]
        return TreeNode(preorder[0],self.buildTree(leftPreorder,leftInorder),self.buildTree(rightPreorder,rightInorder))
        # print(res)
        # return res
        