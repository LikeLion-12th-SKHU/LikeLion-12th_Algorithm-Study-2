ude <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> arr;
vector<int> output;

void dfs(int start){
    if(start == m){
        for(int i = 0;i<output.size();i++){
            cout << output[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = 0;i<n;i++){
        output.push_back(arr[i]);
        dfs(start+1);
        output.pop_back();
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    dfs(0);
}