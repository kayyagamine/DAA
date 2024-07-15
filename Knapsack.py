def unboundedKnapsack(k, arr):
    dp = [0] * (k + 1)
    
    for i in range(1, k + 1):
        for item in arr:
            if item <= i:
                dp[i] = max(dp[i], dp[i - item] + item)
                
    return dp[k]

if __name__ == "__main__":
    t = int(input().strip())
    results = []
    
    for _ in range(t):
        n, k = map(int, input().strip().split())
        arr = list(map(int, input().strip().split()))
        results.append(unboundedKnapsack(k, arr))
    
    for result in results:
        print(result)
