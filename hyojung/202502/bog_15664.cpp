#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> visited;
vector<int> arr;
vector<vector<int>> output;
int n,m;
int main(void){
    cin >> n >> m;
    
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i = 0;i<m;i++){
        visited.push_back(0);
    }
    
    for(int i = 0;i<n-m;i++){
        visited.push_back(1);
    }
    
    sort(visited.begin(),visited.end());
    
    do{
        vector<int> temp;
        for(int i = 0;i<n;i++){
            if(visited[i] == 0){
                 temp.push_back(arr[i]);
            }
        }
        output.push_back(temp);
    }while(next_permutation(visited.begin(),visited.end()));
    sort(output.begin(),output.end());
    
    output.erase(unique(output.begin(),output.end()),output.end());
    
    for(int i = 0;i<output.size();i++){
        for(int j = 0;j<output[i].size();j++){
               cout << output[i][j] << ' ';
        }
        cout << '\n';
    }
        
}