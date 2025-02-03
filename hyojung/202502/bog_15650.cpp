#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> arr;
int main(void){
    cin >> n >> m;
    //m의 개수만큼 0을 넣어줌
    for(int i = 0;i<m;i++){
        arr.push_back(0);
    }
    
    for(int i = 0;i<n-m;i++){
        arr.push_back(1);
    }
    
    do{
        for(int i = 0;i<n;i++){
            if(arr[i] == 0){
                cout << i+1 << ' ';
            }
        }
        cout << '\n';
        
        
    }while(next_permutation(arr.begin(),arr.end()));
}

