#include <iostream>
#include <map>
using namespace std;
int main(void){
    cin.tie(NULL);
    
    map<int,int> m;
    int n,q;
    cin >> n >> q;
    
    for(int i = 0;i<q;i++){
        int target;
        cin >> target;
        int answer = 0;
        int temp = target;
        
        while(temp != 0){
            if(m.find(temp) != m.end()){
                answer = temp;
            }
            temp = temp / 2;
        }
        
       m[target] = 1;
       cout << answer << '\n';
    }
}