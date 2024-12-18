# 17615 볼 모으기 / Silver 1 

import sys
input = sys.stdin.readline

n = int(input())
m = str(input().rstrip())

cnt = []

right_explore = m.rstrip('R')
cnt.append(right_explore.count('R'))

right_explore = m.rstrip('B')
cnt.append(right_explore.count('B'))

left_explore = m.lstrip('R')
cnt.append(left_explore.count('R'))

left_explore = m.lstrip('B')
cnt.append(left_explore.count('B'))

print(min(cnt))