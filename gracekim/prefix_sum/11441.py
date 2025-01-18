# 11441 합 구하기 / Silver 3

# 시간초과
# import sys 
# input = sys.stdin.readline

# n = int(input()) # 수의 개수
# nums = list(map(int, input().split()))
# m = int(input()) # 구간 개수

# for _ in range(m):
#   i, j = map(int, input().split()) # 구간 (i, j)
#   sum = 0
#   for k in range(i-1, j):
#     sum += nums[k]
    
#   print(sum)

import sys 
input = sys.stdin.readline

n = int(input()) # 수의 개수
nums = list(map(int, input().split()))
ans = [0] * (n+1)
for i in range(1, n+1):
  ans[i] = ans[i-1] + nums[i-1]
  
for _ in range(int(input())):
  i, j = map(int, input().split())
  sys.stdout.write(str(ans[j] - ans[i - 1]) + "\n")