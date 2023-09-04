# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head.next==None:
            return None
        ptr = head.next.next
        mid = head
        while ptr and ptr.next:
            mid=mid.next
            ptr=ptr.next.next
        mid.next=mid.next.next
        return head
        