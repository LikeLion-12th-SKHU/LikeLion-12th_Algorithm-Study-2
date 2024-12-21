#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void){
    int n;
    cin >> n;
    //l-r
    //s-k
    int cnt = 0;
    string s;
    cin >> s;
    stack<char> lr;
    stack<char> sk;
    for(int i = 0;i<n;i++){
        if(s[i] == 'L'){
            lr.push(s[i]);
        }
        else if(s[i] == 'S'){
            sk.push(s[i]);
        }
        else if(s[i] == 'K'){
            if(!sk.empty()){
                cnt++;
                sk.pop();
            }
            else{
                break;
            }
        }
        else if(s[i] == 'R'){
            if(!lr.empty()){
                cnt++;
                lr.pop();
            }
            else{
                break;
            }
        }
        else{
            cnt++;
        }
    }
    cout << cnt;
    
}