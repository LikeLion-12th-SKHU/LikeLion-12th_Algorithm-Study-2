#include <iostream>
#include <cmath>
using namespace std;

int arr[101][101];
int main(void){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i != j){
                arr[i][j] = 987654321;
            }
        }
    }
    for(int i = 0;i<m;i++){
        int first,second;
        cin >> first >> second;
        arr[first][second] = 1;
        arr[second][first] = 1;
    }
    
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(arr[1][i] != 987654321){
            cnt++;
        }
    }
    cout << cnt-1;
}