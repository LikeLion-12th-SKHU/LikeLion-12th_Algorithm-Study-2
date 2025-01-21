# 14465 소가 길을 건너간 이유5 / Silver 2

import sys 
input = sys.stdin.readline

n, k, b = map(int, input().split()) # n = 횡단보도 개수, k개의 신호등이 존재하도록 / b줄에는 고장난 신호등
trafficLight = [i for i in range(1, n + 1)]

for i in range(b):
  trafficLight[int(input()) - 1] = -1
  
  
res = 0
for i in range(k):
  if trafficLight[i] == -1:
    res += 1
    
count = res
for i in range(1, n - k + 1):
  if trafficLight[i - 1] == -1:
    count -= 1
  if trafficLight[i + k - 1] == -1:
    count += 1
    
  res = min(res, count)
  
print(res)