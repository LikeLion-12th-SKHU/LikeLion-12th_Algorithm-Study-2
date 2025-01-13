#include <iostream>
using namespace std;

int visited[10001][10001];  
//가장 먼 방문해야 하는 노드
int answer[10001][10001];


int main(void){
    int n,m;
    cin >> n >> m;

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i != j){
                visited[i][j] = 987654321;
            }
        }
    }

    for(int i = 0;i<m;i++){
        int start,end,weight;
        cin >> start >> end >> weight;

        visited[start][end] = weight;
        visited[end][start] = weight;

        //start - end처음 방문하는 노드
        //start-> end로 가기 위해 end를 처음 방문한다.
        //end-> start로 가기 위해서는 start를 처음 방문한다.
        answer[start][end] = end;
        answer[end][start] = start;
    }

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i != j){
                    if(visited[i][j] > visited[i][k] + visited[k][j]){
                        answer[i][j] = answer[i][k];
                        visited[i][j] = visited[i][k] + visited[k][j];
                    }
                }
            }
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == j){
                cout << '-' << ' ';
            }
            else{
                cout << answer[i][j] << ' '.
            }
        }
        cout << '\n';
    }

}