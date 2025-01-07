# 9205 맥주 마시면서 걸어가기 / Gold 5 

import sys
from collections import deque
input = sys.stdin.readline

def bfs():
  q = deque()
  q.append((home_x, home_y))
  while q: 
    x, y = q.popleft()
    if abs(x - festival_x) + abs(y - festival_y) <= 1000:
      print("happy")
      return
    for i in range(n): 
      if not visited[i]:
        new_x, new_y = graph[i] # 편의점 좌표 새로 갱신
        if abs(x - new_x) + abs(y - new_y) <= 1000: # 다음거리까지 갈 수 있다면
          visited[i] = 1
          q.append((new_x, new_y)) # 큐에 넣는다.
  print("sad")
  return


t = int(input()) # 테스트 케이스 개수

for _ in range(t):
  n = int(input()) # 편의점 개수
  home_x, home_y = map(int, input().split()) # 집 좌표
  graph = []
  for _ in range(n):
    x, y = map(int, input().split())
    graph.append((x, y))
  festival_x, festival_y = map(int, input().split())
  visited = [0 for _ in range(n + 1)]
  bfs()
  