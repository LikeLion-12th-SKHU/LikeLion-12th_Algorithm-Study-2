# 11660 구간 합 구하기 5 / Silver 1

import sys
input = sys.stdin.readline

 # 표 크기 N, 합을 구해야 하는 휫수 M
n, m = (map(int, input().split()))
arr = []
for i in range(n):
    a = list(map(int, input().split()))
    arr.append(a)
    
dp = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i - 1][j - 1]
        
for k in range(m):
    x1, y1, x2, y2 = map(int,input().split())
    
    result = dp[x2][y2] - dp[x2][y1 - 1] -dp[x1 - 1][y2] + dp[x1 - 1][y1-1]
    print(result)