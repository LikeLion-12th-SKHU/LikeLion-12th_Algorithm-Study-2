#include <iostream>
using namespace std;
int arr[1025][1025];
int dp[1025][1025];

int main(void){
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    
    int q;
    cin >> q;
    //33-44
    //44-24-42+22
    for(int i = 0;i<q;i++){
        int startx,starty,endx,endy;
        cin >> startx >> starty >> endx >> endy;
        cout << dp[endx][endy] - dp[startx-1][endy] - dp[endx][starty-1] + dp[startx-1][starty-1] << '\n';
    }
    
}