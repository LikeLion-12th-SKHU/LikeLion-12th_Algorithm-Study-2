#include <iostream>
using namespace std;

int dp[100001];
int arr[100001];

int main(void){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        if(i == 0){
            dp[i] = arr[i];
        }
        else{
            dp[i] = dp[i-1] + arr[i];
        }
    }
    
    long long sum = 0;
    for(int i = 0;i<n;i++){
        sum += (arr[i] * (dp[n-1] - dp[i]));
    }
    cout << sum;
    
}