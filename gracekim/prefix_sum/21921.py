# 21921 블로그 / Silver 3 

import sys 
input = sys.stdin.readline

n, x = map(int, input().split())
day = list(map(int, input().split()))

if max(day) == 0:
  print('SAD')
  exit(0)
  
value = sum(day[:x])
max_value = value
max_cnt = 1

for i in range(x, n):
  value += day[i]
  value -= day[i - x]
  
  if value > max_value:
    max_value = value
    max_cnt = 1
  elif value == max_value:
    max_cnt += 1
    
print(max_value)
print(max_cnt)