class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)

        dp = [[False for _ in range(n + 1)] for _ in range(n + 1)]

        for leng in range(1 , n + 1):
            for i in range(0 , n - leng + 1):
                j = i + leng - 1

                if leng == 1:
                    dp[i][j] = True
                
                elif leng == 2 and s[i] == s[j]:
                    dp[i][j] = True
                
                elif leng >= 3:
                    if s[i] == s[j] and dp[i + 1][j - 1]:
                        dp[i][j] = True

        arr = [0 for _ in range(n + 1)]

        for i in range(1 , n + 1):
            arr[i] = arr[i - 1]

            for j in range(i):
                lent = i - j

                if lent >= k and dp[j][i - 1] == True:
                    arr[i] = max(arr[i] , arr[j] + 1)
    
        return arr[n]