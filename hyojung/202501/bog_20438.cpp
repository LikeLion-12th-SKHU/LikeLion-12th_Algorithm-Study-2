#include <iostream>
#include <map>
using namespace std;
int arr[5001];
int dp[5001];

int main(void){
    //3번부터 N+2까지의 입장번호
    //출석코드 -> 입장번호의 배수들에게 출석코드를 보냄
    //K명 -> 출석코드 제출 X
    cin.tie(NULL);
    map<int,int> not_sleep_list;
    map<int,int> sleep_list;
    
    map<int,int>::iterator iter;
    int n,q,k,m;
    cin >> n >> k >> q >> m;
    for(int i = 0;i<k;i++){
        int x;
        cin >> x;
        not_sleep_list[x] = x;
    }
    
    for(int i = 0;i<q;i++){
        int x;
        cin >> x;
        if(not_sleep_list.find(x) == not_sleep_list.end()){
           sleep_list[x] = x;
        }
    }
    
    for(int i = 3;i<=n+2;i++){
        
        bool is_divided = false;
        for(iter = sleep_list.begin();iter != sleep_list.end();iter++){
            int nextTarget = iter->first;
            if(is_divided){
                break;
            }
            if(i >= nextTarget && i % nextTarget == 0){
                is_divided = true;
            }
        }
        if(is_divided == true){
            arr[i] = 0;
        }
        if(not_sleep_list.find(i) != not_sleep_list.end() || is_divided == false){
            arr[i] = 1;
        }
    }
    
    for(int i = 3;i<=n+2;i++){
        if(i == 3){
            dp[i] = arr[i];
        }
        else{
            dp[i] = dp[i-1] + arr[i];
        }
    }
    
    for(int i = 0;i<m;i++){
        int start,end;
        cin >> start >> end;
        cout << (dp[end] - dp[start] + arr[start])<< '\n';
    }
       
    
    
}