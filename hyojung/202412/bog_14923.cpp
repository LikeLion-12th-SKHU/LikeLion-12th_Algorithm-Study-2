#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int visited[1001][1001][2];
int arr[1001][1001];

int main(void){
    int n, m;
    cin >> n >> m;

    int startx, starty;
    int endx, endy;
    cin >> startx >> starty;
    cin >> endx >> endy;
    startx--;
    starty--;
    endx--;
    endy--;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(startx, starty), 0)); 
    visited[startx][starty][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int flag = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }

            if(arr[nx][ny] == 0){
                if(visited[nx][ny][flag] == 0){
                    visited[nx][ny][flag] = visited[x][y][flag] + 1;
                    q.push(make_pair(make_pair(nx, ny), flag));  
                }
            }
            else{
                if(flag == 0 && visited[nx][ny][flag] == 0){
                    visited[nx][ny][1] = visited[x][y][flag] + 1;
                    q.push(make_pair(make_pair(nx, ny), 1)); 
                }
            }
        }
    }

    int result = min(visited[endx][endy][1], visited[endx][endy][0]);
    cout << (result > 0 ? result - 1 : -1); 
}
