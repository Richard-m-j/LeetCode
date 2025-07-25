# Last updated: 7/24/2025, 8:27:41 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        # can be solved by finding prefix sum;
        # if l1+l2 = l1+l2+...+l5, meaning that l3 + ... + l5 = 0, 
		# then l3 + ... + l5 is the consecutive sequence of nodes we want to delete. 
		# If it's a array we could just remove numbers from index of l3 to l5. 
		# If it's a linked list, we could let l2.next = l5.next, we then need to have two pointers,
		# one point to l2 and the other point to l5;
        dummy = ListNode(0)
        dummy.next = head
        prefix = 0
        d = {0:dummy} # key is the prefix sum, value is the last node of getting this sum value, which is l5
        while head:
            prefix += head.val
            d[prefix] = head
            head = head.next
		# Go from the dummy node again to set the next node to be the last node for a prefix sum 
        head = dummy
        prefix = 0
        while head:
            prefix += head.val
            head.next = d[prefix].next
            head = head.next
        
        return dummy.next
        