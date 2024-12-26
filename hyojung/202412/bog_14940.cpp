#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int visited[1001][1001];
int arr[1001][1001];

int main(void){
    int n,m;
    cin >> n >> m;
    int startx,starty;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
            visited[i][j] = 987654321;
            if(arr[i][j] == 2){
                startx = i;
                starty = j;
            }
        }
    }
    
    queue<pair<int,int>> q;
    visited[startx][starty] = 0;
    q.push({startx,starty});
    
    while(!q.empty()){
        int nextx = q.front().first;
        int nexty = q.front().second;
        
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = nextx + dx[i];
            int ny = nexty + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            if(visited[nx][ny] > visited[nextx][nexty] + 1 && arr[nx][ny] != 0){
                visited[nx][ny] = visited[nextx][nexty] + 1;
                q.push({nx,ny});
            }
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] == 987654321){
                if(arr[i][j] == 0){
                    cout << 0 << ' ';
                }
                else{
                    cout << -1 << ' ';
                }
            }
            else{
                cout << visited[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    
    
}