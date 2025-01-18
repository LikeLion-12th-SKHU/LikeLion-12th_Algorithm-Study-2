#include <iostream>
using namespace std;

int dp[100001];
int arr[100001];

int main(void){
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        if(i == 1){
            dp[i] = arr[i];
        }
        else{
            dp[i] = dp[i-1] + arr[i];
        }
    }
    
    for(int i = 0;i<m;i++){
        int start,end;
        cin >> start >> end;
        cout << dp[end] - dp[start] + arr[start] << '\n';
    }
    
}