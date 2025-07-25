# Last updated: 7/24/2025, 8:31:49 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        odd = head
        even = head.next
        evenHead=even

        while even and even.next:
            odd.next=even.next
            odd=odd.next
            even.next = odd.next
            even = even.next
        
        odd.next=evenHead

        return head
        