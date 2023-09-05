# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:

        fast = head
        prev = None
        curr = head
        
        while fast:
            temp = curr 
            fast=fast.next.next
            curr = temp.next
            temp.next = prev
            prev = temp
        res = 0
        while curr and prev:
            total = curr.val + prev.val
            res = max(total,res)
            curr = curr.next
            prev = prev.next

        return res