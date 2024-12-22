#include <stack>
#include <iostream>
using namespace std;
int main(void){
    cin.tie(NULL);
    
    int n;
    cin >> n;
    stack<int> st;
    
    for(int i = 0;i<n;i++){
        int operate;
        cin >> operate;
        if(operate == 1){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(operate == 2){
            if(st.empty()){
                cout << -1 << '\n';
            }
            else{
                int top = st.top();
                cout << top << '\n';
                
                st.pop();
            }
        }
        else if(operate == 3){
            cout << st.size() << '\n';
        }
        else if(operate == 4){
            if(st.empty()){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if(operate == 5){
            if(st.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << st.top() << '\n';
            }
        }
    }
    
}