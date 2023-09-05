# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        dq=[]
        ptr = head
        while ptr:
            dq+=[ptr.val]
            ptr=ptr.next
        n=len(dq)
        res = 0
        for i in range(int(n/2)):
            sum = dq[i]+dq[n-i-1]
            res = max(sum,res)
        return res