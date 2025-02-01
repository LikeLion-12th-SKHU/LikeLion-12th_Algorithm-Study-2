/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
*/
/*
4 2
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool visited[10];
vector<int> arr;
int n,m;

void dfs(int level){
    if(level == m){
        for(int i = 0;i<arr.size();i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1;i<=n;i++){
        if(visited[i] == false){
            visited[i] = true;
            arr.push_back(i);
            dfs(level + 1);
            visited[i] = false;
            arr.pop_back();
        }
    }
    
}

int main(void){
    
    cin >> n >> m;
    dfs(0);
    
    
}