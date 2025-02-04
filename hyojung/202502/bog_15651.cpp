#include <iostream>

int n,m;
bool visited[10];
int arr[10];
using namespace std;

void dfs(int start){
    if(start == m){
        for(int i = 0;i<m;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1;i<=n;i++){
        
        visited[i] = true;
        arr[start] = i;
        dfs(start+1);
        visited[i] = false;
    }

}
int main(void){
    cin >> n >> m;
    dfs(0);
    
}