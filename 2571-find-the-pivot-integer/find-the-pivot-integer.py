class Solution:
    def pivotInteger(self, n: int) -> int:
        c = pow((n*(n+1))//2,0.5)
        convert = int(c)
        return convert if convert == c else -1

        

