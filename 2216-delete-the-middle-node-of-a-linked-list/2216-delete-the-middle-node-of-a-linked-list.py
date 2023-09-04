# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head.next==None:
            return None
        ptr = head.next
        mid = head
        n=0
        while ptr.next:
            ptr=ptr.next
            n+=1
            if n%2 == 0:
                mid=mid.next
        mid.next=mid.next.next
        return head
        