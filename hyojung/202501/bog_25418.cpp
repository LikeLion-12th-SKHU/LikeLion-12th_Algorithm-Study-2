#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int main(void){
    map<long long,long long> m;
    long long a,k;
    cin >> a >> k;
    m[a] = 0;
    queue<long long> q;
    q.push(a);
    while(!q.empty()){
        long long next = q.front();
        if(next == k){
            cout << m[k];
            break;
        }
        q.pop();
        long long first = next + 1;
        long long second = next * 2;
        
        if(m.find(first) == m.end() && first <= k){
            m[first] = m[next] + 1;
            q.push(first);
        }
        if(m.find(second) == m.end() && second <= k){
            m[second] = m[next] + 1;
            q.push(second);
        }
    }
      
}