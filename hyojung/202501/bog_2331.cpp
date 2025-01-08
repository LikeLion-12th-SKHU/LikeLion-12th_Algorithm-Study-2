#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int visited[1000001];
int cnt = 1;

int main(void){
    int a,k;
    cin >> a >> k;

    for(int i = 1;i<=9999;i++){
        visited[i] = 0;
    }

    visited[a] = 1;

    queue<int> q;
    q.push(a);
    map<int,int> m;
    map<int,int>::iterator iter;

    while(!q.empty()){
        int next = q.front();
        int sum = 0;
        q.pop();
        m[next] = next;
        if(visited[next] >= 2 && m.find(next) != m.end()){
            iter = m.find(next);
            m.erase(iter);
        }
        //57
        
      
        for(int i = 0;i<to_string(next).size();i++){
            int pow_ = pow(to_string(next)[i] - '0',k);
            sum += pow_;
        }
        if(visited[sum] < 3){
            q.push(sum);
            visited[sum]++;
        }
    }
    cout << m.size();

}