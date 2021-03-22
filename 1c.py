from collections import defaultdict
class Solution:
    def minTransfers(self, transactions):
        money = defaultdict(int)
        for sender, receiver, amount in transactions:
            money[sender] -= amount
            money[receiver] += amount
 
        amounts = [amount for amount in money.values() if amount != 0]
        N = len(amounts)
        dp = [0] * (2 ** N)
        sums = [0] * (2 ** N) 

 
        for mask in range(2 ** N):
            set_bit = 1
            for b in range(N):
                if mask & set_bit == 0:
                    nxt = mask | set_bit
                    print(nxt)
                    sums[nxt] = sums[mask] + amounts[b]
                    if sums[nxt] == 0:
                        dp[nxt] = max(dp[nxt], dp[mask] + 1)
                    else:
                        dp[nxt] = max(dp[nxt], dp[mask])
                set_bit <<= 1
        return N - dp[-1]
 
s = Solution()
print(s.minTransfers([[0,1,5], [0,2,6], [0,3,6]]))