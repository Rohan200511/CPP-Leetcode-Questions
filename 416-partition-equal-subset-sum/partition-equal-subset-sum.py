from typing import List
class Solution:
    
    def solve(self , nums: List[int] , target : int , i : int , n : int , dp : List[List[int]]) -> bool:
        if(target == 0):
            return True
        
        if(target < 0):
            return False
        
        if(i == n):
            return target == 0
        
        if(dp[i][target] != -1):
             return dp[i][target]

        take = self.solve(nums , target - nums[i] , i + 1 , n , dp)
        skip = self.solve(nums , target , i + 1 , n , dp)

        dp[i][target] = (take or skip)
        return dp[i][target]

    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        total = sum(nums)
        target = total // 2
        if(total % 2 == 1):
            return False
        
        dp = [[-1 for _ in range(target + 1)] for _ in range(n)]

        return self.solve(nums , target , 0 , n , dp)
