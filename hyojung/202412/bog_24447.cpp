#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

long long visited[100011];
long long depth[100011];

int main(void){
    vector<long long> v[1000011];
    int n,m,start;

    cin >> n >> m >> start;
    int cnt = 1;

    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    //노드 깊이 -1로 초기화
    for(int i = 1;i<=n;i++){
        visited[i] = -1;
    }

    queue<int> q;
    visited[start] = 1;
    depth[start] = 0;
    q.push(start);
    cnt++;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        sort(v[top].begin(),v[top].end());
        for(int i = 0;i<v[top].size();i++){
            if(visited[v[top][i]] == -1){
                visited[v[top][i]] = cnt;
                depth[v[top][i]] = depth[top] + 1;
                cnt++;
                q.push(v[top][i]);
            }
        }
    }

    long long sum = 0;
    for(int i = 1;i<=n;i++){
        if(visited[i] == -1){
            visited[i] = 0;
        }

        if(depth[i] == 0){
            if(start != i){
                depth[i] = -1;
            }
        }

        long long nextCnt = visited[i] * depth[i];
        sum += nextCnt;
    }
    cout << sum;

}