#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];
bool visited[100001];
vector<int> v[100001];

int dfs(int start){
    visited[start] = true;
    for(int i = 0;i<v[start].size();i++){
        int nextnode = v[start][i];
        if(visited[nextnode] == false){
            dp[start] += dfs(nextnode);
        }
    }
  
    return dp[start];
}

int main(void){
    cin.tie(NULL);
    
    int n,r,q;
    cin >> n >> r >> q;
    
    for(int i = 0;i<n-1;i++){
        int f_node,s_node;
        cin >> f_node >> s_node;
        v[f_node].push_back(s_node);
        v[s_node].push_back(f_node);
    }
    
    for(int i = 1;i<=n;i++){
        dp[i] = 1;
    }
    
    dfs(r);
    
    for(int i = 0;i<q;i++){
        int target;
        cin >> target;
        cout << dp[target] << '\n';
    }
    
    
}