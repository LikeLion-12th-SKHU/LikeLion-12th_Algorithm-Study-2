#include <queue>
#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    
    queue<int> q;
    for(int i = 1;i<=n;i++){
        q.push(i);
    }
    
    while(q.size() != 1){
        int top = q.front();
        cout << top << ' ';
        q.pop();
        int nexttop = q.front();
        q.pop();
        q.push(nexttop);
    }
    
    cout << q.front();
    
}