#include <iostream>
#include <queue>
#include <map>

using namespace std;

//1 2 3 4 5 6 7 8 9 10
//2 1 3 4 5 6 7 9 10 8


//
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[1001];
        map<int,int> m;
        int count = 0;
        bool visited[1001];
        for(int i = 1;i<=n;i++){
            cin >> arr[i];
            m[i] = arr[i];
            visited[i] = false;
        }
        
        
        
        for(int i = 1;i<=n;i++){
           if(visited[i] == false){
               visited[i] = true;
               queue<int> q;
               q.push(i);
               
               while(!q.empty()){
                   int next = q.front();
                   q.pop();
                   if(visited[m[next]]){
                       //싸이클 존재
                       count++;
                       break;
                   }
                   else{
                       if(visited[m[next]] == false){
                           visited[m[next]] = true;
                           q.push(m[next]);
                       }
                   }
               }
           }
        }
        cout << count << '\n';
        
        
    }
}