# 2468 안전 영역 / Silver 1
import sys
from collections import deque 
input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
max_rain = max(map(max, graph))

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
def bfs(i, j):
  global count
  q = deque()
  q.append((i, j))
  sink[i][j] = True
  count += 1
  while q:
    x, y = q.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx < 0 or ny < 0 or nx >= n or ny >= n:
        continue
      if sink[nx][ny] == False:
        sink[nx][ny] = True
        q.append((nx, ny))

count_list = []
for rain in range(max_rain):
  count = 0
  sink = [[False for _ in range(n)] for i in range(n)]
  for i in range(n):
    for j in range(n):
      if graph[i][j] <= rain:
        sink[i][j] = True
  for i in range(n):
    for j in range(n):
      if sink[i][j] == False:
        bfs(i, j)
  count_list.append(count)
  
print(max(count_list))