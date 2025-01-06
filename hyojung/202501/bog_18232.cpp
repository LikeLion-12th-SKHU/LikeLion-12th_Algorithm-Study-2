#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[300001];

int main(void){
    //s->e 
    //1 -n 
    //만약 점 x라면 x-1,x+1,x에 위치한 텔포지점
    //1초

    int n,m;
    cin >> n >> m;
    int s,e;
    cin >> s >> e;
    vector<int> arr[300001];
   

    for(int i = 0;i<m;i++){
        int start,end;
        cin >> start >> end;
        arr[start].push_back(end);
        arr[end].push_back(start);
    }

    queue<pair<int,int>> q;
    visited[s] = true;
    q.push({s,0});

    int totalCount = 0;

    while(!q.empty()){
        int next = q.front().first;
        int count = q.front().second;
        q.pop();
        if(next == e){
            totalCount = count;
            break;
        }

        if(next - 1 > 0){
            if(!visited[next-1]){
                visited[next-1] = true;
                q.push({next-1,count+1});
            }
        }
        if(next + 1 <= n){
            if(!visited[next+1]){
                visited[next+1] = true;
                q.push({next+1,count+1});
            }
        }
        for(int i = 0;i<arr[next].size();i++){
            int targetNode = arr[next][i];
            if(!visited[targetNode]){
                visited[targetNode] = true;
                q.push({targetNode,count+1});
            }
        }
    }

    cout << totalCount;

}