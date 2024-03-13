class Solution:
    def pivotInteger(self, n: int) -> int:
        c = (n*(n+1))//2

        l=1
        r=n
        while l<=r:
            m = (l+r)//2
            leftSum = (m*(m+1))//2
            rightSum = c - leftSum + m
            if leftSum == rightSum:
                return m
            elif leftSum < rightSum:
                l = m+1
            else:
                r=m-1
        return -1

