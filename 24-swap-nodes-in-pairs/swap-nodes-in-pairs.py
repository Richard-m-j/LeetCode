# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head

        dummy = ListNode(-1, head)

        first = dummy
        second = dummy.next
    
        while first and second and second.next:
            first.next = second.next
            second.next = second.next.next
            first.next.next = second
            first = first.next.next
            second = second.next
        return dummy.next
